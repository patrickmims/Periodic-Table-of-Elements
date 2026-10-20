cmake_minimum_required(VERSION 4.3)

project(main)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(SRC "src")

add_definitions(-w)

find_package(json-c CONFIG)
find_package(PkgConfig REQUIRED)

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

pkg_check_modules(MYSQLCLIENT REQUIRED mysqlclient)

add_executable(${PROJECT_NAME} 
    ${SRC}/libcurl/curl_http.c
    ${SRC}/main.c
    ${SRC}/process/process_wrapper.c
    ${SRC}/ssh/sftp/sftp.c
)

target_include_directories(main PRIVATE ${MYSQLCLIENT_INCLUDE_DIRS})
target_include_directories(main PRIVATE ${MYSQLCLIENT_CFLAGS_OTHER})

# target_link_libraries(main PRIVATE ${MYSQLCLIENT_LIBRARIES} -lcurl)
target_link_libraries(${PROJECT_NAME} PRIVATE
        -lcurl
        -ljson-c
        -lmariadb
        -lmysqlclient
        -lpthread
        json-c::json-c)
