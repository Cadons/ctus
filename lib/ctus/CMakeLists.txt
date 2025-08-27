# Include common cmake scripts
include(${CMAKE_CURRENT_SOURCE_DIR}/.cmake/sources.cmake)
show_module_info(${CMAKE_CURRENT_LIST_DIR}/package.json)

# Configure build output directories for the target
configure_build(ctus)

# Create executable target
if(BUILD_SHARED_LIBS)
add_library(ctus SHARED ${CTUS_SOURCES} ${CTUS_HEADERS} ${CTUS_RESOURCES})
else()
    add_library(ctus STATIC ${CTUS_SOURCES} ${CTUS_HEADERS} ${CTUS_RESOURCES})
endif()

# Include headers directory
target_include_directories(ctus PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/ctus>
        $<INSTALL_INTERFACE:include/ctus>)

# Link libraries
target_link_libraries(ctus PUBLIC CURL::libcurl Boost::uuid Boost::lexical_cast nlohmann_json::nlohmann_json glog::glog fmt::fmt)
if(BUILD_SHARED_LIBS)
    target_compile_definitions(ctus PRIVATE CTUS_EXPORTS)
    target_compile_definitions(ctus PRIVATE CTUS_SHARED)
endif ()
# Enable testing if tests exist
include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()
# Install target
configure_install(ctus)
#For destribution, we need to create a config file for the package
include(CMakePackageConfigHelpers)
configure_package_config_file(
        "${CMAKE_SOURCE_DIR}/cmake/ctusConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/ctusConfig.cmake"
        INSTALL_DESTINATION lib/cmake/ctus
        NO_SET_AND_CHECK_MACRO
        NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ctusConfig.cmake"
        DESTINATION lib/cmake/ctus)