#include "uclib/str.h"
#include "uclib/array.h"

#ifndef MAP_H
#define MAP_H

BEGIN_C_DECLS

struct _map_t;
typedef struct _map_t map_t;

typedef struct _key_value_t {
    str_t* key;
	value_t value;
}key_value_t;

map_t* map_create(bool_t deep_copy);

uint32_t  map_size(map_t* map);
value_t*  map_get(map_t* map, const char* key);
bool_t    map_set(map_t* map, const char* key, value_t data);
bool_t    map_delete(map_t* map, const char* key);
bool_t    map_foreach(map_t* map, visit_t visit, void* ctx);
bool_t    map_clear(map_t* map);

void map_destroy(map_t* map);

END_C_DECLS

#endif/*MAP_H*/

