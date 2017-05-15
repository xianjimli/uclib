set(APP_SRC 
    extract_doc.c
	)

add_executable(extract_doc ${APP_SRC})
target_link_libraries(extract_doc uclib ${SYS_LIBS}) 

if(WIN32)
set_target_properties(extract_doc
    PROPERTIES
    COMPILE_FLAGS /wd"4819"
)
endif()


