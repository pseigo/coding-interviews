cmake_minimum_required(VERSION 3.18)

project(DataStructures
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
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(HEADER_FILES ${CODINGINTERVIEWS_INCLUDE_DIR}/deque.hpp)

###
### Define library target
###
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
add_executable(${PROJECT_NAME}_Deque deque.cpp ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CODINGINTERVIEWS_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME}_Deque PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CODINGINTERVIEWS_INCLUDE_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
