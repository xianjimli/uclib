/* 
 * 功能说明：
 *     1.array_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
 
#include "uclib/value.h"

#ifndef DARRAY_H
#define DARRAY_H

BEGIN_C_DECLS

/**
 * @class array_t
 * 动态数组，根据数据项的个数自动扩展数组的长度。
 */
typedef struct _array_t {
	value_t* data;
	uint32_t size;
    
	uint32_t capacity;
}array_t;

/**
 * @method array_create
 * 创建动态数组。
 *
 * @return {array_t*} 数组对象。
 */
array_t* array_create();

/**
 * @method array_size
 * 获取数组中元素的个数。
 * @param {array_t*} array 数组对象。
 *
 * @return {uint32_t} 元素的个数。
 */
uint32_t  array_size(array_t* array);

/**
 * @method array_get
 * 获取数组中指定索引的元素。
 * @param {array_t*} array 数组对象。
 * @param {uint32_t} index 索引。
 *
 * @return {value_t} 元素。
 */
value_t   array_get(array_t* array, uint32_t index);

/**
 * @method array_set
 * 设置数组中指定索引的元素。
 * @param {array_t*} array 数组对象。
 * @param {uint32_t} index 索引。
 * @param {value_t}  data  元素的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t    array_set(array_t* array, uint32_t index, value_t data);

/**
 * @method array_delete
 * 删除数组中指定索引的元素。
 * @param {array_t*} array 数组对象。
 * @param {uint32_t} index 索引。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t    array_delete(array_t* array, uint32_t index);

/**
 * @method array_insert
 * 在数组中指定索引的位置插入元素。
 * @param {array_t*} array 数组对象。
 * @param {uint32_t} index 索引。
 * @param {value_t}  data  元素的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t    array_insert(array_t* array, uint32_t index, value_t data);

/**
 * @method array_prepend
 * 在数组中前面插入元素。
 * @param {array_t*} array 数组对象。
 * @param {value_t}  data  元素的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t    array_prepend(array_t* array, value_t data);

/**
 * @method array_append
 * 在数组中后面插入元素。
 * @param {array_t*} array 数组对象。
 * @param {value_t}  data  元素的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t    array_append(array_t* array, value_t data);

/**
 * @method array_find
 * 在数组中查找指定的元素。
 * @param {array_t*}   array 数组对象。
 * @param {compare_t}  cmp   比较函数。
 * @param {void*}      ctx   比较函数的上下文。
 *
 * @return {int} 成功返回元素的索引，失败返回-1。
 */
int       array_find(array_t* array, compare_t cmp, void* ctx);

/**
 * @method array_foreach
 * 遍历数组中的元素。
 * @param {array_t*}   array 数组对象。
 * @param {visit_t}    visit 遍历函数。
 * @param {void*}      ctx   遍历函数的上下文。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t    array_foreach(array_t* array, visit_t visit, void* ctx);

/**
 * @method array_foreach
 * 清除数组中的元素。
 * @param {array_t*}   array 数组对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t    array_clear(array_t* array);

/**
 * @method array_destroy
 * 销毁数组。
 * @param {array_t*}   array 数组对象。
 *
 * @return {void} 无。
 */
void array_destroy(array_t* array);

END_C_DECLS

#endif/*DARRAY_H*/

