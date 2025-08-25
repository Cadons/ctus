include(${CMAKE_CURRENT_SOURCE_DIR}/../.cmake/sources.cmake)
#Find GoogleTest package
find_package(GTest REQUIRED)

configure_build(CTUS_test)
find_package(GTest REQUIRED)#GoogleTest package inclusion
find_package(libzippp REQUIRED)
# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include/
)

# Add test executable

# Use the modified copies
add_executable(CTUS_test ${CTUS_TEST_SOURCES})
# Link libraries
target_link_libraries(CTUS_test PRIVATE GTest::GTest GTest::gmock libzippp::libzippp ctus)

#auto discover tests
gtest_discover_tests(CTUS_test
    DISCOVERY_TIMEOUT 60
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
