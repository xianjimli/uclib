#include "gtest/gtest.h"
#include "uclib/str.h"
#include "uclib/map.h"
#include "uclib/emitter.h"
#include "uclib/value_helper.h"

static bool_t on_event(void* ctx, event_t* event) {
    int* p = (int*)ctx;

    *p = *p + 1;

    (void)event;
    return FALSE;
}

#define EVENT_NAME "changed"

TEST(emitter, basic) {
    int i = 0;
    int n = 100;
    int count = 0;

    event_t* event = event_create(EVENT_NAME);
    emitter_t* emitter = emitter_create();
    ASSERT_EQ(TRUE, emitter_on(emitter, EVENT_NAME, on_event, &count)); 

    for(i = 0; i < n; i++) {
        ASSERT_EQ(TRUE, emitter_emit(emitter, event));
        ASSERT_EQ(count, i+1);
    }
    
    ASSERT_EQ(TRUE, emitter_off(emitter, EVENT_NAME, on_event, &count)); 
    event_unref(event);
    emitter_destroy(emitter);
}

