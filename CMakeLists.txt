cmake_minimum_required(VERSION 3.20)

project(qvtkopengl)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON) 

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6OpenGL REQUIRED)

find_package(VTK REQUIRED)

include_directories(${VTK_INCLUDE_DIRS})
link_directories(${VTK_LIBRARY_DIRS})


# include_directories(${GLEW_INCLUDE_DIR})
# link_directories(${GLEW_LIBRARY})

add_executable(qvtkopengl main.cpp QVTKOpenGLWindow.h QVTKOpenGLWindow.cpp)

target_link_libraries(qvtkopengl 
    ${VTK_LIBRARIES}
    ${QT_LIBRARIES}
    ${OPENGL_LIBRARIES}
    Qt6::Widgets)
