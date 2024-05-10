project(scl)

add_library(scl_lib "")
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE scl_lib)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_SUPPRESS_REGENERATION true)
