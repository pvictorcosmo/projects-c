cmake_minimum_required(VERSION 3.23)
project(AV2_2022_22_ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AV2_2022_22_
        init.c
        init.h
        main.c
        pet.c
        pet.h
        user.c
        user.h)
