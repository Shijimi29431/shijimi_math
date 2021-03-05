cmake_minimum_required(VERSION 3.9)


enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(shijimi_math)
enable_testing()

# build type
if(NOT DEFINED CMAKE_BUILD_TYPE )
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT DEFINED CMAKE_BUILD_TYPE )

option(BUILD_TESTS "If true shijimi_math's tests will be built" TRUE)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -W -Wall -Wextra -Wno-unused-parameter -pedantic")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
endif()


# find_package( Boost 1.75.0 REQUIRED )
# if( NOT Boost_FOUND )
#     message( SEND_ERROR "Required package Boost was not detected." )
# endif (NOT Boost_FOUND)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS} )

link_directories( ${Boost_LIBRARY_DIRS} )

subdirs(example)

if( ${BUILD_TESTS} )
  subdirs(test)
endif( ${BUILD_TESTS} )
