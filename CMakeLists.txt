cmake_minimum_required(VERSION 3.18)

set(CODING_INTERVIEWS_HOMEPAGE_URL "https://github.com/pseigo/coding-interviews")

project(CodingInterviews
  VERSION 0.0.1
  DESCRIPTION "Data structures, standard algorithms, and coding problems"
  HOMEPAGE_URL ${CODING_INTERVIEWS_HOMEPAGE_URL}
  LANGUAGES CXX
)

# Public header files
set(CODINGINTERVIEWS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/coding_interviews)

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
  message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# Only run if this is the main project (i.e., not added via add_subdirectory)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF) # Ensure -std=c++xx instead of -std=g++xx

  # Support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

###
### Projects
###
add_subdirectory(src/algorithms)
add_subdirectory(src/data_structures)
add_subdirectory(src/problems)
