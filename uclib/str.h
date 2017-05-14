/* 
 * 功能说明：
 *     1.str_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "uclib/types_def.h"

#ifndef STR_H
#define STR_H

BEGIN_C_DECLS

/**
 * @class str_t 
 * 字符串对象。
 */
typedef struct _str_t{
   uint16_t ref;
    /**
     * @property {uint32_t} size
     * 字符串的长度。
     */
   uint32_t size;
   uint32_t capacity;
    /**
     * @property {char*} str
     * 字符串的内容。
     */
   char* str;
}str_t;

/**
 * @method str_create
 * 创建str对象。
 *
 * @return {str_t*} str对象。
 */
str_t* str_create(const char* str, uint32_t size, uint32_t capacity);

/**
 * @method str_sub
 * 截取一个子字符串。
 * @param {str_t*}     s        字符串对象。
 * @param {uint32_t}   start    偏移量 
 * @param {uint32_t}   size     子串长度。
 *
 * @return {str_t*} 成功返回子字符串对象，失败返回NULL。
 */
str_t* str_sub(str_t* s, uint32_t start, uint32_t size);

/**
 * @method str_extend
 * 扩展字符串的容量。
 * @param {str_t*}     s        字符串对象。
 * @param {uint32_t}   capacity 新的容量。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_extend(str_t* s, uint32_t capacity);

/**
 * @method str_copy
 * 拷贝字符串。
 * @param {str_t*}     s        字符串对象。
 * @param {str_t*}     other    源字符串对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_copy(str_t* s, str_t* other);

/**
 * @method str_dup
 * 复制一个新的字符串。
 * @param {str_t*}     s        字符串对象。
 *
 * @return {str_t*} 成功返回新字符串对象，失败返回NULL。
 */
str_t* str_dup(str_t* s);

/**
 * @method str_start_with
 * 判断字符串是否以指定的字符串开头。
 * @param {str_t*}     s        字符串对象。
 * @param {str_t*}     str      指定的字符串。
 *
 * @return {bool_t} 是返回TRUE，否返回FALSE。
 */
bool_t str_start_with(str_t* s, const char* str);

/**
 * @method str_end_with
 * 判断字符串是否以指定的字符串结束。
 * @param {str_t*}     s        字符串对象。
 * @param {str_t*}     str      指定的字符串。
 *
 * @return {bool_t} 是返回TRUE，否返回FALSE。
 */
bool_t str_end_with(str_t* s, const char* str);

/**
 * @method str_cmp
 * 比较字符串的大小。
 * @param {str_t*}     s        字符串对象。
 * @param {str_t*}     str      字符串。
 *
 * @return {int} 小于返回负数，等于返回0，大于返回正数。
 */
int    str_cmp(str_t* s, const char* str);

/**
 * @method str_ncmp
 * 取前面指定长度的子串，比较字符串的大小。
 * @param {str_t*}      s        字符串对象。
 * @param {str_t*}      str      字符串。
 * @param {uint32_t*}   size     长度。
 *
 * @return {int} 小于返回负数，等于返回0，大于返回正数。
 */
int    str_ncmp(str_t* s, const char* str, uint32_t size);


/**
 * @method str_end_with
 * 判断是否与指定的字符串相等。
 * @param {str_t*}     s        字符串对象。
 * @param {str_t*}     str      指定的字符串。
 *
 * @return {bool_t} 相等返回TRUE，不相等返回FALSE。
 */
bool_t str_equal(str_t* s, const char* str);

/**
 * @method str_index_of_c
 * 定位指定的字符第一次在字符串中出现的位置。
 * @param {str_t*}      s        字符串对象。
 * @param {char}        c        字符。
 *
 * @return {int32_t} 找到返回对应的偏移量，没找到返回-1。
 */
int32_t   str_index_of_c(str_t* s, char c);

/**
 * @method str_index_of_c
 * 定位指定的字符最后一次在字符串中出现的位置。
 * @param {str_t*}      s        字符串对象。
 * @param {char}        c        字符。
 *
 * @return {int32_t} 找到返回对应的偏移量，没找到返回-1。
 */
int32_t   str_last_index_of_c(str_t* s, char c);

/**
 * @method str_index_of
 * 定位指定的字符串第一次在字符串中出现的位置。
 * @param {str_t*}      s        字符串对象。
 * @param {const char*} str      字符串。
 *
 * @return {int32_t} 找到返回对应的偏移量，没找到返回-1。
 */
int32_t   str_index_of(str_t* s, const char* str);

/**
 * @method str_replace_c
 * 把字符串中指定的字符替换另外一个字符。
 * @param {str_t*}     s        字符串对象。
 * @param {char}       c        待替换的字符。
 * @param {char}       new_char 将替换的字符。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_replace_c(str_t* s, char c, char new_char);

/**
 * @method str_replace
 * 把字符串中指定的字符串替换另外一个字符串。
 * @param {str_t*}            s        字符串对象。
 * @param {const char*}       str      待替换的字符串。
 * @param {const char*}       new_str  将替换的字符串。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_replace(str_t* s, const char* str, const char* new_str);

/**
 * @method str_set
 * 把字符串的内容设置成指定的字符串。
 * @param {str_t*}            s        字符串对象。
 * @param {const char*}       str      指定的字符串。
 * @param {uint32_t}          size     截取的长度，如果大于strlen(str)，则使用strlen(str)。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_set(str_t* s, const char* str, uint32_t size);

/**
 * @method str_append_char
 * 向字符串中追加一个字符。
 * @param {str_t*}            s        字符串对象。
 * @param {char}              c        待追加的字符。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_append_char(str_t* s, char c);

/**
 * @method str_append_char
 * 向字符串中追加一个字符串。
 * @param {str_t*}            s        字符串对象。
 * @param {const char* str}   str      待追加的字符串。
 * @param {uint32_t}          size     截取的长度，如果大于strlen(str)，则使用strlen(str)。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_append(str_t* s, const char* str, uint32_t size);

/**
 * @method str_append_f
 * 向字符串中追加一个或多个字符串。XXX: 请先调用str_extend扩展足够的容量。
 * @param {str_t*}            s        字符串对象。
 * @param {const char* str}   format   格式，参考printf。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_append_f(str_t* s, const char* format, ...);

/**
 * @method str_trim_left
 * 移出字符串左边指定的字符。
 * @param {str_t*}            s        字符串对象。
 * @param {const char* str}   str      包含指定字符的字符串。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_trim_left(str_t* s, const char* str);

/**
 * @method str_trim_right
 * 移出字符串右边指定的字符。
 * @param {str_t*}            s        字符串对象。
 * @param {const char* str}   str      包含指定字符的字符串。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_trim_right(str_t* s, const char* str);

/**
 * @method str_trim
 * 移出字符串左边和右边指定的字符。
 * @param {str_t*}            s        字符串对象。
 * @param {const char* str}   str      包含指定字符的字符串。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_trim(str_t* s, const char* str);

/**
 * @method str_to_int
 * 把字符串转换成整数。
 * @param {str_t*}            s        字符串对象。
 *
 * @return {int32_t} 成功返回对应的整数，失败返回0。
 */
int32_t str_to_int(str_t* s);

/**
 * @method str_to_float
 * 把字符串转换成浮点数。
 * @param {str_t*}            s        字符串对象。
 *
 * @return {float} 成功返回对应的浮点数，失败返回0。
 */
float   str_to_float(str_t* s);

/**
 * @method str_to_double
 * 把字符串转换成双精度浮点数。
 * @param {str_t*}            s        字符串对象。
 *
 * @return {float} 成功返回对应的双精度浮点数，失败返回0。
 */
double  str_to_double(str_t* s);

/**
 * @method str_from_int
 * 把整数转换成字符串。
 * @param {str_t*}            s        字符串对象。
 * @param {int32_t}           value    待转换的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_from_int(str_t* s, int32_t value);

/**
 * @method str_from_float
 * 把浮点数转换成字符串。
 * @param {str_t*}            s        字符串对象。
 * @param {float}             value    待转换的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_from_float(str_t* s, float value);

/**
 * @method str_from_double
 * 把双精度浮点数转换成字符串。
 * @param {str_t*}            s        字符串对象。
 * @param {double}            value    待转换的值。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_from_double(str_t* s, double value);

/**
 * @method str_basename
 * 获取文件名中的basename，并设置到字符串中。
 * @param {str_t*}            s                字符串对象。
 * @param {const char*}       filename         带路径的文件名。
 * @param {bool_t}            include_extname  是否包含扩展名。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_basename(str_t* s, const char* filename, bool_t include_extname);

/**
 * @method str_extname
 * 获取文件名中的扩展名，并设置到字符串中。
 * @param {str_t*}            s                字符串对象。
 * @param {const char*}       filename         带路径的文件名。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_extname(str_t* s, const char* filename);

/**
 * @method str_dirname
 * 获取文件名中的目录名，并设置到字符串中。
 * @param {str_t*}            s                字符串对象。
 * @param {const char*}       filename         带路径的文件名。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_dirname(str_t* s, const char* filename);

/**
 * @method str_normalize_path
 * 正规化文件名，把'/'和'\\'换成平台对应的分隔符。
 * 把'.'和'..'替换成实际的值。
 * @param {str_t*}            s                字符串对象。
 * @param {const char*}       filename         带路径的文件名。
 * @param {const char*}       cwd              当前路径。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_normalize_path(str_t* s, const char* filename, const char* cwd);

/**
 * @method str_to_lower
 * 把字符串转换成小写。
 * @param {str_t*}            s        字符串对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_to_lower(str_t* s);

/**
 * @method str_to_upper
 * 把字符串转换成大写。
 * @param {str_t*}            s        字符串对象。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_to_upper(str_t* s);

typedef void (*str_on_token_t)(void* ctx, str_t* token);

/**
 * @method str_tokenizer
 * 把字符串转拆成多个token，没解析出一个token就调用一下on_token。
 * @param {str_t*}            s        字符串对象。
 * @param {str_on_token_t}    on_token 接受token的回调函数。
 * @param {void*}             ctx      回调函数的上下文。
 * @param {const char*}       delim    分隔字符集合，缺省为" "。
 * @param {const char*}       ctokens  单字符的token集合，比如在C语言中'{','}'等字符。
 *
 * @return {bool_t} 成功返回TRUE，失败返回FALSE。
 */
bool_t str_tokenizer(str_t* s, str_on_token_t on_token, void* ctx, 
        const char* delim, const char* ctokens); 

/**
 * @method str_ref
 * 增加引用计数。
 * @param {str_t*} v str对象。
 *
 * @return {str_t*} str对象本身。
 */
str_t* str_ref(str_t* s);

/**
 * @method str_unref
 * 减少引用计数。
 * @param {str_t*} v str对象。
 *
 * @return {str_t*} 引用计数仍然大于0返回str对象本身，否则返回NULL。
 */
str_t* str_unref(str_t* s);

/**
 * 在栈上分配一个临时的字符串对象, 不能扩展它的长度。
 */
str_t* str_init_static(str_t* s, char* str, uint32_t size, uint32_t capacity);

END_C_DECLS

#endif/*STR_H*/

