cmake_minimum_required(VERSION 3.15)
project(linkedlist_c C)

set(CMAKE_C_STANDARD 99)

add_library(linkedlist linkedlist.c linkedlist.h)