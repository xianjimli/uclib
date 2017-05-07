
#include "gtest/gtest.h"
#include "uclib/str.h"
#include "uclib/map.h"
#include "uclib/value_helper.h"

TEST(map, basic) {
    uint32_t i = 0;
    uint32_t n = 100;
    str_t* key = str_create(NULL, 0, 0);
    map_t* map = map_create(FALSE);

    for(i = 0; i < n; i++) {
        str_from_int(key, i);
        ASSERT_EQ(TRUE, map_set(map, key->str, value_from_int32(i)));
        ASSERT_EQ(value_int32(map_get(map, key->str)), i);
        ASSERT_EQ(map_size(map), i+1);
    }
    
    for(i = 0; i < n; i++) {
        str_from_int(key, i);
        ASSERT_EQ(map_delete(map, key->str), TRUE);
    }

    map_destroy(map);
    str_unref(key);
}

