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
}value_type_t;

/*value_t代表一个通用的数据类型，可以保存任何数据格式的数据。*/
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
		double f65;

		pointer_t ptr;
		struct _str_t* str;
		struct _obj_t* obj;
	}value;
}value_t;

/**
 * \brief 初始化value_t为一个8位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_int8(value_t* gv, int8_t value);

/**
 * \brief 获取8位有符号数。调用者需要保证value_t的类型是8位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
int8_t value_int8(value_t* gv);

/**
 * \brief 初始化value_t为一个8位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_uint8(value_t* gv, uint8_t value);

/**
 * \brief 获取8位无符号数。调用者需要保证value_t的类型是8位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
uint8_t value_uint8(value_t* gv);

/**
 * \brief 初始化value_t为一个16位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_int16(value_t* gv, int16_t value) ;

/**
 * \brief 获取16位有符号数。调用者需要保证value_t的类型是16位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
int16_t value_int16(value_t* gv);

/**
 * \brief 初始化value_t为一个16位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_uint16(value_t* gv, uint16_t value);

/**
 * \brief 获取16位无符号数。调用者需要保证value_t的类型是16位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
uint16_t value_uint16(value_t* gv);

/**
 * \brief 初始化value_t为一个32位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_int32(value_t* gv, int32_t value);

/**
 * \brief 获取32位有符号数。调用者需要保证value_t的类型是32位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
int32_t value_int32(value_t* gv);

/**
 * \brief 初始化value_t为一个32位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_uint32(value_t* gv, uint32_t value);

/**
 * \brief 获取32位无符号数。调用者需要保证value_t的类型是32位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
uint32_t value_uint32(value_t* gv);

/**
 * \brief 初始化value_t为一个64位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_int64(value_t* gv, int64_t value);

/**
 * \brief 获取64位有符号数。调用者需要保证value_t的类型是64位有符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
int64_t value_int64(value_t* gv);

/**
 * \brief 初始化value_t为一个64位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_uint64(value_t* gv, uint64_t value);

/**
 * \brief 获取64位无符号数。调用者需要保证value_t的类型是64位无符号数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
uint64_t value_uint64(value_t* gv);

/**
 * \brief 初始化value_t为一个指针。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_pointer(value_t* gv, void* value, destroy_t destroy);

/**
 * \brief 获取指针。调用者需要保证value_t的类型是指针。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
void* value_pointer(value_t* gv);

/**
 * \brief 初始化value_t为一个单精度浮点数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_float(value_t* gv, float value);

/**
 * \brief 获取单精度浮点数。调用者需要保证value_t的类型是单精度浮点数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
float value_float(value_t* gv);

/**
 * \brief 初始化value_t为一个双精度浮点数。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_double(value_t* gv, double value);

/**
 * \brief 获取双精度浮点数。调用者需要保证value_t的类型是双精度浮点数。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
double value_double(value_t* gv);

/**
 * \brief 初始化value_t为一个对象。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_obj(value_t* gv, struct _obj_t* value);

/**
 * \brief 获取对象。调用者需要保证value_t的类型是对象。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
struct _obj_t* value_obj(value_t* gv);

/**
 * \brief 初始化value_t为一个对象。
 *
 * \param[in] gv            ： value_t对象
 * \param[in] value         ： 初始化的值。
 * 
 * \retval value_t对象本身
 */
value_t* value_set_str(value_t* gv, struct _str_t* value);

/**
 * \brief 获取对象。调用者需要保证value_t的类型是对象。
 *
 * \param[in] gv            ： value_t对象
 * 
 * \retval value_t对象的值。
 */
struct _str_t* value_str(value_t* gv);


/**
 * \brief 拷贝一个value_t对象到另外一个value_t对象。
 *
 * \param[in] dst            ： 目的value_t对象
 * \param[in] src            ： 源value_t对象
 * 
 * \retval value_t对象的值。
 */
void value_copy(value_t* dst, const value_t* src, bool_t deep_copy);

value_t* value_ref(value_t* value);

value_t* value_unref(value_t* value);

END_C_DECLS

#endif
