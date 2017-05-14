#include "gtest/gtest.h"
#include "uclib/obj.h"
#include "uclib/value_helper.h"

typedef struct _my_obj_t {
    obj_t obj;
    str_t* name;
    int age;
}my_obj_t;

bool_t my_obj_set_prop(my_obj_t* obj, const char* name, value_t value) {
    char c = name[0];
    if(c == 'n') {
        const char* str = (const char*)value_pointer(value);
        str_set(obj->name, str, strlen(str)); 
    
        return TRUE;
    }else if(c == 'a') {
        obj->age = value_int32(value);
        return TRUE;
    }else{
        printf("not supported.\n");
        return FALSE;
    }
}

value_t my_obj_get_prop(my_obj_t* obj, const char* name) {
    char c = name[0];
    if(c == 'n') {
        return value_from_pointer((void*)obj->name->str, NULL);
    }else if(c == 'a') {
        return value_from_int32(obj->age);
    }else{
        printf("not supported.\n");
    }
   
    return value_null;
}

static void my_obj_destroy(my_obj_t* obj) {
    str_unref(obj->name);
}

my_obj_t* my_obj_create() {
    my_obj_t* obj = (my_obj_t*)calloc(1, sizeof(my_obj_t));
    obj_init(&obj->obj, 0xffee);
    
    obj->name = str_create(NULL, 0, 0);
    obj->obj.set_prop = (obj_set_prop_t)my_obj_set_prop;
    obj->obj.get_prop = (obj_get_prop_t)my_obj_get_prop;
    obj->obj.destroy = (obj_destroy_t)my_obj_destroy;

    return obj;
}

TEST(obj, basic) {
    my_obj_t* obj = my_obj_create();
    
    ASSERT_EQ(TRUE, obj_set_prop(&obj->obj, "name", value_from_pointer((void*)"jim", NULL)));
    ASSERT_EQ(strcmp("jim", (char*)value_pointer(obj_prop(&obj->obj, "name"))) == 0, TRUE);

    ASSERT_EQ(TRUE, obj_set_prop(&obj->obj, "age", value_from_int32(100)));
    ASSERT_EQ(100, value_int32(obj_prop(&obj->obj, "age")));

    obj_unref(&obj->obj);
}

