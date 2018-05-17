/*
 * 功能说明：
 *     1.emitter_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "uclib/str.h"
#include "uclib/map.h"
#include "uclib/event.h"

#ifndef EMITTER_H
#define EMITTER_H

BEGIN_C_DECLS

/**
 * @class emitter_t
 * 事件发射器。相当于观察者模式中被观察的对象，提供事件注册、注销和分发功能。
 */
typedef struct _emitter_t {
  map_t* listeners;
} emitter_t;

typedef bool_t (*on_event_t)(void* ctx, event_t* event);

/**
 * @method emitter_create
 * 创建事件发射器。
 *
 * @return {emitter_t*} 事件发射器对象。
 */
emitter_t* emitter_create();

/**
 * @method emitter_on
 * 注册指定的事件处理函数，事件发生后调用指定的回调函数。
 * @param {emitter_t*}  emitter 事件发射器对象。
 * @param {const char*} name 事件名。
 * @param {on_event_t*} on_event 回调函数指针。
 * @param {void*}       ctx 回调函数的上下文。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t emitter_on(emitter_t* emitter, const char* name, on_event_t on_event, void* ctx);

/**
 * @method emitter_off
 * 注销指定的事件处理函数。
 * @param {emitter_t*}  emitter 事件发射器对象。
 * @param {const char*} name 事件名。
 * @param {on_event_t*} on_event 回调函数指针。
 * @param {void*}       ctx 回调函数的上下文。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t emitter_off(emitter_t* emitter, const char* name, on_event_t on_event, void* ctx);

/**
 * @method emitter_emit
 * 分发事件。
 * @param {emitter_t*} emitter 事件发射器对象。
 * @param {event_t*}   event   事件。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t emitter_emit(emitter_t* emitter, event_t* event);

/**
 * @method emitter_destroy
 * 销毁事件发射器对象。
 * @param {emitter_t*} emitter 事件发射器对象。
 *
 * @return {void} 无。
 */
void emitter_destroy(emitter_t* emitter);

END_C_DECLS

#endif /*EMITTER_H*/
