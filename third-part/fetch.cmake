include(${PROJECT_SOURCE_DIR}/cmake/CPM.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/target_if_include.cmake)

set(fetch_root_path ${PROJECT_SOURCE_DIR}/third-part)

target_if_include(elog ${fetch_root_path}/netpoll-cpp/fetch_netpoll.cmake)