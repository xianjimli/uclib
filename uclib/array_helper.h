/* 
 * 功能说明：
 *     1.array_t类的helper函数。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
 
#include "uclib/str.h"
#include "uclib/obj.h"
#include "uclib/array.h"

#ifndef DARRAY_HELPER_H
#define DARRAY_HELPER_H

BEGIN_C_DECLS

static INLINE bool_t array_append_str(array_t* thiz, str_t* str) {
    value_t v;
    return_value_if_fail(thiz != NULL && str != NULL, FALSE);
    value_set_str(&v, str);

    return array_append(thiz, v);
}

static INLINE str_t* array_get_str(array_t* thiz, size_t index) {
    value_t v = array_get(thiz, index); 
    return_value_if_fail(!value_is_null(v), NULL);

    str_t* str = value_str(v);

    return str;
}

static INLINE bool_t array_append_obj(array_t* thiz, obj_t* obj) {
    value_t v;
    return_value_if_fail(thiz != NULL && obj != NULL, FALSE);
    value_set_obj(&v, obj);

    return array_append(thiz, v);
}

static INLINE obj_t* array_get_obj(array_t* thiz, size_t index) {
    value_t v = array_get(thiz, index); 
    return_value_if_fail(!value_is_null(v), NULL);

    return value_obj(v);
}

static INLINE bool_t array_append_int32(array_t* thiz, int32_t iv) {
    value_t v;
    return_value_if_fail(thiz != NULL, FALSE);
    value_set_int32(&v, iv);

    return array_append(thiz, v);
}

static INLINE int32_t array_get_int32(array_t* thiz, size_t index) {
    value_t v = array_get(thiz, index); 
    return_value_if_fail(!value_is_null(v), 0);

    return value_int32(v);
}

END_C_DECLS

#endif/*DARRAY_HELPER_H*/

