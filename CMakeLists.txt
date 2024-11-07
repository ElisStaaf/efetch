cmake_minimum_required(VERSION 3.14...3.22)

project(
  "efetch"
  VERSION 1.0.0
  LANGUAGES CXX
)
set(SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/usr/bin")

add_executable("efetch" ${SOURCE_FILES})
install(
    TARGETS "efetch"
    DESTINATION "/usr/bin"
)
