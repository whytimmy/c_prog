target_sources(shell_sort_lib
	PRIVATE
		shell_sort.cpp
	PUBLIC
		shell_sort.hpp
)

target_include_directories(shell_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)