cmake_minimum_required(VERSION 3.18)

project(Problems
  VERSION 0.0.1
  HOMEPAGE_URL ${CODING_INTERVIEWS_HOMEPAGE_URL}
  LANGUAGES CXX
)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

###
### Variables
###
# set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
# set(HEADER_FILES ${CODINGINTERVIEWS_INCLUDE_DIR}/foo.hpp)

###
### Define library target
###
add_executable(${PROJECT_NAME}_BinarySearchTree ${CMAKE_CURRENT_SOURCE_DIR}/binary_search_tree.cpp)

target_include_directories(${PROJECT_NAME}_BinarySearchTree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CODINGINTERVIEWS_INCLUDE_DIR})

target_compile_options(${PROJECT_NAME}_BinarySearchTree PRIVATE -Werror -Wall -Wextra -pedantic)
