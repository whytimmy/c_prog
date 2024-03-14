set(SOURCES 
	shell_test.cpp
)

add_executable(shell_test ${SOURCES})
target_link_libraries(shell_test 
	gtest_main 
	gmock_main 
	shell_sort_lib
)

add_test(shell_test shell_test)
