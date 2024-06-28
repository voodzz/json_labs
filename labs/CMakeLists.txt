cmake_minimum_required(VERSION 3.27)
project(labs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(labs
        lab.cpp
        lab.h
        main.cpp
        readAndParse.cpp
        readAndParse.h
        FilesStorage.h
        FilesStorage.cpp
        FileName.cpp
        FileName.h
        Mains.h
        Mains.cpp
        #tests_for_labs/test.cc
)

include_directories(../../../side_libraries/nlohmann)

#target_link_libraries(
#        labs
#        GTest::gtest_main
#)