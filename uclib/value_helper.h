/* 
 * 功能说明：
 *     1.value_t helper函数。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "uclib/value.h"

#ifndef VALUE_HELPER_H
#define VALUE_HELPER_H 

BEGIN_C_DECLS

static inline value_t value_from_int8(int8_t v) {
    value_t vv;
    value_set_int8(&vv, v);

    return vv;
}

static inline value_t value_from_uint8(uint8_t v) {
    value_t vv;
    value_set_uint8(&vv, v);

    return vv;
}


static inline value_t value_from_int16(int16_t v) {
    value_t vv;
    value_set_int16(&vv, v);

    return vv;
}

static inline value_t value_from_uint16(uint16_t v) {
    value_t vv;
    value_set_uint16(&vv, v);

    return vv;
}


static inline value_t value_from_int32(int32_t v) {
    value_t vv;
    value_set_int32(&vv, v);

    return vv;
}

static inline value_t value_from_uint32(uint32_t v) {
    value_t vv;
    value_set_uint32(&vv, v);

    return vv;
}

static inline value_t value_from_int64(int64_t v) {
    value_t vv;
    value_set_int64(&vv, v);

    return vv;
}

static inline value_t value_from_uint64(uint64_t v) {
    value_t vv;
    value_set_uint64(&vv, v);

    return vv;
}
static inline value_t value_from_float(float v) {
    value_t vv;
    value_set_float(&vv, v);

    return vv;
}

static inline value_t value_from_double(double v) {
    value_t vv;
    value_set_double(&vv, v);

    return vv;
}


static inline value_t value_from_str(struct _str_t* v) {
    value_t vv;
    value_set_str(&vv, v);

    return vv;
}

static inline value_t value_from_pointer(void* pointer, destroy_t destroy) {
    value_t vv;
    value_set_pointer(&vv, pointer, destroy);

    return vv;
}

END_C_DECLS

#endif/*VALUE_HELPER_H*/

