cmake_minimum_required(VERSION 3.8.2)
PROJECT (demo_h264_rkmedia)

add_definitions(-g -O0 -ggdb -gdwarf -funwind-tables -rdynamic)
add_definitions(-DDEBUG)

aux_source_directory(./ SRCS)
set(LIBS easymedia)

include_directories(${PROJECT_SOURCE_DIR}/include/easymedia)
include_directories(${PROJECT_SOURCE_DIR}/include/rkmedia)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} ${LIBS})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
