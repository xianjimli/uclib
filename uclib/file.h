/* 
 * 功能说明：
 *     1.文件类工具函数。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "uclib/str.h"

#ifndef FILE_H
#define FILE_H

BEGIN_C_DECLS

/**
 * @method dir_exist
 * 判断目录是否存在。
 * @param {const char*} path 目录名。
 *
 * @return {bool_t} 存在返回TRUE，不存在返回FALSE。
 */
bool_t dir_exist(const char* path);

/**
 * @method file_delete
 * 删除文件。
 * @param {const char*} filename 文件名。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t file_delete(const char* filename);

/**
 * @method file_get_size
 * 删除文件。
 * @param {const char*} filename 文件名。
 *
 * @return {size_t} 成功返回大小，失败返回0。
 */
size_t file_get_size(const char* filename);

/**
 * @method file_exist
 * 判断文件是否存在。
 * @param {const char*} filename 文件名。
 *
 * @return {bool_t} 存在返回TRUE，不存在返回FALSE。
 */
bool_t file_exist(const char* filename);

/**
 * @method file_read_text
 * 读取文件内容。
 * @param {const char*} filename 文件名。
 * @param {str_t*}      content  文件内容。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t file_read_text(const char* filename, str_t* content);

/**
 * @method file_write_text
 * 写入文件内容。
 * @param {const char*} filename 文件名。
 * @param {str_t*}      content  文件内容。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t file_write_text(const char* filename, const char* content);

END_C_DECLS

#endif/*FILE_H*/
