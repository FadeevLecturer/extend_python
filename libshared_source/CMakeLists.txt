project(libshared)
cmake_minimum_required(VERSION 3.10)
include(GenerateExportHeader)
add_library(shared SHARED libshared.cpp)
