
#include "uclib/str.h"
#include "uclib/map.h"

#ifndef EVENT_H
#define EVENT_H 

BEGIN_C_DECLS

typedef struct _event_t {
    uint32_t ref;
    str_t* name;
    map_t* params;
}event_t;

event_t* event_create(const char* name);
bool_t   event_set_name(event_t* event, const char* name);
bool_t   event_set_param(event_t* event, const char* name, const char* value);
const char* event_get_param(event_t* event, const char* name);

event_t* event_ref(event_t* event);
event_t* event_unref(event_t* event);

void event_dump(event_t* event);

END_C_DECLS

#endif
