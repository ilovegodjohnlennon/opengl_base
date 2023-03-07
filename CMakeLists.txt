cmake_minimum_required(VERSION 3.25)

project(gl_test)

add_executable(${PROJECT_NAME} src/main.cpp src/Window.cpp)


add_library(STB_IMAGE "libs/stb_image/stb_image.cpp")
add_library(GLAD "libs/glad/gl.c")


include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} -lglfw -lOpenGL STB_IMAGE GLAD)