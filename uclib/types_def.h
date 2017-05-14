/** 
 * 功能说明：
 *     1.基本类型定义。
 *
 * 修改历史：
 *     1.2017-4-30 李先静<xianjimli@hotmail.com> 创建。
 */

#ifndef TYPES_DEF_H
#define TYPES_DEF_H 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#if defined(WIN32) || defined(DEVICE_BUILD)
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
#else
#ifndef _INT8_T_DECLARED
typedef __int8_t int8_t;
#define _INT8_T_DECLARED
#endif
#ifndef _UINT8_T_DECLARED
typedef __uint8_t uint8_t;
#define _UINT8_T_DECLARED
#endif

#ifndef _INT16_T_DECLARED
typedef __int16_t int16_t;
#define _INT16_T_DECLARED
#endif
#ifndef _UINT16_T_DECLARED
typedef __uint16_t uint16_t;
#define _UINT16_T_DECLARED
#endif

#ifndef _INT32_T_DECLARED
typedef __int32_t int32_t;
#define _INT32_T_DECLARED
#endif
#ifndef _UINT32_T_DECLARED
typedef __uint32_t uint32_t;
#define _UINT32_T_DECLARED
#endif
#endif/*WIN32*/

#ifdef WIN32 
#   include <direct.h>
#   include <Windows.h>
#   define socket_t SOCKET
#   define DIRECTORY_SEPARATOR "\\"
#   define DIRECTORY_SEPARATOR_CHAR '\\'
#   define getcwd    _getcwd
#   define unlink    _unlink
#   define snprintf  _snprintf
#   define mkdir     _mkdir
#else
#   define socket_t int
#   include <unistd.h>
#   include <sys/time.h>
#   define DIRECTORY_SEPARATOR "/"
#   define DIRECTORY_SEPARATOR_CHAR '/'
#endif/*WIN32*/

#ifndef MAX_PATH
#define MAX_PATH 256
#endif/*MAX_PATH*/

#ifdef __cplusplus
#   define BEGIN_C_DECLS extern "C" {
#   define END_C_DECLS }
#else
#   define BEGIN_C_DECLS
#   define END_C_DECLS
#endif

#ifndef TRUE
#   define bool_t int
#   define TRUE   1
#   define FALSE  0
#endif

#ifdef NDEBUG
#   define ENSURE(p) p
#   define return_if_fail(p) if(!(p)) {return;}
#   define break_if_fail(p) if(!(p)) {break;}
#   define return_value_if_fail(p, value) if(!(p)) {return (value);}
#else
#   define ENSURE(p) assert(p)
#   define break_if_fail(p) if(!(p)) \
    {printf("%s:%d "#p"\n", __FUNCTION__, __LINE__); break;}
#   define return_if_fail(p) if(!(p)) \
    {printf("%s:%d "#p"\n", __FUNCTION__, __LINE__); return;}
#   define return_value_if_fail(p, value) if(!(p)) \
    {printf("%s:%d "#p"\n", __FUNCTION__, __LINE__);return (value);}
#endif

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

typedef int (*compare_t)(const void* a, const void* b);
typedef void (*destroy_t)(void* data);
typedef bool_t (*visit_t)(void* ctx, void* data);

typedef struct _pointer_t {
    void* data;
    destroy_t destroy;
}pointer_t;

#endif/*TYPES_DEF_H*/
