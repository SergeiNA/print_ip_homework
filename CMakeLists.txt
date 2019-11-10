cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 10000)
endif()

project(print_tp VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)



add_executable(print_ip main.cpp print_ip.h)

#add_library(filter_lib filter.cpp filter.h)

#add_executable(ip_filter_tests ip_filter_tests.cpp)

set_target_properties(print_ip PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

# set_target_properties(ip_filter_tests PROPERTIES
#     COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#     INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
# )

target_link_libraries(print_ip
    #filter_lib
    Threads::Threads
)

# target_link_libraries(ip_filter_tests
#     ${Boost_LIBRARIES}
#     filter_lib
# )

# install(TARGETS ip_filter RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set(CPACK_PACKAGE_CONTACT "SergeiNA at github.com")

# set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

# include(CPack)

# enable_testing()

# add_test(ip_filter_tests_all ip_filter_tests)
