#include "gtest/gtest.h"
#include "uclib/event.h"

TEST(event, basic) {
    str_t* str = str_create(NULL, 0, 0);
    event_t* event = event_create("changed");

    ASSERT_EQ(str_equal(event->type, "changed"), TRUE);
    ASSERT_EQ(event_set_param(event, "prop", "100"), TRUE);
    ASSERT_EQ(strcmp(event_get_param(event, "prop"), "100") == 0, true);

    ASSERT_EQ(event_set_param(event, "value", "100"), TRUE);
    ASSERT_EQ(strcmp(event_get_param(event, "value"), "100") == 0, true);
    event_dump(event, str);
    ASSERT_EQ(str_equal(str, "changed {prop = 100;value = 100;}"), TRUE);
    event_unref(event);
    str_unref(str);
}

