/*
 * 功能说明：
 *     1.mutex_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "uclib/types_def.h"

#ifndef MUTEX_H
#define MUTEX_H

BEGIN_C_DECLS

/**
 * @class mutex_t
 * 互斥锁。
 */
struct _mutex_t;
typedef struct _mutex_t mutex_t;

/**
 * @method mutex_create
 * 创建mutex。
 *
 * @return {mutex_t*} mutex对象。
 */
mutex_t* mutex_create();

/**
 * @method mutex_lock
 * 加锁。
 * @param {mutex_t*}    mutex mutex对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t mutex_lock(mutex_t* mutex);

/**
 * @method mutex_unlock
 * 解锁。
 * @param {mutex_t*}    mutex mutex对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t mutex_unlock(mutex_t* mutex);

/**
 * @method mutex_destroy
 * 销毁mutex对象。
 * @param {mutex_t*}    mutex mutex对象。
 *
 * @return {void} 无。
 */
void mutex_destroy(mutex_t* mutex);

END_C_DECLS

#endif /*MUTEX_H*/
