cmake_minimum_required(VERSION 3.5)

add_subdirectory(Core)

# Core root path
target_include_directories(Core_LIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
