project(01_Simple_Lexer)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DUSE_FILES")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/testinput.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

FLEX_TARGET(SIMPLE_LEXER simple.l ${CMAKE_CURRENT_BINARY_DIR}/simple_scanner.c COMPILE_FLAGS "-d")
add_executable(SimpleLexer main.cpp ${FLEX_SIMPLE_LEXER_OUTPUTS})