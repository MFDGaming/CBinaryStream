cmake_minimum_required(VERSION 3.1)

project(CBinaryStream)

add_library(cbinarystream ${PROJECT_SOURCE_DIR}/src/binary_stream.c)
target_include_directories(cbinarystream PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(cbinarystream-test ${PROJECT_SOURCE_DIR}/tests/test.c)
target_link_libraries(cbinarystream-test cbinarystream)
