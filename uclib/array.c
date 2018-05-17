/*
 * 功能说明：
 *     1.array_t类的实现。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "array.h"

array_t* array_create() {
  array_t* array = calloc(1, sizeof(array_t));
  return_value_if_fail(array != NULL, NULL);

  return array;
}

#define MIN_PRE_ALLOCATE_NR 10

static bool_t array_expand(array_t* array, uint32_t need) {
  return_value_if_fail(array != NULL, FALSE);

  if ((array->size + need) > array->capacity) {
    uint32_t capacity = array->capacity + (array->capacity >> 1) + MIN_PRE_ALLOCATE_NR;

    value_t* data = (value_t*)realloc(array->data, sizeof(value_t) * capacity);
    if (data != NULL) {
      array->data = data;
      array->capacity = capacity;
    }
  }

  return ((array->size + need) <= array->capacity) ? TRUE : FALSE;
}

bool_t array_insert(array_t* array, uint32_t index, value_t data) {
  bool_t ret = FALSE;
  uint32_t cursor = index;
  return_value_if_fail(array != NULL, FALSE);

  cursor = cursor < array->size ? cursor : array->size;

  if (array_expand(array, 1) == TRUE) {
    uint32_t i = 0;
    for (i = array->size; i > cursor; i--) {
      array->data[i] = array->data[i - 1];
    }

    array->size++;
    array_set(array, cursor, data);

    ret = TRUE;
  }

  return ret;
}

bool_t array_prepend(array_t* array, value_t data) { return array_insert(array, 0, data); }

bool_t array_append(array_t* array, value_t data) { return array_insert(array, -1, data); }

bool_t array_delete(array_t* array, uint32_t index) {
  uint32_t i = 0;
  return_value_if_fail(array != NULL && array->size > index, FALSE);

  value_unref(array->data + index);
  for (i = index; (i + 1) < array->size; i++) {
    array->data[i] = array->data[i + 1];
  }
  array->size--;

  return TRUE;
}

value_t array_get(array_t* array, uint32_t index) {
  return_value_if_fail(array != NULL && index < array->size, value_null);

  return array->data[index];
}

bool_t array_set(array_t* array, uint32_t index, value_t data) {
  return_value_if_fail(array != NULL && index < array->size, FALSE);

  value_copy(array->data + index, &data, FALSE);

  return TRUE;
}

bool_t array_foreach(array_t* array, visit_t visit, void* ctx) {
  uint32_t i = 0;
  uint32_t n = 0;
  value_t* p = NULL;
  return_value_if_fail(array != NULL && visit != NULL, FALSE);

  for (i = 0, n = array->size, p = array->data; i < n; i++, p++) {
    if (visit(ctx, p)) {
      return TRUE;
    }
  }

  return FALSE;
}

int array_find(array_t* array, compare_t cmp, void* ctx) {
  uint32_t i = 0;
  uint32_t n = 0;
  value_t* p = NULL;
  return_value_if_fail(array != NULL && cmp != NULL, -1);

  for (i = 0, n = array->size, p = array->data; i < n; i++, p++) {
    if (cmp(ctx, p) == 0) {
      return i;
    }
  }

  return -1;
}

bool_t array_clear(array_t* array) {
  uint32_t i = 0;
  uint32_t n = 0;
  value_t* p = NULL;
  return_value_if_fail(array != NULL, FALSE);

  for (i = 0, n = array->size, p = array->data; i < n; i++, p++) {
    value_unref(p);
  }
  array->size = 0;

  return TRUE;
}

void array_destroy(array_t* array) {
  if (array != NULL) {
    array_clear(array);
    free(array->data);
    array->data = NULL;
    free(array);
  }

  return;
}

uint32_t array_size(array_t* array) {
  return_value_if_fail(array != NULL, 0);

  return array->size;
}
