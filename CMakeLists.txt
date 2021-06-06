# Cmake Options
cmake_minimum_required(VERSION 3.20.2)
project(ascpp++)

# CXX Options 
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

#Include subdirectories
#Error handling library 
add_subdirectory(exceptions)
#Preprocessor
add_subdirectory(preprocessor)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE preprocessor)
target_link_libraries(${PROJECT_NAME} PRIVATE exceptions)