
#include "uclib/str.h"

#ifndef FILE_H
#define FILE_H

BEGIN_C_DECLS

bool_t dir_exist(const char* path);
bool_t file_delete(const char* filename);
size_t file_get_size(const char* filename);
bool_t file_exist(const char* filename);
bool_t file_read_text(const char* filename, str_t* s);
bool_t file_write_text(const char* filename, const char* content);

END_C_DECLS

#endif/*FILE_H*/
