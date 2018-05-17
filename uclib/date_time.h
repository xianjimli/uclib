/*
 * 功能说明：
 *     1.时间相关的函数。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "uclib/types_def.h"

#ifndef DATE_TIME_H
#define DATE_TIME_H

BEGIN_C_DECLS

/**
 * @method time_now
 * 获取当天时间相对于0点的毫秒数。
 *
 * @return {size_t} 当天时间相对于0点的毫秒数。
 */
size_t time_now();

/**
 * @method msleep
 * 睡眠指定的毫秒数。
 * @param {uint32_t} ms 毫秒数。
 *
 * @return {void} 无。
 */
void msleep(uint32_t ms);

END_C_DECLS

#endif /*DATE_TIME_H*/
