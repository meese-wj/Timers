add_library(timer_base STATIC
            timer_base.cpp)

set(install_lib_name "TimerBase")
set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${install_lib_name})
message(STATUS "CMake Install Location: ${CMAKE_INSTALL_PREFIX}")

# Define some cache variables
include(GNUInstallDirs)

target_include_directories(timer_base PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

# Export this library for future use
install(TARGETS timer_base
        EXPORT  ${install_lib_name}
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(FILES timer_base.hpp DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(EXPORT ${install_lib_name} 
        FILE   "${install_lib_name}Targets.cmake" 
        NAMESPACE "${install_lib_name}::"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${install_lib_name}")

# Add config helpers
include(CMakePackageConfigHelpers)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/${install_lib_name}Config.cmake.in" 
                              "${CMAKE_CURRENT_BINARY_DIR}/${install_lib_name}Config.cmake" 
                              INSTALL_DESTINATION 
                              "${CMAKE_INSTALL_LIBDIR}/cmake/${install_lib_name}")

install(FILES 
        "${CMAKE_CURRENT_BINARY_DIR}/${install_lib_name}Config.cmake" 
        "${CMAKE_CURRENT_BINARY_DIR}/${install_lib_name}ConfigVersion.cmake" 
        DESTINATION 
        "${CMAKE_INSTALL_LIBDIR}/cmake/${install_lib_name}")

# Create a Package Version 
set(version 1.0)

set_property(TARGET timer_base PROPERTY VERSION ${version})
set_property(TARGET timer_base PROPERTY SOVERSION 1)
set_property(TARGET timer_base PROPERTY INTERFACE_timer_base_MAJOR_VERSION 1)
set_property(TARGET timer_base APPEND PROPERTY 
             COMPATIBLE_INTERFACE_STRING timer_base_MAJOR_VERSION)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/${install_lib_name}ConfigVersion.cmake"
                                 VERSION ${version}
                                 COMPATIBILITY AnyNewerVersion)

