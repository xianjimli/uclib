/*
 * 功能说明：
 *     1.value_t类的实现。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "str.h"
#include "obj.h"
#include "value.h"

value_t* value_set_int8(value_t* v, int8_t value) {
  return_value_if_fail(v != NULL, NULL);
  v->type = VALUE_TYPE_INT8;
  v->value.i8 = value;

  return v;
}

int8_t value_int8(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_INT8, 0);

  return v.value.i8;
}

value_t* value_set_uint8(value_t* v, uint8_t value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_UINT8;
  v->value.u8 = value;

  return v;
}

uint8_t value_uint8(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_UINT8, 0);

  return v.value.u8;
}

value_t* value_set_int16(value_t* v, int16_t value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_INT16;
  v->value.i16 = value;

  return v;
}

int16_t value_int16(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_INT16, 0);

  return v.value.i16;
}

value_t* value_set_uint16(value_t* v, uint16_t value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_UINT16;
  v->value.u16 = value;

  return v;
}

uint16_t value_uint16(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_UINT16, 0);

  return v.value.u16;
}

value_t* value_set_int32(value_t* v, int32_t value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_INT32;
  v->value.i32 = value;

  return v;
}

int32_t value_int32(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_INT32, 0);

  return v.value.i32;
}

value_t* value_set_uint32(value_t* v, uint32_t value) {
  return_value_if_fail(v != NULL, NULL);
  v->type = VALUE_TYPE_UINT32;
  v->value.u32 = value;

  return v;
}

uint32_t value_uint32(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_UINT32, 0);

  return v.value.u32;
}

value_t* value_set_int64(value_t* v, int64_t value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_INT64;
  v->value.i64 = value;

  return v;
}

int64_t value_int64(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_INT64, 0);

  return v.value.i64;
}

value_t* value_set_uint64(value_t* v, uint64_t value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_UINT64;
  v->value.u64 = value;

  return v;
}

uint64_t value_uint64(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_UINT64, 0);

  return v.value.u64;
}

value_t* value_set_pointer(value_t* v, void* value, destroy_t destroy) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_POINTER;
  v->value.ptr.data = value;
  v->value.ptr.destroy = destroy;

  return v;
}

void* value_pointer(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_POINTER, NULL);

  return v.value.ptr.data;
}

value_t* value_set_float(value_t* v, float value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_FLOAT32;
  v->value.f32 = value;

  return v;
}

float value_float(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_FLOAT32, 0.0);

  return v.value.f32;
}

value_t* value_set_double(value_t* v, double value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_FLOAT64;
  v->value.f64 = value;

  return v;
}

double value_double(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_FLOAT64, 0);

  return v.value.f64;
}

value_t* value_set_obj(value_t* v, obj_t* value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_OBJECT;
  v->value.obj = value;

  return v;
}

obj_t* value_obj(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_OBJECT, NULL);

  return v.value.obj;
}

value_t* value_set_str(value_t* v, str_t* value) {
  return_value_if_fail(v != NULL, NULL);

  v->type = VALUE_TYPE_STRING;
  v->value.str = value;

  return v;
}

str_t* value_str(value_t v) {
  return_value_if_fail(v.type == VALUE_TYPE_STRING, NULL);

  return v.value.str;
}

void value_copy(value_t* dst, const value_t* src, bool_t deep_copy) {
  return_if_fail(dst != NULL && src != NULL);
  if (dst == src) {
    return;
  }

  if (src->type == VALUE_TYPE_OBJECT) {
    dst->type = VALUE_TYPE_OBJECT;
    dst->value.obj = deep_copy ? obj_dup(src->value.obj) : obj_ref(src->value.obj);
  } else if (src->type == VALUE_TYPE_STRING) {
    dst->type = VALUE_TYPE_STRING;
    dst->value.str = deep_copy ? str_dup(src->value.str) : str_ref(src->value.str);
  } else {
    memcpy(dst, src, sizeof(value_t));
  }
}

value_t* value_ref(value_t* value) {
  return_value_if_fail(value != NULL, NULL);

  if (value->type == VALUE_TYPE_OBJECT) {
    obj_ref(value->value.obj);
  } else if (value->type == VALUE_TYPE_STRING) {
    str_ref(value->value.str);
  }

  return value;
}

value_t* value_unref(value_t* value) {
  return_value_if_fail(value != NULL, NULL);

  if (value->type == VALUE_TYPE_OBJECT) {
    obj_unref(value->value.obj);
    value->value.obj = NULL;
  } else if (value->type == VALUE_TYPE_STRING) {
    str_unref(value->value.str);
    value->value.str = NULL;
  } else if (value->type == VALUE_TYPE_POINTER) {
    if (value->value.ptr.destroy) {
      value->value.ptr.destroy(value->value.ptr.data);
      value->value.ptr.data = NULL;
      value->value.ptr.destroy = NULL;
    }
    value->type = VALUE_TYPE_INVALID;
  }

  return value;
}

const value_t value_null = {VALUE_TYPE_INVALID};

bool_t value_is_null(value_t value) { return value.type == VALUE_TYPE_INVALID; }

int value_to_int(value_t v) {
  return_value_if_fail(v.type != VALUE_TYPE_INVALID, 0);

  switch (v.type) {
    case VALUE_TYPE_INT8: {
      return (int)v.value.i8;
    }
    case VALUE_TYPE_UINT8: {
      return (int)v.value.u8;
    }
    case VALUE_TYPE_INT16: {
      return (int)v.value.i16;
    }
    case VALUE_TYPE_UINT16: {
      return (int)v.value.u16;
    }
    case VALUE_TYPE_INT32: {
      return (int)v.value.i32;
    }
    case VALUE_TYPE_UINT32: {
      return (int)v.value.u32;
    }
    case VALUE_TYPE_INT64: {
      return (int)v.value.i64;
    }
    case VALUE_TYPE_UINT64: {
      return (int)v.value.u64;
    }
    case VALUE_TYPE_FLOAT32: {
      return (int)v.value.f32;
    }
    case VALUE_TYPE_FLOAT64: {
      return (int)v.value.f64;
    }
    case VALUE_TYPE_STRING: {
      return str_to_int(v.value.str);
    }

    default:
      break;
  }

  return 0;
}
