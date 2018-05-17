/*
 * 功能说明：
 *     1.map_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "uclib/str.h"
#include "uclib/array.h"

#ifndef MAP_H
#define MAP_H

BEGIN_C_DECLS

/**
 * @class map_t
 * 存放key/value映射的容器，方便通过key查找value。
 */
struct _map_t;
typedef struct _map_t map_t;

typedef struct _key_value_t {
  str_t* key;
  value_t value;
} key_value_t;

/**
 * @method map_create
 * 创建map。
 *
 * @return {map_t*} map对象。
 */
map_t* map_create();

/**
 * @method map_size
 * 获取map中元素的个数。
 * @param {map_t*} map map对象。
 *
 * @return {uint32_t} 元素的个数。
 */
uint32_t map_size(map_t* map);

/**
 * @method map_get
 * 获取指定key的value。
 * @param {map_t*}      map map对象。
 * @param {const char*} key 键名。
 *
 * @return {value_t} 值。
 */
value_t map_get(map_t* map, const char* key);

/**
 * @method map_set
 * 设置指定key的value。
 * @param {map_t*}      map map对象。
 * @param {const char*} key 键名。
 * @param {value_t}     value 值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t map_set(map_t* map, const char* key, value_t data);

/**
 * @method map_delete
 * 删除指定key。
 * @param {map_t*}      map map对象。
 * @param {const char*} key 键名。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t map_delete(map_t* map, const char* key);

/**
 * @method map_foreach
 * 遍历所有的key/value。
 * @param {map_t*}     map   map对象。
 * @param {visit_t}    visit 遍历函数。
 * @param {void*}      ctx   遍历函数的上下文。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t map_foreach(map_t* map, visit_t visit, void* ctx);

/**
 * @method map_clear
 * 清除所有元素。
 * @param {map_t*}     map   map对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t map_clear(map_t* map);

/**
 * @method map_destroy
 * 销毁map对象。
 * @param {map_t*}     map   map对象。
 *
 * @return {void} 无。
 */
void map_destroy(map_t* map);

END_C_DECLS

#endif /*MAP_H*/
