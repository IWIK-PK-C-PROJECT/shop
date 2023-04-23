cmake_minimum_required(VERSION 3.24)
project(shop_app)

set(CMAKE_CXX_STANDARD 23)


file(
        GLOB_RECURSE sources
        LIST_DIRECTORIES true
        CONFIGURE_DEPENDS true
        "src/*.cpp"
)

add_executable(
        ${CMAKE_PROJECT_NAME}_executable
        ${sources}
)