#include "gtest/gtest.h"
#include "uclib/str.h"

static void assert_s(str_t* s, uint16_t ref, uint32_t size, const char* str) {
    ASSERT_EQ(s->ref, ref);
    ASSERT_EQ(s->size, size);
    ASSERT_GE(s->capacity, s->size);
    ASSERT_EQ(strcmp(s->str, str), 0);
}

#define STR "abc"
#define SUB_STR "a"
#define SUB_STR_END "bc"

TEST(str, create) {
    str_t* s = str_create(STR, -1, 100);
    assert_s(s, 1, sizeof(STR)-1, STR);
    str_unref(s);
}

TEST(str, start_end) {
    str_t* s = str_create(STR, -1, 100);
    ASSERT_EQ(str_start_with(s, SUB_STR), TRUE);
    ASSERT_EQ(str_end_with(s, SUB_STR_END), TRUE);
    str_unref(s);
}

TEST(str, dup) {
    str_t* s = str_create(STR, -1, 100);
    str_t* ss = str_dup(s);

    assert_s(s, 1, sizeof(STR)-1, STR);
    assert_s(ss, 1, sizeof(STR)-1, STR);

    str_unref(ss);
    str_unref(s);
}

TEST(str, lower_upper) {
    str_t* s = str_create("abc123", -1, 100);
    ASSERT_EQ(TRUE, str_to_upper(s));
    ASSERT_EQ(TRUE, str_equal(s, "ABC123"));
    
    ASSERT_EQ(TRUE, str_to_lower(s));
    ASSERT_EQ(TRUE, str_equal(s, "abc123"));
    str_unref(s);
}

TEST(str, copy) {
    str_t* s = str_create(STR, -1, 100);
    str_t* ss = str_create(NULL, 0, 0);
    
    str_copy(ss, s);
    assert_s(s, 1, sizeof(STR)-1, STR);
    assert_s(ss, 1, sizeof(STR)-1, STR);

    str_unref(ss);
    str_unref(s);
}

TEST(str, sub) {
    str_t* s = str_create(STR, strlen(STR), 100);
    str_t* s1 = str_sub(s, 0, 1);
    str_t* s2 = str_sub(s, 0, 100);

    assert_s(s1, 1, strlen(SUB_STR), SUB_STR);
    assert_s(s2, 1, strlen(STR), STR);

    str_unref(s1);
    str_unref(s2);
    str_unref(s);
}

TEST(str, index_of_c) {
    str_t* s = str_create("a/b/c", 0xff, 0xff);
    ASSERT_EQ(str_index_of_c(s, '/'), 1);
    ASSERT_EQ(str_index_of_c(s, 'a'), 0);
    ASSERT_EQ(str_index_of_c(s, 'c'), 4);
    ASSERT_EQ(str_index_of_c(s, 'd'), -1);
    str_unref(s);
}

TEST(str, last_index_of_c) {
    str_t* s = str_create("a/b/c", 0xff, 0xff);
    ASSERT_EQ(str_last_index_of_c(s, '/'), 3);
    ASSERT_EQ(str_last_index_of_c(s, 'a'), 0);
    ASSERT_EQ(str_last_index_of_c(s, 'd'), -1);
    str_unref(s);
}

TEST(str, index_of) {
    str_t* s = str_create("a/b/c", 0xff, 0xff);
    ASSERT_EQ(str_index_of(s, "/"), 1);
    ASSERT_EQ(str_index_of(s, "a"), 0);
    ASSERT_EQ(str_index_of(s, "d"), -1);
    str_unref(s);
}

TEST(str, replace_c) {
    str_t* s = str_create("a/b/c", 0xff, 0xff);
    ASSERT_EQ(str_replace_c(s, '/', '\\'), TRUE);
    ASSERT_EQ(str_equal(s, "a\\b\\c"), TRUE);
    str_unref(s);
}

TEST(str, replace) {
    str_t* s = str_create("a/b/c", 0xff, 0xff);
    ASSERT_EQ(str_replace(s, "/", "\\"), TRUE);
    ASSERT_EQ(str_equal(s, "a\\b\\c"), TRUE);
    ASSERT_EQ(str_set(s, "abc abc abc", 0xffff), TRUE);
    ASSERT_EQ(str_replace(s, "ab", "AB"), TRUE);
    ASSERT_EQ(str_equal(s, "ABc ABc ABc"), TRUE);
    
    ASSERT_EQ(str_replace(s, "AB", ""), TRUE);
    ASSERT_EQ(str_equal(s, "c c c"), TRUE);
    str_unref(s);
}

TEST(str, append_char) {
    str_t* s = str_create(NULL, 0xff, 0xff);
    ASSERT_EQ(str_append_char(s, 'a'), TRUE);
    ASSERT_EQ(str_equal(s, "a"), TRUE);
    ASSERT_EQ(str_append_char(s, 'b'), TRUE);
    ASSERT_EQ(str_equal(s, "ab"), TRUE);
    ASSERT_EQ(str_append_char(s, 'c'), TRUE);
    ASSERT_EQ(str_equal(s, "abc"), TRUE);
    str_unref(s);
}

TEST(str, append_str) {
    str_t* s = str_create(NULL, 0xff, 0xff);
    ASSERT_EQ(str_append(s, "a", 1), TRUE);
    ASSERT_EQ(str_equal(s, "a"), TRUE);
    ASSERT_EQ(str_append(s, "b", 1), TRUE);
    ASSERT_EQ(str_equal(s, "ab"), TRUE);
    ASSERT_EQ(str_append(s, "c", 1), TRUE);
    ASSERT_EQ(str_equal(s, "abc"), TRUE);
    str_unref(s);
}

TEST(str, to_from_int) {
    str_t* s = str_create(NULL, 0xff, 0xff);
    ASSERT_EQ(str_from_int(s, 123), TRUE);
    ASSERT_EQ(str_to_int(s), 123);
    str_unref(s);
}

TEST(str, to_from_float) {
    str_t* s = str_create(NULL, 0xff, 0xff);
    ASSERT_EQ(str_from_float(s, (float)1.23), TRUE);
    ASSERT_LE(str_to_float(s) - 1.23, 0.00001);
    str_unref(s);
}

TEST(str, to_from_double) {
    str_t* s = str_create(NULL, 0xff, 0xff);
    ASSERT_EQ(str_from_double(s, 1.23), TRUE);
    ASSERT_LE(str_to_double(s) - 1.23, 0.00001);
    str_unref(s);
}

TEST(str, trim) {
    str_t* s = str_create("  abc  ", 0xff, 0xff);
    ASSERT_EQ(str_trim_left(s, NULL), TRUE);
    ASSERT_EQ(str_equal(s, "abc  "), TRUE);
    
    ASSERT_EQ(str_trim_right(s, NULL), TRUE);
    ASSERT_EQ(str_equal(s, "abc"), TRUE);

    str_unref(s);
}

TEST(str, path1) {
    str_t* path = str_create(NULL, 0, 0);
    str_t* filename = str_create(NULL, 0, 0);
    str_t* basename = str_create(NULL, 0, 0);
    str_t* extname = str_create(NULL, 0, 0);
    str_t* dirname = str_create(NULL, 0, 0);

    ASSERT_EQ(TRUE, str_normalize_path(filename, "/a/b/c\\d\\e.js", NULL));
    ASSERT_EQ(TRUE, str_normalize_path(path, "/a/b/c\\d\\", NULL));

    ASSERT_EQ(TRUE, str_basename(basename, filename->str, TRUE));
    ASSERT_EQ(TRUE, str_dirname(dirname, filename->str));
    ASSERT_EQ(TRUE, str_extname(extname, filename->str));

    ASSERT_EQ(TRUE, str_equal(basename, "e.js"));
    ASSERT_EQ(TRUE, str_equal(path, dirname->str)); 
    ASSERT_EQ(TRUE, str_equal(extname, "js")); 

    str_unref(path);
    str_unref(filename);
    str_unref(basename);
    str_unref(extname);
    str_unref(dirname);
}

TEST(str, static) {
    str_t str;
    char buff[256];
    str_init_static(&str, buff, 0, sizeof(buff));

    ASSERT_EQ(str_append(&str, "123", 3), TRUE);
    ASSERT_EQ(str_append(&str, "abc", 3), TRUE);
    ASSERT_EQ(str_equal(&str, "123abc"), TRUE);
    ASSERT_EQ(str_to_int(&str), 123);
}

