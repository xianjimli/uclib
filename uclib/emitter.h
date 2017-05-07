#include "uclib/str.h"
#include "uclib/map.h"
#include "uclib/event.h"

#ifndef EMITTER_H
#define EMITTER_H 

BEGIN_C_DECLS

typedef struct _emitter_t {
    map_t* listeners;
}emitter_t;

typedef bool_t (*on_event_t)(void* ctx, event_t* event);

emitter_t* emitter_create();

bool_t emitter_on(emitter_t* emitter, const char* name, on_event_t on_event, void* ctx);
bool_t emitter_off(emitter_t* emitter, const char* name, on_event_t on_event, void* ctx);
bool_t emitter_emit(emitter_t* emitter, event_t* event);

void emitter_destroy(emitter_t* emitter);

END_C_DECLS

#endif
