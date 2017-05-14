/* 
 * 功能说明：
 *     1.emitter_t类的实现。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "uclib/emitter.h"
#include "uclib/value_helper.h"

typedef struct _listener_t {
    void* ctx;
    on_event_t on_event;
}listener_t;

static listener_t* listener_create(on_event_t on_event, void* ctx) {
    listener_t* listener = (listener_t*)calloc(1, sizeof(listener_t));
    return_value_if_fail(listener != NULL, NULL);

    listener->ctx = ctx;
    listener->on_event = on_event;

    return listener;
}

static void listener_destroy(listener_t* listener) {
    return_if_fail(listener != NULL && listener->on_event);

    memset(listener, 0x00, sizeof(listener_t));
    free(listener);
}

static int listener_compare(listener_t* a, value_t* v) {
    listener_t* b = (listener_t*)value_pointer(*v);
    return (a->on_event == b->on_event && a->ctx == b->ctx) ? 0 : 1;
}

emitter_t* emitter_create() {
    emitter_t* emitter = (emitter_t*)calloc(1, sizeof(emitter_t));
    return_value_if_fail(emitter != NULL, NULL);

    emitter->listeners = map_create(FALSE);
    if(emitter->listeners == NULL) {
        free(emitter);
        emitter = NULL;
    }

    return emitter;
}

bool_t emitter_on(emitter_t* emitter, const char* name, on_event_t on_event, void* ctx) {
    value_t value;
    array_t* arr = NULL;
    listener_t* listener = NULL;
    return_value_if_fail(emitter != NULL && name != NULL && on_event != NULL, FALSE);
    
    value = map_get(emitter->listeners, name);
    if(value_is_null(value)) {
        arr = array_create(FALSE);
        return_value_if_fail(arr != NULL, FALSE);

        map_set(emitter->listeners, name, value_from_pointer(arr, (destroy_t)array_destroy));
    }else{
        arr = value_pointer(value);
    }
    
    listener = listener_create(on_event, ctx);
    return_value_if_fail(listener != NULL, FALSE);

    return array_append(arr, value_from_pointer(listener, (destroy_t)listener_destroy));
}

bool_t emitter_off(emitter_t* emitter, const char* name, on_event_t on_event, void* ctx) {
    value_t value;
    array_t* arr = NULL;
    return_value_if_fail(emitter != NULL && name != NULL && on_event != NULL, FALSE);
    
    value = map_get(emitter->listeners, name);
    if(!value_is_null(value)) {
        int pos = 0;
        listener_t listener;
        listener.ctx = ctx;
        listener.on_event = on_event;

        arr = value_pointer(value);
        pos = array_find(arr, (compare_t)listener_compare, &listener); 
        return_value_if_fail(pos >= 0, FALSE);

        array_delete(arr, pos);
    }

    return TRUE;
}

static bool_t emit(event_t* event, value_t* value) {
    listener_t* listener = (listener_t*)value_pointer(*value);
    return_value_if_fail(listener != NULL && listener->on_event != NULL, FALSE);

    return listener->on_event(listener->ctx, event);
}

bool_t emitter_emit(emitter_t* emitter, event_t* event) {
    value_t value;
    array_t* arr = NULL;
    return_value_if_fail(emitter != NULL && event != NULL && event->type != NULL, FALSE);
    
    value = map_get(emitter->listeners, event->type->str);
    if(!value_is_null(value)) {
        arr = value_pointer(value);
        array_foreach(arr, (visit_t)emit, event);
    }

    return TRUE;
}

void emitter_destroy(emitter_t* emitter) {
    return_if_fail(emitter != NULL && emitter->listeners != NULL);

    map_destroy(emitter->listeners);
    emitter->listeners = NULL;

    free(emitter);
}


