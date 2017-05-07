#include "str.h"
#include "obj.h"
#include "value.h"

value_t* value_set_int8(value_t* gv, int8_t value) {
	return_value_if_fail(gv != NULL, NULL);
	gv->type = VALUE_TYPE_INT8;
	gv->value.i8 = value;

	return gv;
}

int8_t value_int8(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_INT8, 0);

	return gv->value.i8;
}

value_t* value_set_uint8(value_t* gv, uint8_t value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_UINT8;
	gv->value.u8 = value;

	return gv;
}

uint8_t value_uint8(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_UINT8, 0);

	return gv->value.u8;
}

value_t* value_set_int16(value_t* gv, int16_t value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_INT16;
	gv->value.i16 = value;

	return gv;
}

int16_t value_int16(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_INT16, 0);

	return gv->value.i16;
}

value_t* value_set_uint16(value_t* gv, uint16_t value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_UINT16;
	gv->value.u16 = value;

	return gv;
}

uint16_t value_uint16(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_UINT16, 0);

	return gv->value.u16;
}

value_t* value_set_int32(value_t* gv, int32_t value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_INT32;
	gv->value.i32 = value;

	return gv;
}

int32_t value_int32(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_INT32, 0);

	return gv->value.i32;
}

value_t* value_set_uint32(value_t* gv, uint32_t value) {
	return_value_if_fail(gv != NULL, NULL);
	gv->type = VALUE_TYPE_UINT32;
	gv->value.u32 = value;

	return gv;
}

uint32_t value_uint32(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_UINT32, 0);

	return gv->value.u32;
}

value_t* value_set_int64(value_t* gv, int64_t value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_INT64;
	gv->value.i64 = value;

	return gv;
}

int64_t value_int64(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_INT64, 0);

	return gv->value.i64;
}

value_t* value_set_uint64(value_t* gv, uint64_t value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_UINT64;
	gv->value.u64 = value;

	return gv;
}

uint64_t value_uint64(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_UINT64, 0);

	return gv->value.u64;
}

value_t* value_set_pointer(value_t* gv, void* value, destroy_t destroy) {
	return_value_if_fail(gv != NULL, NULL);

    gv->type = VALUE_TYPE_POINTER;
    gv->value.ptr.data = value;
    gv->value.ptr.destroy = destroy;

	return gv;
}

void* value_pointer(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_POINTER, NULL);

	return gv->value.ptr.data;
}

value_t* value_set_float(value_t* gv, float value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_FLOAT32;
	gv->value.f32 = value;

	return gv;
}

float value_float(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_FLOAT32, 0.0);

	return gv->value.f32;
}

value_t* value_set_double(value_t* gv, double value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_FLOAT64;
	gv->value.f65 = value;

	return gv;
}

double value_double(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_FLOAT64, 0);

	return gv->value.f65;
}

value_t* value_set_obj(value_t* gv, obj_t* value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_OBJECT;
	gv->value.obj = value;

	return gv;
}

obj_t* value_obj(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_OBJECT, NULL);

	return gv->value.obj;
}

value_t* value_set_str(value_t* gv, str_t* value) {
	return_value_if_fail(gv != NULL, NULL);

	gv->type = VALUE_TYPE_STRING;
	gv->value.str = value;

	return gv;
}

str_t* value_str(value_t* gv) {
	return_value_if_fail(gv != NULL && gv->type == VALUE_TYPE_STRING, NULL);

	return gv->value.str;
}

void value_copy(value_t* dst, const value_t* src, bool_t deep_copy) {
    return_if_fail(dst != NULL && src != NULL);
    if(dst == src) {
        return;
    }

    if(src->type == VALUE_TYPE_OBJECT) {
        dst->type = VALUE_TYPE_OBJECT;
        dst->value.obj = deep_copy ? obj_dup(src->value.obj) : obj_ref(src->value.obj);
    }else if(src->type == VALUE_TYPE_STRING) {
        dst->type = VALUE_TYPE_STRING;
        dst->value.str = deep_copy ? str_dup(src->value.str) : str_ref(src->value.str);
    }else{
	    memcpy(dst, src, sizeof(value_t));
    }
}

value_t* value_ref(value_t* value) {
    return_value_if_fail(value != NULL, NULL);

    if(value->type == VALUE_TYPE_OBJECT) {
        obj_ref(value->value.obj);
    }else if(value->type == VALUE_TYPE_STRING) {
        str_ref(value->value.str);
    }

    return value;
}

value_t* value_unref(value_t* value) {
    return_value_if_fail(value != NULL, NULL);

    if(value->type == VALUE_TYPE_OBJECT) {
        obj_unref(value->value.obj);
        value->value.obj = NULL;
    }else if(value->type == VALUE_TYPE_STRING) {
        str_unref(value->value.str);
        value->value.str = NULL;
    }else if(value->type == VALUE_TYPE_POINTER) {
        if(value->value.ptr.destroy) {
            value->value.ptr.destroy(value->value.ptr.data);
            value->value.ptr.data = NULL;
            value->value.ptr.destroy = NULL;
        }
        value->type = VALUE_TYPE_INVALID;
    }
   
    return value;
}

