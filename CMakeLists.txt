cmake_minimum_required(VERSION 3.20.2) 

project(space_traders_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DCPPHTTPLIB_OPENSSL_SUPPORT -DJSON_ImplicitConversions=OFF")

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cc"
        )

add_library(${PROJECT_NAME} ${all_SRCS})

find_package(OpenSSL COMPONENTS Crypto SSL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ./include)
target_include_directories(${PROJECT_NAME} PRIVATE ./third_party)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
