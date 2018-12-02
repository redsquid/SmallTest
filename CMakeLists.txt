cmake_minimum_required(VERSION 3.1)

project(SmallTest VERSION 0.1)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SRC_DIR src)

set(TEST_SRC 
	${SRC_DIR}/main.cpp
)

add_executable(main ${TEST_SRC})

