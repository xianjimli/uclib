#include "event.h"
#include "value_helper.h"

event_t* event_create(const char* name) {
    event_t* event = NULL;
    return_value_if_fail(name != NULL, NULL);

    event = (event_t*)calloc(1, sizeof(event_t));
    return_value_if_fail(event != NULL, NULL);

    do {
        event->name = str_create(name, strlen(name), 0);
        break_if_fail(event->name != NULL);
        event->params = map_create(FALSE); 
        event->ref = 1;
    }while(0);

    if(event->name == NULL || event->params == NULL) {
        if(event->name != NULL) {
            str_unref(event->name);
        }
        if(event->params != NULL) {
            map_destroy(event->params);
        }

        event = NULL;
    }

    return event;
}

bool_t   event_set_name(event_t* event, const char* name) {
    return_value_if_fail(event != NULL && name != NULL, FALSE);

    return str_set(event->name, name, strlen(name));
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
    return_if_fail(event != NULL && event->name != NULL && event->params != NULL);

    str_unref(event->name);
    map_destroy(event->params);
    memset(event, 0x00, sizeof(event_t));
    free(event);

    return;
}

static bool_t on_param(void* ctx, value_t* v) {
    key_value_t* kv = (key_value_t*)value_pointer(v);
    printf("   %s = %s\n", kv->key->str, value_str(&kv->value)->str);
    (void)ctx;

    return FALSE;
}

void event_dump(event_t* event) {
    printf("%s {\n", event->name->str);
    map_foreach(event->params, (visit_t)on_param, NULL);
    printf("}\n");
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
    }else{
        return event;
    }
}


