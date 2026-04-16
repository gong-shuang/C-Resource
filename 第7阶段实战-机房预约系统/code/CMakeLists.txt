cmake_minimum_required(VERSION 3.10)
project(ComputerRoomReservationSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含所有源文件
set(SOURCES
    机房预约系统.cpp
    manager.cpp
    orderFile.cpp
    student.cpp
    teacher.cpp
)

# 生成可执行文件
add_executable(computer_room_reservation_system ${SOURCES})

# 确保头文件能够被正确包含
target_include_directories(computer_room_reservation_system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
