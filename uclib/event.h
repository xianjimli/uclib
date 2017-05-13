/* 
 * 功能说明：
 *     1.emitter_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "uclib/str.h"
#include "uclib/map.h"

#ifndef EVENT_H
#define EVENT_H 

BEGIN_C_DECLS

/**
 * @class event_t 
 * 事件。
 */
typedef struct _event_t {
    uint32_t ref;
    /**
     * @property {str_t*} type
     * 事件类型。
     */
    str_t* type;
    map_t* params;
}event_t;

/**
 * @method event_create
 * 创建事件对象。
 *
 * @return {event_t*} 事件对象。
 */
event_t* event_create(const char* type);

/**
 * @method event_set_type
 * 设置事件的类型。
 * @param {event_t*}    event 事件对象。
 * @param {const char*} type 事件类型。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t   event_set_type(event_t* event, const char* type);

/**
 * @method event_set_param
 * 设置事件的参数。
 * @param {event_t*}    event 事件对象。
 * @param {const char*} name  参数的名称。
 * @param {const char*} value 参数的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t   event_set_param(event_t* event, const char* name, const char* value);

/**
 * @method event_get_param
 * 获取事件的参数。
 * @param {event_t*}    event 事件对象。
 * @param {const char*} name  参数的名称。
 *
 * @return {const char*} 参数的值。
 */
const char* event_get_param(event_t* event, const char* name);

/**
 * @method event_ref
 * 增加引用计数。
 * @param {event_t*} event 事件对象。
 *
 * @return {event_t*} 事件对象本身。
 */
event_t* event_ref(event_t* event);

/**
 * @method event_unref
 * 减少引用计数。
 * @param {event_t*} event 事件对象。
 *
 * @return {event_t*} 引用计数仍然大于0返回event对象本身，否则返回NULL。
 */
event_t* event_unref(event_t* event);

void event_dump(event_t* event, str_t* str);

END_C_DECLS

#endif

