cmake_minimum_required(VERSION 3.20.2) 

project(space_traders_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

file(GLOB_RECURSE all_SRCS CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cc"
        )

add_library(${PROJECT_NAME} ${all_SRCS})

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /DCPPHTTPLIB_OPENSSL_SUPPORT /DJSON_ImplicitConversions=OFF)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -DCPPHTTPLIB_OPENSSL_SUPPORT -DJSON_ImplicitConversions=OFF)
endif()

find_package(OpenSSL COMPONENTS Crypto SSL REQUIRED)

# For this project
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
# For CPP-HTTPLIB
target_include_directories(${PROJECT_NAME} PUBLIC ./third_party)
# For JSON
target_include_directories(${PROJECT_NAME} PUBLIC ./third_party/json/single_include)

target_link_libraries(${PROJECT_NAME} PUBLIC OpenSSL::SSL OpenSSL::Crypto)
