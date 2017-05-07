
#include "obj.h"


value_t*  obj_prop(obj_t* o, const char* name) {
    return NULL;
}

bool_t obj_set_prop(obj_t* o, const char* name, value_t value) {
    return TRUE;;
}

obj_t* obj_ref(obj_t* o) {
    return o;
}

obj_t* obj_unref(obj_t* o) {
    return o;
}

obj_t* obj_dup(obj_t* o) {
    return o;
}
bool_t obj_copy(obj_t* o, obj_t* other) {
    return TRUE;
}

