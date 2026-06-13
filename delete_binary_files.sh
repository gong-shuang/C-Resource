#!/bin/bash

# 递归删除当前目录及其子目录中的C++编译生成的可执行文件

dir=$(pwd)
echo "当前目录: $dir"
echo "正在扫描C++编译生成的可执行文件..."
echo ""

deleted_count=0
total_size=0

# C++ 编译生成的可执行文件类型：
#   - 有执行权限的普通文件（排除脚本文件 .sh/.py/.pl 等）
#   - .o   - 目标文件
#   - .a   - 静态库
#   - .so  - 动态库
#   - .out - 可执行文件

while IFS= read -r -d '' file; do
    # 获取文件大小
    size=$(stat -c%s "$file" 2>/dev/null || stat -f%z "$file" 2>/dev/null)
    
    echo "删除: $file"
    echo "  大小: $size 字节"
    
    # 删除文件
    if rm -f "$file"; then
        echo "  ✓ 删除成功"
        ((deleted_count++))
        ((total_size+=size))
    else
        echo "  ✗ 删除失败"
    fi
    
    echo ""
done < <(find "$dir" -type f \( \
    -executable -not \( -name "*.sh" -o -name "*.py" -o -name "*.pl" -o -name "*.rb" -o -name "*.lua" -o -name "*.php" \) \
    -o -name "*.o" \
    -o -name "*.a" \
    -o -name "*.so" \
    -o -name "*.out" \
    \) -print0)

echo "=============================="
echo "处理完成！"
echo "删除文件数: $deleted_count"
echo "释放空间: $total_size 字节 ($(echo "scale=2; $total_size/1024" | bc) KB)"
