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

# For this project
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
# For CPP-HTTPLIB
target_include_directories(${PROJECT_NAME} PUBLIC ./third_party)
# For JSON
target_include_directories(${PROJECT_NAME} PUBLIC ./third_party/json/single_include)

target_link_libraries(${PROJECT_NAME} PUBLIC OpenSSL::SSL OpenSSL::Crypto)
