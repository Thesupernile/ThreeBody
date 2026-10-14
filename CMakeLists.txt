cmake_minimum_required(VERSION 3.26.0)
project(ThreeBodySim VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(ThreeBodySim
    src/main.cpp
    src/glad.c    
)

target_include_directories(ThreeBodySim PRIVATE include)

target_link_libraries(ThreeBodySim ${GLFW3_LIBRARY} OpenGL::GL)
