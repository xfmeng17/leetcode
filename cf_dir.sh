#!/bin/bash
set -xeuo pipefail

# 检查是否提供了目录参数
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi
# 检查提供的路径是否是一个目录
if [ ! -d "$1" ]; then
    echo "Error: $1 is not a directory"
    exit 1
fi
# 查找所有 .h, .cc, 和 .cpp 文件，排除 .pb.h 和 .pb.cc 文件
# 并使用 clang-format -style=file 格式化这些文件
find "$1" -type f \( -name "*.h" -o -name "*.cc" -o -name "*.cpp" \) \
     -not \( -name "*.pb.h" -o -name "*.pb.cc∑" \) \
     -exec clang-format -style=file -i {} +
echo "clang-format completed..."