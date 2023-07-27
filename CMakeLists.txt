cmake_minimum_required(VERSION 3.20.2) 

include(FetchContent)

project(space_traders_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

##
## MAIN_PROJECT CHECK
## determine if nlohmann_json is built as a subproject (using add_subdirectory) or if it is the main project
##
set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

if(${MAIN_PROJECT})
    set(ENABLE_SPACE_TRADERS_CPP_TESTING_Init ON)
else()
    set(ENABLE_SPACE_TRADERS_CPP_TESTING_Init OFF)
endif()

option(ENABLE_SPACE_TRADERS_CPP_TESTING                     "Build the unit tests when ENABLE_SPACE_TRADERS_CPP_TESTING is enabled." ${ENABLE_SPACE_TRADERS_CPP_TESTING_Init})

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cc"
        )
add_library(${PROJECT_NAME} ${SRC_FILES})

find_package(OpenSSL COMPONENTS Crypto SSL REQUIRED)

add_subdirectory(./third_party/cpp-httplib)
add_subdirectory(./third_party/date)
add_subdirectory(./third_party/json)

target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenSSL::SSL OpenSSL::Crypto httplib::httplib date::date nlohmann_json::nlohmann_json)

add_compile_definitions(CPPHTTPLIB_OPENSSL_SUPPORT JSON_ImplicitConversions=OFF)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic )
endif()

if(ENABLE_SPACE_TRADERS_CPP_TESTING)
  FetchContent_Declare(
    googletest
    URL https://api.github.com/repos/google/googletest/zipball/v1.13.0
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing()
  file(GLOB_RECURSE TEST_SRC_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/test/include/*.h" "${PROJECT_SOURCE_DIR}/test/*.cc")
  add_executable(space_traders_cpp_test ${TEST_SRC_FILES})
  target_link_libraries(space_traders_cpp_test GTest::gtest_main GTest::gmock_main)
  target_link_libraries(space_traders_cpp_test ${PROJECT_NAME})
  target_include_directories(space_traders_cpp_test PRIVATE ./test/include)
  include(GoogleTest)
  gtest_discover_tests(space_traders_cpp_test)
endif()