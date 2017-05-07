#include "uclib/types_def.h"

#ifndef THREAD_H
#define THREAD_H 

struct _thread_t;
typedef struct _thread_t thread_t;

typedef void* (thread_entry_t)(void* args);

BEGIN_C_DECLS

thread_t* thread_create(thread_entry_t entry, void* ctx);

bool_t thread_start(thread_t* thread);
bool_t thread_join(thread_t* thread);

void thread_destroy(thread_t* thread);

END_C_DECLS

#endif

