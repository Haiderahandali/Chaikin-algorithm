cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Test)

add_executable(App src/main.cpp
src/InputHandler.cpp
src/Vector.cpp
src/Window.cpp
src/LinkedList.cpp
src/curveDraw.cpp)

add_custom_command(TARGET App POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_SOURCE_DIR}/build/compile_commands.json
	${CMAKE_SOURCE_DIR}
	)

target_include_directories(App PRIVATE /usr/local/include/)
target_include_directories(App PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(App PUBLIC -Wall -Wextra -Wpedantic -Werror)

add_library(DEPS INTERFACE)

find_library(SDL2 NAMES SDL2 PATHS /usr/local/lib REQUIRED)
find_library(SDL2main NAMES SDL2main PATHS /usr/local/lib REQUIRED)
find_library(SDL2_image NAMES SDL2_image PATHS /usr/local/lib REQUIRED)
find_library(SDL2_ttf NAMES SDL2_ttf PATHS /usr/local/lib REQUIRED)

target_link_libraries(DEPS  INTERFACE ${SDL2main} INTERFACE ${SDL2} INTERFACE ${SDL2_image} INTERFACE ${SDL2_ttf})
set_target_properties(App PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug/ RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release/)

target_link_libraries(App PRIVATE DEPS)

