include_directories(${PROJECT_SOURCE_DIR})

add_executable(chess main.cpp)

find_package(SDL2 REQUIRED)

# Link SDL2::Main, SDL2::Image and SDL2::GFX to our project
target_link_libraries(chess SDL2::Main)


add_subdirectory(ui)
target_link_libraries(chess UIModule)