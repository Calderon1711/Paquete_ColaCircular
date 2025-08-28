cmake_minimum_required(VERSION 3.30)
project(ColaCircular)

set(CMAKE_CXX_STANDARD 20)

add_executable(ColaCircular main.cpp
        Paquete.h
        ColaCircular.h
        ColaEspera.h)
