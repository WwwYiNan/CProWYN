cmake_minimum_required(VERSION 3.20)
project(CPro)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(CPro main.cpp)
add_executable(test Test1.cpp)
add_executable(d1 demo01.cpp)

add_executable(2  main_2.cpp)
add_executable(3  main_3.cpp)
add_executable(4  main_4.cpp)
#实验一
#add_executable(lab1  2021b32009/lab1_1.cpp)
#add_executable(lab2  2021b32009/lab1_2.cpp)
#add_executable(lab3 2021b32009/lab1_3.cpp)
#add_executable(lab4 2021b32009/lab1_4.cpp)
#栈
add_executable(zhan1 zhan/main.cpp)
add_executable(duilie zhan/duilie.cpp)
add_executable(duilie2 zhan/duilie2.cpp)

#串
add_executable(cuan1 cuan/main.cpp)

# Tree
add_executable(tree Tree/Tree.cpp)
add_executable(l31 Tree/lab3_01.cpp)
add_executable(l32 Tree/lab3_02.cpp)
add_executable(l33 Tree/lab3_03.cpp)
add_executable(btree Tree/bitree0.cpp)
add_executable(ttree Tree/Tree_test.cpp)