cmake_minimum_required(VERSION 3.5)

set(srcs_posix posix/ual_posix.c
                posix/ual_mutex.c
                posix/ual_memory.c
                posix/ual_wdt.c
                posix/ual_task.c)

project(ual)

add_library(ual STATIC ${srcs_posix})
target_include_directories(ual PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ual PUBLIC pthread)

add_subdirectory(example)
