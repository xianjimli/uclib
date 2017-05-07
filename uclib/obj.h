
#include "uclib/value.h"

#ifndef OBJ_H
#define OBJ_H 

BEGIN_C_DECLS

struct _obj_t;
typedef struct _obj_t obj_t;

struct _obj_t {
   uint16_t ref;
   uint16_t magic;
};

value_t*  obj_prop(obj_t* o, const char* name);
bool_t obj_set_prop(obj_t* o, const char* name, value_t value);

obj_t* obj_ref(obj_t* o);
obj_t* obj_unref(obj_t* o);
obj_t* obj_dup(obj_t* o);
bool_t obj_copy(obj_t* o, obj_t* other);

END_C_DECLS

#endif
