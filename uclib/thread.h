/* 
 * 功能说明：
 *     1.thread_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "uclib/types_def.h"

#ifndef THREAD_H
#define THREAD_H 

/**
 * @class thread_t 
 * 线程对象。
 */
struct _thread_t;
typedef struct _thread_t thread_t;

typedef void* (*thread_entry_t)(void* args);

BEGIN_C_DECLS

/**
 * @method thread_create
 * 创建thread对象。
 *
 * @return {thread_t*} thread对象。
 */
thread_t* thread_create(thread_entry_t entry, void* args);

/**
 * @method thread_start
 * 启动线程。
 * @param {thread_t*}    thread thread对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t thread_start(thread_t* thread);

/**
 * @method thread_join
 * 等待线程退出。
 * @param {thread_t*}    thread thread对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t thread_join(thread_t* thread);

/**
 * @method thread_destroy
 * 销毁thread对象。
 * @param {thread_t*}    thread thread对象。
 *
 * @return {void} 无。
 */
void thread_destroy(thread_t* thread);

END_C_DECLS

#endif/*THREAD_H*/

