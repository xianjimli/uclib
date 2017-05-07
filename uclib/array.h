#include "uclib/value.h"

#ifndef DARRAY_H
#define DARRAY_H

BEGIN_C_DECLS

typedef struct _array_t {
	value_t* data;
	uint32_t size;
	uint32_t capacity;
	bool_t deep_copy;
}array_t;

array_t* array_create(bool_t deep_copy);

uint32_t  array_size(array_t* array);
value_t*  array_get(array_t* array, uint32_t index);
bool_t    array_set(array_t* array, uint32_t index, value_t data);

bool_t    array_delete(array_t* array, uint32_t index);
bool_t    array_delete_pointer(array_t* array, uint32_t index, destroy_t destroy);
bool_t    array_insert(array_t* array, uint32_t index, value_t data);

bool_t    array_prepend(array_t* array, value_t data);
bool_t    array_append(array_t* array, value_t data);

int       array_find(array_t* array, compare_t cmp, void* ctx);
bool_t    array_foreach(array_t* array, visit_t visit, void* ctx);

bool_t    array_clear(array_t* array);

void array_destroy(array_t* array);

END_C_DECLS

#endif/*DARRAY_H*/

