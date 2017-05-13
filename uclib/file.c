
/* 
 * 功能说明：
 *     1.文件类工具函数。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "file.h"
#include <sys/stat.h>

bool_t file_delete(const char* filename) {
    return_value_if_fail(filename != NULL, FALSE);

    return 0 == unlink(filename);
}

size_t file_get_size(const char* filename) {
    struct stat st;
    return_value_if_fail(filename != NULL, 0);

    if(stat(filename, &st) == 0) {
        return st.st_size;
    }

    return 0;
}

bool_t file_exist(const char* filename) {
    struct stat st;
    return_value_if_fail(filename != NULL, 0);

    if(stat(filename, &st) == 0) {
        return (st.st_mode & S_IFREG) != 0;
    }

    return FALSE;
}

bool_t dir_exist(const char* path) {
    struct stat st;
    return_value_if_fail(path != NULL, FALSE);

    if(stat(path, &st) == 0) {
        return (st.st_mode & S_IFDIR) != 0;
    }

    return FALSE;
}

bool_t file_read_text(const char* filename, str_t* s) {
    FILE* fp = NULL;
    bool_t ret = FALSE;
    return_value_if_fail(filename != NULL && s != NULL, FALSE);

    fp = fopen(filename, "rb");
    if(fp != NULL) {
        size_t len = file_get_size(filename);
        if(str_extend(s, len)) {
            ret = 1 == fread(s->str, len, 1, fp);
            s->size = len;
        }
        fclose(fp);
    }
    
    return ret;
}

bool_t file_write_text(const char* filename, const char* content) {
    FILE* fp = NULL;
    bool_t ret = FALSE;
    return_value_if_fail(filename != NULL && content != NULL, FALSE);

    fp = fopen(filename, "wb+");
    if(fp != NULL) {
        ret = 1 == fwrite(content, strlen(content), 1, fp);
        fclose(fp);
    }

    return ret;
}

