include_directories(${CMAKE_SOURCE_DIR}/firstLib/include)

add_executable(firstLibCall main.cpp)

target_link_libraries(firstLibCall firstLib)
