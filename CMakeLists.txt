cmake_minimum_required(VERSION 2.8)

set(NAME wolf3d)

project(${NAME})

set(SRC
	src/main.cpp
	src/example.cpp
)

add_executable(${NAME} ${SRC})
target_link_libraries(${NAME} GL GLU GLEW glfw)