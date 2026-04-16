cmake_minimum_required(VERSION 3.10)
project(SpeechContestManagementSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含所有源文件
set(SOURCES
    演讲比赛流程管理系统.cpp
    speechManager.cpp
)

# 生成可执行文件
add_executable(speech_contest_management_system ${SOURCES})

# 确保头文件能够被正确包含
target_include_directories(speech_contest_management_system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
