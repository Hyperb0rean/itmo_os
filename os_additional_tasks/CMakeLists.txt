cmake_minimum_required(VERSION 3.1...3.27)


project(
  os_additional_tasks
  VERSION 1.0
  LANGUAGES C)

set(CMAKE_C_FLAGS "-g -Werror -Wall -Wextra -pedantic -lpthread")


set(CMAKE_C_FLAGS_ASAN "-g -fsanitize=address -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=leak -fsanitize=undefined -fsanitize-address-use-after-scope"
                   CACHE STRING "Compiler flags in asan build"
                   FORCE)
                   
add_executable(buff_ch go_buffered_channel/main.c go_buffered_channel/chan.c go_buffered_channel/chan.h  go_buffered_channel/queue.h go_buffered_channel/queue.c) 
