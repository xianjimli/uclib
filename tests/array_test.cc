#include "gtest/gtest.h"
#include "uclib/array.h"
#include "uclib/array_helper.h"
#include "uclib/value_helper.h"

TEST(array, basic) {
    int32_t i = 0;
    int32_t n = 10000;
    array_t* a = array_create(FALSE);

    for(i = 0; i < n; i++) {
        ASSERT_EQ(TRUE, array_append_int32(a, i)); 
        ASSERT_EQ(array_get_int32(a, i), i); 

        ASSERT_EQ(array_set(a, i, value_from_int32(i+1)), TRUE); 
        ASSERT_EQ(array_get_int32(a, i), i+1); 

        ASSERT_EQ(array_set(a, i, value_from_int32(i)), TRUE); 
        ASSERT_EQ(array_get_int32(a, i), i); 
        ASSERT_EQ(a->size, i+1);
    }

    for(i = 0; i < n; i++) {
        ASSERT_EQ(array_get_int32(a, 0), i); 
        ASSERT_EQ(TRUE, array_delete(a, 0)); 
    }

    ASSERT_EQ(a->size, 0);

    array_destroy(a);
}

TEST(array, str) {
    int32_t i = 0;
    int32_t n = 10000;
    array_t* a = array_create(TRUE);
    str_t* str = str_create(NULL, 0, 0);

    for(i = 0; i < n; i++) {
        str_from_int(str, i);
        ASSERT_EQ(TRUE, array_append_str(a, str)); 
        str_t* s = array_get_str(a, i);
        value_t* v = array_get(a, i);
        ASSERT_EQ(str_to_int(s), i); 
    }

    for(i = 0; i < n; i++) {
        ASSERT_EQ(str_to_int(array_get_str(a, 0)), i); 
        ASSERT_EQ(TRUE, array_delete(a, 0)); 
    }

    ASSERT_EQ(a->size, 0);
    str_unref(str);

    array_destroy(a);
}
