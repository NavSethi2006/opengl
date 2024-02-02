cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 1.0)

file(GLOB TARGET_SRC "./src/*.c")


add_executable(main ${TARGET_SRC})
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include/)  


target_link_libraries(main -lm -ldl -lpthread -lX11 -lXrandr -lglfw -lGL -lGLU -lglut
                            ${CMAKE_SOURCE_DIR}/lib/libcglm.so)

 
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/includes/)