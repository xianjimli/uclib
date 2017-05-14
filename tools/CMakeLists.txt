set(APP_SRC 
    extract_doc.c
	)

add_executable(extract_doc ${APP_SRC})
target_link_libraries(extract_doc uclib ${SYS_LIBS}) 


