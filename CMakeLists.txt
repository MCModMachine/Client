#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 3.5)
#Name your project here
project(mcubed-client)

#This tells CMake to fib.c and name it fibonacci
add_executable(mcubed cli.cpp)

