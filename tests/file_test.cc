#include "gtest/gtest.h"
#include "uclib/file.h"


#define FILENAME "__foo__.txt"
#define CONTENT "hell world"

TEST(file, basic) {
    str_t* s = str_create(NULL, 0, 100);
    ASSERT_EQ(file_write_text(FILENAME, CONTENT), TRUE);
    ASSERT_EQ(file_get_size(FILENAME), strlen(CONTENT));
    ASSERT_EQ(file_exist(FILENAME), TRUE);
    ASSERT_EQ(file_read_text(FILENAME, s), TRUE);
    ASSERT_EQ(str_equal(s, CONTENT), TRUE);
    ASSERT_EQ(s->size, strlen(CONTENT));
    ASSERT_EQ(file_delete(FILENAME), TRUE);
    ASSERT_EQ(file_exist(FILENAME), FALSE);
    str_unref(s);
}

