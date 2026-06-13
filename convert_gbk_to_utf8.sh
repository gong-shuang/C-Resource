#!/bin/bash

# 递归检查当前目录及其子目录中所有C++文件的编码
# 如果是 GBK/GB2312 编码，则转换为 UTF-8

dir=$(pwd)
echo "当前目录: $dir"
echo "正在扫描所有C++文件（.cpp, .h, .hpp, .cxx, .cc）..."
echo ""

converted_count=0
skipped_count=0

# 使用 find 递归查找所有C++文件
while IFS= read -r -d '' file; do
    # 使用 file 命令检测文件编码
    encoding=$(file -i "$file" | grep -o "charset=[^ ]*" | cut -d= -f2)
    
    echo "文件: $file"
    echo "  原始编码: $encoding"
    
    # 检查是否为 GBK/GB2312 编码
    if echo "$encoding" | grep -qiE "(gbk|gb2312|iso-8859-1|unknown-8bit)"; then
        echo "  需要转换为 UTF-8..."
        
        # 创建临时文件
        temp_file=$(mktemp)
        
        # 使用 iconv 转换编码
        if iconv -f GBK -t UTF-8 "$file" -o "$temp_file"; then
            # 覆盖原文件
            mv "$temp_file" "$file"
            echo "  ✓ 转换成功"
            
            # 验证转换后的编码
            new_encoding=$(file -i "$file" | grep -o "charset=[^ ]*" | cut -d= -f2)
            echo "  转换后编码: $new_encoding"
            ((converted_count++))
        else
            echo "  ✗ 转换失败"
            rm -f "$temp_file"
        fi
    else
        echo "  无需转换 (已为 UTF-8 或其他编码)"
        ((skipped_count++))
    fi
    
    echo ""
done < <(find "$dir" -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" -o -name "*.cxx" -o -name "*.cc" \) -print0)

echo "=============================="
echo "处理完成！"
echo "转换文件数: $converted_count"
echo "跳过文件数: $skipped_count"
