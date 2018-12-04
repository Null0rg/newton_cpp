cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories ("src/main/")
set(BOOST_ROOT dependencies/boost_1_68_0/)

# tell CMake to run tests 
enable_testing()

# find Boost headers
find_package(Boost)
include_directories (${Boost_INCLUDE_DIRS})

# test files are stored in the src/test folder
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/test/*.cpp)

# for each source file in the src/test folder folder
foreach(TEST_FILE ${TEST_SRCS})

        # extract the file name without file extension
        # and store the result in TEST_NAME
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

        # add the compile target
        add_executable(${TEST_NAME} ${TEST_FILE})

        # put test binaries in bin_test folder
        set_target_properties(${TEST_NAME} PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/bin_test
        )

        # now add the test for test execution with
        # the working directory bin_test and the  
        # command being the test executable we just
        # built
        add_test(NAME ${TEST_NAME} 
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin_test
                 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin_test/${TEST_NAME}
        )

endforeach(TEST_FILE)