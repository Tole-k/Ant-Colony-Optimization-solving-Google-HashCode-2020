cmake_minimum_required (VERSION 3.11)
project(main
    LANGUAGES CXX
	VERSION 1.0.0
)

SET(GCC_COVERAGE_COMPILE_FLAGS "--static -O3")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_executable(${PROJECT_NAME} main.cpp library.cpp AntColonyOptimization.cpp book.h ant.cpp)
