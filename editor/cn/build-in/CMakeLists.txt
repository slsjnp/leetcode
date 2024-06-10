cmake_minimum_required(VERSION 3.16)

# 获取当前目录到变量 CURRENT_FOLDER
string(REGEX REPLACE ".*/\(.*\)" "\\1" CURRENT_FOLDER ../doc)

# project名
project(${CURRENT_FOLDER})

# 设置 C 标准
set(CMAKE_CXX_STANDARD 14)

# 将.（当前文件夹）下编译用的源文件添加到一个宏列表中
aux_source_directory(../build-in DIR_BUILT_IN_SRCS)

# 将指定的源文件生成链接文件，然后添加到工程中
add_library(built-in STATIC ${DIR_BUILT_IN_SRCS})

#aux_source_directory(. EXECUTABLE)
#foreach(T_FILE_NAME ${EXECUTABLE})
#    get_filename_component(EXECUTABLE_NAME ${T_FILE_NAME} NAME_WE)
#    message(${EXECUTABLE_NAME})
#    add_executable(${EXECUTABLE_NAME} ${T_FILE_NAME})
#    target_link_libraries(
#            ${EXECUTABLE_NAME}
#            PRIVATE
#            leetcode
#            ${CMAKE_THREAD_LIBS_INIT}
#            GTest::GTest
#            GTest::Main
#    )
##    gtest_discover_tests(${EXECUTABLE_NAME})
#endforeach()