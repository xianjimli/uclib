/*
 * 功能说明：
 *     1.value_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "uclib/types_def.h"

#ifndef VALUE_H
#define VALUE_H

struct _obj_t;
struct _str_t;

BEGIN_C_DECLS

/*数据类型定义*/
typedef enum _value_type_t {
  VALUE_TYPE_INVALID = 0,
  VALUE_TYPE_INT8,
  VALUE_TYPE_UINT8,
  VALUE_TYPE_INT16,
  VALUE_TYPE_UINT16,
  VALUE_TYPE_INT32,
  VALUE_TYPE_UINT32,
  VALUE_TYPE_INT64,
  VALUE_TYPE_UINT64,
  VALUE_TYPE_POINTER,
  VALUE_TYPE_FLOAT32,
  VALUE_TYPE_FLOAT64,
  VALUE_TYPE_STRING,
  VALUE_TYPE_OBJECT
} value_type_t;

/**
 * @class value_t
 * 一个通用数据类型，用来存放整数、浮点数、obj_t、str_t和其它对象。
 */
typedef struct _value_t {
  uint32_t type;
  union {
    int8_t i8;
    uint8_t u8;
    int16_t i16;
    uint16_t u16;
    int32_t i32;
    uint32_t u32;
    int64_t i64;
    uint64_t u64;
    float f32;
    double f64;

    pointer_t ptr;
    struct _str_t* str;
    struct _obj_t* obj;
  } value;
} value_t;

/**
 * @method value_set_int8
 * 设置类型为int8的值。
 * @param {value_t*} v     value对象。
 * @param {int8_t}   value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_int8(value_t* v, int8_t value);

/**
 * @method value_int8
 * 获取类型为int8的值。
 * @param {value_t} v value对象。
 *
 * @return {int8_t} 值。
 */
int8_t value_int8(value_t v);

/**
 * @method value_set_uint8
 * 设置类型为uint8的值。
 * @param {value_t*} v     value对象。
 * @param {uint8_t}  value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_uint8(value_t* v, uint8_t value);

/**
 * @method value_uint8
 * 获取类型为uint8的值。
 * @param {value_t} v value对象。
 *
 * @return {int8_t} 值。
 */
uint8_t value_uint8(value_t v);

/**
 * @method value_set_int16
 * 设置类型为int16的值。
 * @param {value_t*} v     value对象。
 * @param {int16_t}  value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_int16(value_t* v, int16_t value);

/**
 * @method value_int16
 * 获取类型为int16的值。
 * @param {value_t} v value对象。
 *
 * @return {int16_t} 值。
 */
int16_t value_int16(value_t v);

/**
 * @method value_set_uint16
 * 设置类型为uint16的值。
 * @param {value_t*} v     value对象。
 * @param {uint16_t} value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_uint16(value_t* v, uint16_t value);

/**
 * @method value_uint16
 * 获取类型为uint16的值。
 * @param {value_t} v value对象。
 *
 * @return {uint16_t} 值。
 */
uint16_t value_uint16(value_t v);

/**
 * @method value_set_int32
 * 设置类型为int32的值。
 * @param {value_t*} v     value对象。
 * @param {int32_t}  value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_int32(value_t* v, int32_t value);

/**
 * @method value_int32
 * 获取类型为int32的值。
 * @param {value_t} v value对象。
 *
 * @return {int32_t} 值。
 */
int32_t value_int32(value_t v);

/**
 * @method value_set_uint32
 * 设置类型为uint32的值。
 * @param {value_t*} v     value对象。
 * @param {uint32_t} value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_uint32(value_t* v, uint32_t value);

/**
 * @method value_uint32
 * 获取类型为uint32的值。
 * @param {value_t} v value对象。
 *
 * @return {uint32_t} 值。
 */
uint32_t value_uint32(value_t v);

/**
 * @method value_set_int64
 * 设置类型为int64的值。
 * @param {value_t*} v     value对象。
 * @param {int64_t}  value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_int64(value_t* v, int64_t value);

/**
 * @method value_int64
 * 获取类型为int64的值。
 * @param {value_t} v value对象。
 *
 * @return {int64_t} 值。
 */
int64_t value_int64(value_t v);

/**
 * @method value_set_uint64
 * 设置类型为uint64的值。
 * @param {value_t*} v     value对象。
 * @param {uint64_t} value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_uint64(value_t* v, uint64_t value);

/**
 * @method value_uint64
 * 获取类型为uint64的值。
 * @param {value_t} v value对象。
 *
 * @return {uint64_t} 值。
 */
uint64_t value_uint64(value_t v);

/**
 * @method value_set_pointer
 * 设置类型为pointer的值。
 * @param {value_t*}  v       value对象。
 * @param {void*}     value   待设置的值。
 * @param {destroy_t} destroy 销毁指针的函数指针。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_pointer(value_t* v, void* value, destroy_t destroy);

/**
 * @method value_pointer
 * 获取类型为pointer的值。
 * @param {value_t} v value对象。
 *
 * @return {uint64_t} 值。
 */
void* value_pointer(value_t v);

/**
 * @method value_set_float
 * 设置类型为float的值。
 * @param {value_t*} v     value对象。
 * @param {float}    value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_float(value_t* v, float value);

/**
 * @method value_float
 * 获取类型为float的值。
 * @param {value_t} v value对象。
 *
 * @return {float} 值。
 */
float value_float(value_t v);

/**
 * @method value_set_double
 * 设置类型为double的值。
 * @param {value_t*} v     value对象。
 * @param {double}   value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_double(value_t* v, double value);

/**
 * @method value_double
 * 获取类型为double的值。
 * @param {value_t} v value对象。
 *
 * @return {double} 值。
 */
double value_double(value_t v);

/**
 * @method value_set_obj
 * 设置类型为obj_t的值。
 * @param {value_t*} v     value对象。
 * @param {obj_t*}   value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_obj(value_t* v, struct _obj_t* value);

/**
 * @method value_obj
 * 获取类型为obj_t的值。
 * @param {value_t} v value对象。
 *
 * @return {obj_t*} 值。
 */
struct _obj_t* value_obj(value_t v);

/**
 * @method value_set_str
 * 设置类型为str_t的值。
 * @param {value_t*} v     value对象。
 * @param {str_t*}   value 待设置的值。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_set_str(value_t* v, struct _str_t* value);

/**
 * @method value_str
 * 获取类型为str_t的值。
 * @param {value_t} v value对象。
 *
 * @return {str_t*} 值。
 */
struct _str_t* value_str(value_t v);

/**
 * @method value_copy
 * 拷贝。
 * @param {value_t*} v         value对象。
 * @param {value_t*} src       源value对象。
 * @param {bool_t}   deep_copy 是否深度拷贝。
 *
 * @return {value_t*} value对象本身。
 */
void value_copy(value_t* v, const value_t* src, bool_t deep_copy);

/**
 * @method value_ref
 * 增加引用计数。
 * @param {value_t*} v value对象。
 *
 * @return {value_t*} value对象本身。
 */
value_t* value_ref(value_t* v);

/**
 * @method value_unref
 * 减少引用计数。
 * @param {value_t*} v value对象。
 *
 * @return {value_t*} 引用计数仍然大于0返回value对象本身，否则返回NULL。
 */
value_t* value_unref(value_t* v);

/**
 * @method value_is_null
 * 判断value是否为空值。
 * @param {value_t} value value对象。
 *
 * @return {bool_t} 为空值返回TRUE，否则返回FALSE。
 */
bool_t value_is_null(value_t value);

/**
 * @var {value_null} 空值。
 */
extern const value_t value_null;

/**
 * @method value_to_int
 * 转换为int的值。
 * @param {value_t} v value对象。
 *
 * @return {int} 值。
 */
int value_to_int(value_t v);

END_C_DECLS

#endif
