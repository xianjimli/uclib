#include "gtest/gtest.h"
#include "uclib/event.h"

TEST(event, basic) {
    event_t* event = event_create("changed");

    ASSERT_EQ(str_equal(event->name, "changed"), TRUE);
    ASSERT_EQ(event_set_param(event, "prop", "100"), TRUE);
    ASSERT_EQ(strcmp(event_get_param(event, "prop"), "100") == 0, TRUE);

    ASSERT_EQ(event_set_param(event, "value", "100"), TRUE);
    ASSERT_EQ(strcmp(event_get_param(event, "value"), "100") == 0, TRUE);
    event_dump(event);
    event_unref(event);
}

