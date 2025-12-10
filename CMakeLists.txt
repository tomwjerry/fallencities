cmake_minimum_required(VERSION 3.23)

project(FallenCities)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(unofficial-uwebsockets CONFIG REQUIRED)

if(CMAKE_CXX_BYTE_ORDER STREQUAL "BIG_ENDIAN")
    add_compile_definitions(BIG_ENDIAN=TRUE)
else()
    add_compile_definitions(BIG_ENDIAN=FALSE)
endif()

add_executable(FallenCities)

target_compile_features(FallenCities PRIVATE cxx_std_17)

target_compile_definitions(FallenCities PUBLIC UWS_NO_ZLIB=1)

target_include_directories(FallenCities PRIVATE flecs/distr)
target_include_directories(FallenCities PRIVATE uWebSockets/src)
target_include_directories(FallenCities PRIVATE uWebSockets/uSockets/src)

target_link_directories(FallenCities PRIVATE libuv-1.x/build/Debug)

target_sources(FallenCities
  PRIVATE
    flecs/distr/flecs.c
    src/Networker/Networker.cpp
    src/main.cpp
)

target_link_libraries(FallenCities PRIVATE unofficial::uwebsockets::uwebsockets)
