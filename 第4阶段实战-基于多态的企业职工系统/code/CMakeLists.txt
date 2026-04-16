cmake_minimum_required(VERSION 3.10)
project(EmployeeManagementSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含所有源文件
set(SOURCES
    基于多态的职工管理系统.cpp
    workerManager.cpp
    employee.cpp
    manager.cpp
    boss.cpp
)

# 生成可执行文件
add_executable(employee_management_system ${SOURCES})

# 确保头文件能够被正确包含
target_include_directories(employee_management_system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
