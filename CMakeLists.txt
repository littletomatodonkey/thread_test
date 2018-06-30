cmake_minimum_required(VERSION 2.8)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

# else can not fin nullptr and so on.
set (CMAKE_CXX_STANDARD 11)

#project name
project(thread_test)

#debug
set(CMAKE_BUILD_TYPE debug )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -march=native -fopenmp -g2 -ggdb -lpthread")

# thread_create
set( EXE_NAME thread_create_test )
set(APP_SRC thread_create.cpp)
add_executable(${EXE_NAME} ${APP_SRC} )
target_link_libraries(${EXE_NAME})

# thread_with_params
set( EXE_NAME thread_with_params )
set(APP_SRC thread_with_params.cpp)
add_executable(${EXE_NAME} ${APP_SRC} )
target_link_libraries(${EXE_NAME})

# thread with return value
set( EXE_NAME thread_with_ret )
set(APP_SRC thread_with_ret.cpp)
add_executable(${EXE_NAME} ${APP_SRC} )
target_link_libraries(${EXE_NAME})

set( EXE_NAME thread_with_info )
set(APP_SRC thread_with_info.cpp)
add_executable(${EXE_NAME} ${APP_SRC} )
target_link_libraries(${EXE_NAME})