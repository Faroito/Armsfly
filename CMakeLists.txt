cmake_minimum_required(VERSION 3.15)
project(Armsfly)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  SET( LINUX 1)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  SET( APPLE 1 )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  SET( WINDOWS 1)
endif()

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
find_library(GLFW3_LIBRARY glfw REQUIRED)

if(LINUX)
  find_path(GLEW_INCLUDE_DIR GL/glew.h)
  find_library(GLEW_LIBRARY GLEW glew REQUIRED)
endif(LINUX)

if (APPLE)
  include_directories(/usr/local/include)
  find_library(GLEW_LIBRARY glew REQUIRED)
  find_library(COCOA_LIBRARY Cocoa REQUIRED)
  find_library(IOKIT_LIBRARY IOKit REQUIRED)
  find_library(COREVID_LIBRARY CoreVideo REQUIRED)
endif (APPLE)

set(SOURCE_FILES)
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/librairies/)

add_executable(Armsfly ${SOURCE_FILES}
        source/gl_wrapper/App.cpp
        source/gl_wrapper/Window.cpp
        source/scene/Camera.cpp
        source/scene/Scene.cpp
        source/Main.cpp)

if (APPLE)
  target_link_libraries (Armsfly
          ${GLFW3_LIBRARY}
          ${OPENGL_LIBRARIES}
          ${GLEW_LIBRARY}
          ${COCOA_LIBRARY} ${COREVID_LIBRARY} ${IOKIT_LIBRARY})
endif (APPLE)

if (UNIX)
  target_link_libraries (Armsfly
          ${GLEW_LIBRARY}
          ${GLFW3_LIBRARY}
          ${OPENGL_LIBRARIES}
          pthread)
endif (UNIX)
