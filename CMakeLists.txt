### 项目启动教程
# sudo apt install g++ cmake
# git clone xxx_github_url
# cd xxx_project/build
# cmake ..
# make
# cd ../bin && ./main

####################

# cmake最低配置版本
cmake_minimum_required(VERSION 2.8)

# 项目名称 && 使用语言
project(demo CXX)

# 指定头文件地址
include_directories(include)

# 宏定义源文件地址
aux_source_directory(src SRC_LIST)

# elf 文件存放位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 主函数名称 与 源文件地址
add_executable(main ${SRC_LIST})

# 添加编译选项
add_compile_options(-Wall -O3 -std=c++17)
