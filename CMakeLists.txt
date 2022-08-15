cmake_minimum_required(VERSION 3.21)
project(cink2 C)

set(CMAKE_C_STANDARD 99)

add_executable(cink2
        src/cink.c
        src/lib/data_strcut.h
        src/lib/service.h
        src/lib/ttl_.h
        src/lib/cmc_.h
        src/lib/cink.h
        )
