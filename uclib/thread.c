#include "thread.h"

#ifdef WIN32 
#include <Windows.h>
#include <process.h>
#define  thread_t HANDLE
#else
#include "pthread.h"
#define  thread_t pthread_t
#endif

struct _thread_t {
    void* args;
    bool_t running;
    thread_t thread;
    thread_entry_t entry;
};

typedef struct _thread_t thread_t;

typedef void* (thread_entry_t)(void* args);

BEGIN_C_DECLS

thread_t* thread_create(thread_entry_t entry, void* args) {
    thread_t* thread = NULL;
    return_value_if_fail(entry != NULL, NULL);

    thread = (thread_t*)calloc(1, sizeof(thread_t));
    return_value_if_fail(thread != NULL, NULL);

    thread->args = args;
    thread->entry = entry;

    return thread;
}

static void* entry(thread_t* thread) {
    thread->entry(entry->args);
    thread->running = FALSE;

    return NULL;
}

bool_t thread_start(thread_t* thread) {
    return_value_if_fail(thread != NULL, FALSE);

#ifdef WIN32
#ifndef _beginthread_proc_type
typedef void (*_beginthread_proc_type)(void* args);
#endif//_beginthread_proc_type

    uint32_t stack_size = 1024 * 1024;
    thread->thread = (HANDLE)_beginthread((_beginthread_proc_type)entry, stack_size, thread);
    thread->running = thread->thread != NULL;
#else
    int ret = pthread_create(&(thread->thread), NULL, (void *(*)(void *))entry, thread);
    thread->running = ret == 0;
#endif

    return thread->running;
}

bool_t thread_join(thread_t* thread) {
    return_value_if_fail(thread != NULL, FALSE);
    if(thread->running) {
#ifdef WIN32
    WaitForSingleObject(thread->thread, INFINITE);
#else
    void* ret = NULL;
    if(thread->thread) {
        pthread_join(thread->thread, &ret);
    }
#endif
    }

    return TRUE;
}

void thread_destroy(thread_t* thread) {
    return_if_fail(thread != NULL);
    memset(thread, 0x00, sizeof(thread_t));
    free(thread);

    return;
}

END_C_DECLS

#endif

