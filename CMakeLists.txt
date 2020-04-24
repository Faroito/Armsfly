cmake_minimum_required(VERSION 3.15)
project(Armsfly)
set(CMAKE_CXX_STANDARD 17)

set(GRAPHIC_NAME graphic)
set(OPENCV_NAME opencv)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  SET( LINUX 1)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  SET( APPLE 1 )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  SET( WINDOWS 1)
endif()

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
find_package (OpenCV REQUIRED)
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

include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/include/scene)
include_directories(${PROJECT_SOURCE_DIR}/include/gl_wrapper)
include_directories(${PROJECT_SOURCE_DIR}/librairies/)

add_executable(${GRAPHIC_NAME}
        source/gl_wrapper/App.cpp
        source/gl_wrapper/Window.cpp
        source/scene/Camera.cpp
        source/scene/Scene.cpp
        source/GraphicMain.cpp)
add_executable(${OPENCV_NAME}
        source/OpenCVMain.cpp)

target_compile_options(${GRAPHIC_NAME} PRIVATE -std=c++17)
target_compile_options(${OPENCV_NAME} PRIVATE -std=c++17)
target_compile_options(${GRAPHIC_NAME} PRIVATE -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic)
target_compile_options(${OPENCV_NAME} PRIVATE -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic)
target_compile_options(${GRAPHIC_NAME} PRIVATE -Wno-unused-parameter)
target_compile_options(${OPENCV_NAME} PRIVATE -Wno-unused-parameter)

if (GCC_VERSION VERSION_GREATER 7.0 OR GCC_VERSION VERSION_EQUAL 7.0)
  target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wduplicated-cond -Wduplicated-branche)
endif()

if (APPLE)
  target_link_libraries (${GRAPHIC_NAME}
          ${GLFW3_LIBRARY}
          ${OPENGL_LIBRARIES}
          ${GLEW_LIBRARY}
          ${COCOA_LIBRARY} ${COREVID_LIBRARY} ${IOKIT_LIBRARY})
  target_link_libraries (${OPENCV_NAME}
          ${OpenCV_LIBS}
          ${COCOA_LIBRARY} ${COREVID_LIBRARY} ${IOKIT_LIBRARY})
endif (APPLE)

if (LINUX)
  target_link_libraries (${GRAPHIC_NAME}
          ${GLEW_LIBRARY}
          ${GLFW3_LIBRARY}
          ${OPENGL_LIBRARIES}
          pthread)
  target_link_libraries (${OPENCV_NAME}
          ${OpenCV_LIBS}
          pthread)
endif (LINUX)
