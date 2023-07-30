cmake_minimum_required(VERSION 3.14)
project(
        Capp
        VERSION 0.1
        LANGUAGES CXX
)

# Required version >= 14
if (CMAKE_CXX_STANDARD LESS 14)
    message(FATAL_ERROR "CMAKE_CXX_STANDARD must be at least 14")
elseif (CMAKE_CXX_STANDARD EQUAL 14)
    message(STATUS "Using C++14")
else ()
    message(STATUS "Using C++17")
    set(CMAKE_CXX_STANDARD 17)
endif ()

# Prevent duplicate targets when relying on source code
if (TARGET ${PROJECT_NAME})
    message(WARNING "Target ${PROJECT_NAME} already exists!")
    return()
endif ()

file(GLOB SRC_CODEC "${PROJECT_SOURCE_DIR}/capp/codec/*.h" "${PROJECT_SOURCE_DIR}/capp/codec/*.cc")
file(GLOB SRC_UTIL "${PROJECT_SOURCE_DIR}/capp/util/*.h" "${PROJECT_SOURCE_DIR}/capp/util/*.cc")

# Get third-part
include(${PROJECT_SOURCE_DIR}/third-part/fetch.cmake)

add_library(${PROJECT_NAME} ${SRC_CODEC} ${SRC_UTIL})
target_link_libraries(${PROJECT_NAME} netpoll)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

if (ENABLE_CAPP_TEST)
    enable_testing()
    add_subdirectory(tests)
endif ()