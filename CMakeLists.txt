cmake_minimum_required(VERSION 3.1)

project(SmallTest)

include_directories(src)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SRC_DIR src)

set(TEST_SRC 
	${SRC_DIR}/main.cpp
	${SRC_DIR}/Tests.cpp
	${SRC_DIR}/TestSuite.cpp
	${SRC_DIR}/Console.cpp
	${SRC_DIR}/Result.cpp
)

set(LIB_TEST_SRC
	${SRC_DIR}/Tests.cpp
	${SRC_DIR}/TestSuite.cpp
	${SRC_DIR}/Console.cpp
	${SRC_DIR}/Result.cpp
)

add_executable(main ${TEST_SRC})

file(GLOB SOURCES ${LIB_TEST_SRC})
add_library(ldmtest SHARED ${SOURCES})
