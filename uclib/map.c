#include "map.h"
#include "value_helper.h"

struct _map_t {
    array_t* array;
};

static key_value_t* key_value_create(const char* key, value_t value, bool_t deep_copy) {
    key_value_t* kv = calloc(1, sizeof(key_value_t));
    return_value_if_fail(kv != NULL, NULL);

    kv->key = str_create(key, strlen(key), 0);
    value_copy(&kv->value, &value, deep_copy);
    
    return kv;
}

static bool_t key_value_destroy(key_value_t* kv) {
    return_value_if_fail(kv != NULL && kv->key, FALSE);

    str_unref(kv->key);
    value_unref(&kv->value);
    memset(kv, 0x00, sizeof(key_value_t));

    free(kv);

    return FALSE;
}

static int compare_kv(const char* a, value_t* v) {
    key_value_t* b = (key_value_t*)value_pointer(v);
    return strcmp(a, b->key->str);
}

map_t* map_create(bool_t deep_copy) {
    map_t* map = NULL;
    array_t* array = array_create(deep_copy);
    return_value_if_fail(array != NULL, NULL);
    
    map = (map_t*)calloc(1, sizeof(map_t));
    if(map) {
        map->array = array;
    }else{
        array_destroy(array);
    }

    return map;
}

value_t*  map_get(map_t* map, const char* key) {
    int pos = 0;
    key_value_t* kv = NULL;
    return_value_if_fail(map != NULL && map->array != NULL && key != NULL, NULL);
    
    pos = array_find(map->array, (compare_t)compare_kv, (void*)key);
    return_value_if_fail(pos >= 0, NULL);

    kv = value_pointer(array_get(map->array, pos));

    return &(kv->value);
}

bool_t    map_set(map_t* map, const char* key, value_t data) {
    int pos = 0;
    return_value_if_fail(map != NULL && map->array != NULL && key != NULL, FALSE);
    
    pos = array_find(map->array, (compare_t)compare_kv, (void*)key);
    if(pos < 0) {
        key_value_t* kv = key_value_create(key, data, map->array->deep_copy);
        return array_append(map->array, value_from_pointer(kv, (destroy_t)key_value_destroy));  
    }else{
        key_value_t* kv = value_pointer(array_get(map->array, pos));
        value_copy(&kv->value, &data, map->array->deep_copy);

        return TRUE;
    }
}

bool_t    map_delete(map_t* map, const char* key) {
    int pos = 0;
    return_value_if_fail(map != NULL && map->array != NULL && key != NULL, FALSE);
    
    pos = array_find(map->array, (compare_t)compare_kv, (void*)key);
    return_value_if_fail(pos >= 0, FALSE);

    return array_delete(map->array, pos);
}

bool_t    map_foreach(map_t* map, visit_t visit, void* ctx) {
    return_value_if_fail(map != NULL && map->array != NULL && visit != NULL, FALSE);

    return array_foreach(map->array, visit, ctx);
}

bool_t    map_clear(map_t* map) {
    return_value_if_fail(map != NULL && map->array != NULL, FALSE);
    array_clear(map->array);

    return TRUE;
}

void map_destroy(map_t* map) {
    return_if_fail(map != NULL && map->array != NULL);
    map_clear(map);
    array_destroy(map->array);
    map->array = NULL;
    free(map);
}

uint32_t  map_size(map_t* map) {
    return_value_if_fail(map != NULL && map->array != NULL, 0);

    return map->array->size;
}
