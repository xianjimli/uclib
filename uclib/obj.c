/* 
 * 功能说明：
 *     1.obj_t类的声明。
 *
 * 修改历史：
 *     1.2017-5-7 李先静 创建。
 */

#include "obj.h"

static void obj_destroy(obj_t* obj);

obj_t* obj_init(obj_t* obj, uint16_t magic) {
    return_value_if_fail(obj != NULL, NULL);

    obj->ref = 1;
    obj->magic = magic;

    return obj;
}

obj_t* obj_ref(obj_t* obj) {
    return_value_if_fail(obj != NULL && obj->ref > 0, NULL);
    obj->ref++;

    return obj;
}

obj_t* obj_unref(obj_t* obj) {
    return_value_if_fail(obj != NULL && obj->ref > 0, NULL);

    obj->ref--;
    if(obj->ref == 0) {
        obj_destroy(obj);
        obj = NULL;
    }

    return obj;
}

obj_t* obj_dup(obj_t* obj) {
    return_value_if_fail(obj != NULL && obj->ref > 0 && obj->dup != NULL, NULL);

    return obj->dup(obj);
}

bool_t obj_copy(obj_t* obj, obj_t* other) {
    return_value_if_fail(other != NULL && other->ref > 0, FALSE);
    return_value_if_fail(obj != NULL && obj->ref > 0 && obj->copy != NULL, FALSE);

    return obj->copy(obj, other);
}

value_t  obj_prop(obj_t* obj, const char* prop) {
    return_value_if_fail(obj != NULL && obj->ref > 0 && obj->get_prop && prop, value_null);

    return obj->get_prop(obj, prop);
}

bool_t    obj_set_prop(obj_t* obj, const char* prop, value_t value) {
    return_value_if_fail(obj != NULL && obj->ref > 0 && obj->set_prop && prop, FALSE);

    return obj->set_prop(obj, prop, value);
}

bool_t obj_on(obj_t* obj, const char* event_name, on_event_t on_event, void* ctx) {
    return_value_if_fail(obj != NULL && obj->ref > 0, FALSE);
    return_value_if_fail(event_name != NULL && on_event != NULL, FALSE);

    if(!obj->emitter) {
        obj->emitter = emitter_create();
        return_value_if_fail(obj->emitter != NULL, FALSE);
    }
    
    return emitter_on(obj->emitter, event_name, on_event, ctx);
}

bool_t obj_off(obj_t* obj, const char* event_name, on_event_t on_event, void* ctx) {
    return_value_if_fail(obj != NULL && obj->ref > 0, FALSE);
    return_value_if_fail(event_name != NULL && on_event != NULL, FALSE);
    return_value_if_fail(obj->emitter != NULL, FALSE);
    
    return emitter_off(obj->emitter, event_name, on_event, ctx);
}

bool_t obj_emit(obj_t* obj, event_t* event) {
    return_value_if_fail(obj != NULL && obj->ref > 0, FALSE);
    return_value_if_fail(event != NULL && obj->emitter != NULL, FALSE);

    return emitter_emit(obj->emitter, event);
}

static void obj_destroy(obj_t* obj) {
    return_if_fail(obj != NULL);

    if(obj->destroy) {
        obj->destroy(obj);
    }
    if(obj->emitter) {
        emitter_destroy(obj->emitter);
    }
    memset(obj, 0x00, sizeof(obj_t));
    free(obj);
}

