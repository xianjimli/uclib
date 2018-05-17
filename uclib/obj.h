/*
 * 功能说明：
 *     1.obj_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-7 李先静 创建。
 */

#include "uclib/value.h"
#include "uclib/emitter.h"

#ifndef OBJ_H
#define OBJ_H

BEGIN_C_DECLS

struct _obj_t;
typedef struct _obj_t obj_t;

typedef obj_t* (*obj_dup_t)(obj_t* obj);
typedef bool_t (*obj_destroy_t)(obj_t* obj);
typedef bool_t (*obj_copy_t)(obj_t* obj, obj_t* other);
typedef bool_t (*obj_set_prop_t)(obj_t* obj, const char* prop, value_t value);
typedef value_t (*obj_get_prop_t)(obj_t* obj, const char* prop);

typedef bool_t (*obj_set_t)(obj_t* obj, value_t value);
typedef value_t (*obj_get_t)(obj_t* obj);

/**
 * @class obj_t
 * 通用的对象。提供通用的属性设置/获取函数，和事件注册/分发功能。
 */
struct _obj_t {
  uint16_t ref;
  uint16_t magic;
  emitter_t* emitter;

  /*
   * 下列函数指针需要子类初始化。
   */
  obj_dup_t dup;
  obj_copy_t copy;
  obj_destroy_t destroy;
  obj_set_prop_t set_prop;
  obj_get_prop_t get_prop;
};

/**
 * @method obj_init
 * 初始化obj，在分配对象内存之后，就应该调用本函数。
 *
 * @param {obj_t*}     obj 对象
 * @param {uint16_t}   magic 对象属类的标识。
 *
 * @return {obj_t*} 返回对象本身。
 */
obj_t* obj_init(obj_t* obj, uint16_t magic);

/**
 * @method obj_ref
 * 增加引用计数。
 * @param {obj_t*} obj obj对象。
 *
 * @return {obj_t*} obj对象本身。
 */
obj_t* obj_ref(obj_t* obj);

/**
 * @method obj_unref
 * 减少引用计数。
 * @param {obj_t*} obj obj对象。
 *
 * @return {obj_t*} 引用计数仍然大于0返回obj对象本身，否则返回NULL。
 */
obj_t* obj_unref(obj_t* obj);

/**
 * @method obj_dup
 * 复制对象。
 * @param {obj_t*} obj obj对象。
 *
 * @return {obj_t*} 新的obj对象。
 */
obj_t* obj_dup(obj_t* obj);

/**
 * @method obj_copy
 * 深度拷贝对象。
 * @param {obj_t*} obj   obj对象。
 * @param {obj_t*} other 源obj对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t obj_copy(obj_t* obj, obj_t* other);

/**
 * @method obj_prop
 * 获取对象的属性。
 * @param {obj_t*}      obj   obj对象。
 * @param {const char*} prop  属性名。
 *
 * @return {bool_t} 返回属性值。
 */
value_t obj_prop(obj_t* obj, const char* prop);

/**
 * @method obj_set_prop
 * 获取对象的属性。
 * @param {obj_t*}  obj    obj对象。
 * @param {obj_t*}  prop   属性名。
 * @param {value_t} value  属性值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t obj_set_prop(obj_t* obj, const char* prop, value_t value);

/**
 * @method obj_on
 * 注册指定的事件处理函数，事件发生后调用指定的回调函数。
 * @param {obj_t*}  obj 事件发射器对象。
 * @param {const char*} name 事件名。
 * @param {on_event_t*} on_event 回调函数指针。
 * @param {void*}       ctx 回调函数的上下文。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t obj_on(obj_t* obj, const char* event_name, on_event_t on_event, void* ctx);

/**
 * @method obj_off
 * 注销指定的事件处理函数。
 * @param {obj_t*}  obj 事件发射器对象。
 * @param {const char*} name 事件名。
 * @param {on_event_t*} on_event 回调函数指针。
 * @param {void*}       ctx 回调函数的上下文。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t obj_off(obj_t* obj, const char* event_name, on_event_t on_event, void* ctx);

/**
 * @method obj_emit
 * 分发事件。
 * @param {obj_t*} obj 事件发射器对象。
 * @param {event_t*}   event   事件。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t obj_emit(obj_t* obj, event_t* event);

END_C_DECLS

#endif /*OBJ_H*/
