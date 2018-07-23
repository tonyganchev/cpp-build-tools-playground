cmake_minimum_required (VERSION 2.6)
project(server)
set(server_VERSION_MAJOR 1)
set(server_VERSION_MINOR 0)
configure_file(
	"${PROJECT_SOURCE_DIR}/server_config.hpp.in"
	"${PROJECT_BINARY_DIR}/server_config.hpp")
include_directories("${PROJECT_BINARY_DIR}")
add_executable(server main.cpp)