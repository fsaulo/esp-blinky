cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
 set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

list(APPEND EXTRA_COMPONENT_DIRS hal source)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(blink)
