include(${PROJECT_SOURCE_DIR}/cmake/add_executable_test.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/package_operate.cmake)

add_package(doctest https://gitee.com/acking-you/doctest.git origin/master)


add_executable_test_by_filename(test_netpoll.cc)

targets_link_package(netpoll test_netpoll)
#targets_link_package(doctest_with_main test_netpoll)
