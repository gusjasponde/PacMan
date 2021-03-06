cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(PacManStandalone
  LANGUAGES CXX
)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(
  NAME cxxopts
  GITHUB_REPOSITORY jarro2783/cxxopts
  VERSION 2.2.0
  OPTIONS
    "CXXOPTS_BUILD_EXAMPLES Off"
    "CXXOPTS_BUILD_TESTS Off"
)

CPMAddPackage(
  NAME PacMan
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..
)

# ---- Create standalone executable ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(PacManStandalone ${sources})

set_target_properties(PacManStandalone PROPERTIES 
  CXX_STANDARD 17 
  OUTPUT_NAME "PacMan"
)

target_link_libraries(PacManStandalone PacMan cxxopts SDL2 SDL2_ttf SDL2_mixer glm)

# ---- Copy resources to build folder ----
FILE(COPY ../resources/ DESTINATION "${CMAKE_BINARY_DIR}/resources")