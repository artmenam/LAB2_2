cmake_minimum_required(VERSION 3.23)
project(LAB2_2)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")


add_executable(LAB2_2 main.cpp DynamicArray.h LinkedList.h Sequence.h SequenceArray.h SequenceLinkedList.h test.cpp test.h)
