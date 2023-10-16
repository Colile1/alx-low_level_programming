#!/bin/bash

# List of file names
files=("0-reset_to_98.c" "1-swap.c" "2-strlen.c" "3-puts.c" "4-print_rev.c" "5-rev_string.c" "6-puts2.c" "7-puts_half.c" "8-print_array.c" "9-strcpy.c" "10-atoi.c" "11-keygen.c")

# Create main.h
echo "" > main.h

# Create README.md
echo "# 0x05. C - Pointers, arrays, and strings" > README.md
echo "" >> README.md
echo "This repository contains C programs created as part of the 0x05 project." >> README.md
echo "" >> README.md
echo "## Files" >> README.md
echo "" >> README.md
for file in "${files[@]}"
do
    touch "$file"
    echo "- $file" >> README.md
done

# Set permissions
for file in "${files[@]}"
do
    chmod 664 "$file"
done

echo "Files and README.md created."
