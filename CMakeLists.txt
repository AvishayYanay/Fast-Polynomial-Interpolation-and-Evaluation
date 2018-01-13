cmake_minimum_required(VERSION 3.9)
project(mpeval)

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(/path_to_your_ntl/NTL/ntl-10.5.0/include)
add_executable(mpeval main.cpp utils_zp.h utils_zp.cpp tests_zp.h tests_zp.cpp utils_gf2n.cpp utils_gf2n.h tests_gf2n.cpp tests_gf2n.h)


target_link_libraries(mpeval /path_to_your_ntl/NTL/ntl-10.5.0/src/ntl.a)
target_link_libraries(mpeval gmp gmpxx)
