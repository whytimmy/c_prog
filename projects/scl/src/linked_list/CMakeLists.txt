target_sources(scl_lib 
	PRIVATE
		linked_list.cpp
	PUBLIC
		linked_list.hpp
)

target_include_directories(scl_lib PUBLIC
		${PROJECT_SOURCE_DIR}/src/linked_list
)
