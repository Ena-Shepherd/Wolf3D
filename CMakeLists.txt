cmake_minimum_required(VERSION 3.16)

set(NAME wolf3d)

project(${NAME})

file(GLOB SOURCES "src/*.cpp" "libraries/SFML-2.6.0/lib/*.a")

include_directories("./libraries/SFML-2.6.0/include")
link_directories("./libraries/SFML-2.6.0/lib")

add_executable(${NAME} ${SOURCES})
target_link_libraries(
	${NAME}
	sfml-graphics
	sfml-window
	sfml-system
	GL GLU GLEW glfw
)