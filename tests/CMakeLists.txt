include_directories(${PROJECT_SOURCE_DIR}/3rd-party/googletest)
include_directories(${PROJECT_SOURCE_DIR}/3rd-party/googletest/src)
include_directories(${PROJECT_SOURCE_DIR}/3rd-party/googletest/include)
link_directories(${PROJECT_SOURCE_DIR}/3rd-party/googletest/make)

set(APP_SRC 
	${PROJECT_SOURCE_DIR}/3rd-party/googletest/src/gtest-all.cc
	${PROJECT_SOURCE_DIR}/3rd-party/googletest/src/gtest_main.cc
	str_test.cc
	array_test.cc
	file_test.cc
	value_test.cc
	map_test.cc
	event_test.cc
	emitter_test.cc
	thread_test.cc
	obj_test.cc
	)

add_executable(runTest ${APP_SRC})
target_link_libraries(runTest uclib ${SYS_LIBS}) 


