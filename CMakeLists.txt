cmake_minimum_required(VERSION 3.8.2)
PROJECT (demo_h264_rkmedia)

add_definitions(-g -O0 -ggdb -gdwarf -funwind-tables -rdynamic)
add_definitions(-DDEBUG -DRKAIQ)

aux_source_directory(${PROJECT_SOURCE_DIR} SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/common COMMON_SRCS)
set(LIBS easymedia rkaiq)

#rkmedia
include_directories(${PROJECT_SOURCE_DIR}/include/easymedia)
include_directories(${PROJECT_SOURCE_DIR}/include/rkmedia)
# rkaiq
include_directories(${CMAKE_SYSROOT}/usr/include/rkaiq/algos)
include_directories(${CMAKE_SYSROOT}/usr/include/rkaiq/common)
include_directories(${CMAKE_SYSROOT}/usr/include/rkaiq/iq_parser)
include_directories(${CMAKE_SYSROOT}/usr/include/rkaiq/uAPI)
include_directories(${CMAKE_SYSROOT}/usr/include/rkaiq/xcore)

add_executable(${PROJECT_NAME} ${SRCS} ${COMMON_SRCS})
target_link_libraries(${PROJECT_NAME} ${LIBS})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
