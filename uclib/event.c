/* 
 * 功能说明：
 *     1.event_t类的实现。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */
#include "event.h"
#include "value_helper.h"

event_t* event_create(const char* type) {
    event_t* event = NULL;
    return_value_if_fail(type != NULL, NULL);

    event = (event_t*)calloc(1, sizeof(event_t));
    return_value_if_fail(event != NULL, NULL);

    do {
        event->type = str_create(type, strlen(type), 0);
        break_if_fail(event->type != NULL);
        event->params = map_create(FALSE); 
        event->ref = 1;
    }while(0);

    if(event->type == NULL || event->params == NULL) {
        if(event->type != NULL) {
            str_unref(event->type);
        }
        if(event->params != NULL) {
            map_destroy(event->params);
        }

        event = NULL;
    }

    return event;
}

bool_t   event_set_type(event_t* event, const char* type) {
    return_value_if_fail(event != NULL && type != NULL, FALSE);

    return str_set(event->type, type, strlen(type));
}

bool_t   event_set_param(event_t* event, const char* name, const char* value) {
    return_value_if_fail(event != NULL && name != NULL && value != NULL, FALSE);

    return map_set(event->params, name, value_from_str(str_create(value, strlen(value), 0))); 
}

const char* event_get_param(event_t* event, const char* name) {
    return_value_if_fail(event != NULL && name != NULL, FALSE);
    
    return value_str(map_get(event->params, name))->str;
}

static void event_destroy(event_t* event) {
    return_if_fail(event != NULL && event->type != NULL && event->params != NULL);

    str_unref(event->type);
    map_destroy(event->params);
    memset(event, 0x00, sizeof(event_t));
    free(event);

    return;
}

static bool_t on_param(void* ctx, value_t* v) {
    str_t* str = (str_t*)ctx;
    key_value_t* kv = (key_value_t*)value_pointer(*v);
    str_append(str, "", -1);
    str_append(str, kv->key->str, -1);
    str_append(str, " = ", -1);
    str_append(str, value_str(kv->value)->str, -1);
    str_append(str, ";", -1);

    return FALSE;
}

void event_dump(event_t* event, str_t* str) {
    str_append(str, event->type->str, -1);
    str_append(str, " {", -1);
    map_foreach(event->params, (visit_t)on_param, str);
    str_append(str, "}", -1);
}

event_t* event_ref(event_t* event) {
    return_value_if_fail(event != NULL && event->ref > 0, NULL);
    event->ref++;

    return event;
}

event_t* event_unref(event_t* event) {
    return_value_if_fail(event != NULL && event->ref > 0, NULL);
    event->ref--;
    if(event->ref == 0) {
        event_destroy(event);
        return NULL;
    }else{
        return event;
    }
}


