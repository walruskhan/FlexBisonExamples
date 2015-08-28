cmake_minimum_required(VERSION 3.3)

find_package(FLEX)
find_package(BISON)
if (NOT ${FLEX_FOUND} OR NOT ${BISON_FOUND})
    message(FATAL_ERROR "Flex and/or Bison are not installed on this machine! (or cmake can't find them)")
endif (NOT ${FLEX_FOUND} OR NOT ${BISON_FOUND})
message(STATUS "Flex Version: ${FLEX_VERSION} Bison Version: ${BISON_VERSION}")

add_subdirectory(01_simple_lexer)