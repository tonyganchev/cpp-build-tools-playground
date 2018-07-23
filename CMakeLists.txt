cmake_minimum_required (VERSION 2.6)

project(server)

set(server_VERSION_MAJOR 1)
set(server_VERSION_MINOR 0)
configure_file(
	"${PROJECT_SOURCE_DIR}/server_config.hpp.in"
	"${PROJECT_BINARY_DIR}/server_config.hpp")

include_directories("${PROJECT_BINARY_DIR}")

find_package(cpprestsdk CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

add_executable(server main.cpp)

target_link_libraries(
	server PRIVATE cpprestsdk::cpprest
	               cpprestsdk::cpprestsdk_zlib_internal
	               cpprestsdk::cpprestsdk_boost_internal
	               cpprestsdk::cpprestsdk_openssl_internal
	               ZLIB::ZLIB
	               OpenSSL::SSL
	               Boost::system)
