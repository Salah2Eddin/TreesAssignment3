cmake_minimum_required(VERSION 3.24)
project(Heap)

set(CMAKE_CXX_STANDARD 23)

add_executable(Heap main.cpp MinHeap.cpp MinHeap.h Student.h StudentsTreesProgram.h Student.cpp MaxHeap.cpp MaxHeap.h BST.cpp BST.h AVL.cpp AVL.h)
