cmake_minimum_required(VERSION 3.16)
project(leetcode)

# 当前编译器ID
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

# 设置 C++14 标准
set(CMAKE_CXX_STANDARD 14)

# 使用Visual Studio编译额外的修改
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # MSVC默认以MD(多线程DLL)动态链接库文件，不适合本项目，替换MD为MT（多线程静态）
    set(CompilerFlags
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
            )
    foreach (CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach ()
    # 指定编译器的标准一致性模式(支持关键词：and or not)
    add_compile_options(/permissive-)
    # 指定代码文件编码格式为utf-8 (无BOM)
    add_compile_options(/utf-8)
endif ()

# 启用对此目录及子目录的测试，该命令应位于源目录的根目录中
enable_testing()

# 启动自下载
include(FetchContent)
set(GOOGLETEST "/home/sj/googletest/build/lib")
link_directories(GOOGLETEST)
include_directories("/home/sj/googletest/googletest/include")
# FetchContent获取GTest
message(STATUS "3rd-party: start fetch GoogleTest...")
FetchContent_Declare(googletest GIT_REPOSITORY https://hub.fastgit.org/google/googletest.git)   # 镜像站加速
set(INSTALL_GTEST ON)       # 不安装GTest
FetchContent_MakeAvailable(googletest)
message(STATUS "3rd-party: fetch GoogleTest success!")

# git获取Google benchmark
message(STATUS "3rd-party: start fetch Google benchmark...")
FetchContent_Declare(benchmark GIT_REPOSITORY https://hub.fastgit.org/google/benchmark.git)     # 镜像站加速
set(BENCHMARK_ENABLE_TESTING OFF)       # 不编译benchmark测试项
set(BENCHMARK_ENABLE_INSTALL OFF)       # 不安装benchmark
FetchContent_MakeAvailable(benchmark)
message(STATUS "3rd-party: fetch Google benchmark success!")

# 引入build-in依赖
include_directories(editor/cn/build-in)
add_subdirectory(editor/cn/build-in)

# 生成所有子目录到变量 SUBDIRS
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR}/editor/cn ${CMAKE_CURRENT_LIST_DIR}/editor/cn/*-test)
# 遍历所有子目录，如果子目录下存在 CMakeLists.txt 文件，add_subdirectory
foreach (SUBDIR ${SUBDIRS})
    # 检测test代码
    if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/editor/cn/${SUBDIR}/${SUBDIR}.cpp)
        message(STATUS "found target: ${SUBDIR}")
        # 编译test代码
        add_executable(${SUBDIR}-test ${CMAKE_CURRENT_LIST_DIR}/editor/cn/${SUBDIR}/${SUBDIR}.cpp)
        # 链接ASan库
        target_compile_options(${SUBDIR}-test PRIVATE -fsanitize=address)
        target_link_options(${SUBDIR}-test PRIVATE -fsanitize=address)
        # 链接built-in库依赖
        target_link_libraries(${SUBDIR}-test built-in)
        # 链接Gtest库依赖
        target_link_libraries(${SUBDIR}-test gtest_main)
        target_link_libraries(${SUBDIR}-test gtest)
        target_link_libraries(${SUBDIR}-test pthread)
        # 运行test测试
        add_test(${SUBDIR}-test ${SUBDIR})
    endif ()
    # 检测benchmark代码
    if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/${SUBDIR}-benchmark.cpp)
        # 编译benchmark代码
        add_executable(${SUBDIR}-benchmark ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/${SUBDIR}-benchmark.cpp editor/cn/header.h editor/cn/seat-test.cpp editor/cn/biweek64-test.cpp editor/cn/week65-test.cpp editor/cn/week266-test.cpp editor/cn/biweek65-test.cpp editor/cn/meituan-test.cpp
                editor/cigen.cpp
                editor/cigen.h)
        # 链接built-in库
#        target_link_libraries(${SUBDIR}-benchmark built-in)
        # 链接benchmark库
        target_link_libraries(${SUBDIR}-benchmark benchmark_main ${CMAKE_USE_PTHREADS_INIT})
        # 运行benchmark测试
        add_test(${SUBDIR}-benchmark ${SUBDIR}-benchmark)
    endif ()
endforeach ()



#include_directories(editor)
#
#add_executable(leetcode
#        editor/cn/AddTwoNumbers.cpp
#        editor/cn/LongestSubstringWithoutRepeatingCharacters.cpp
#        editor/cn/TwoSum.cpp)
