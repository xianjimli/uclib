add_library(uclib 
    mutex.c 
    thread.c 
    emitter.c 
    event.c 
    map.c 
    file.c 
    array.c 
    str.c 
    obj.c 
    value.c 
    date_time.c)

if(WIN32)
set_target_properties(uclib
    PROPERTIES
    COMPILE_FLAGS /wd"4819"
)
endif()

