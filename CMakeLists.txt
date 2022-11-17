cmake_minimum_required(VERSION 3.22.1)

project(STRING_TYPE)

add_executable(${PROJECT_NAME} src/main.c)

add_subdirectory(string_type)

target_include_directories(${PROJECT_NAME} PUBLIC string_type)
target_link_directories(${PROJECT_NAME} PRIVATE string_type)
target_link_libraries(${PROJECT_NAME} string_type)
