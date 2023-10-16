# List of file names
$files = @("0-reset_to_98.c", "1-swap.c", "2-strlen.c", "3-puts.c", "4-print_rev.c", "5-rev_string.c", "6-puts2.c", "7-puts_half.c", "8-print_array.c", "9-strcpy.c", "10-atoi.c", "11-keygen.c")

# Create main.h
$null > main.h

# Create README.md
@"
# 0x05. C - Pointers, arrays, and strings

This repository contains C programs created as part of the 0x05 project.

## Files
$($files -join [Environment]::NewLine)
"@ > README.md

# Create files and set permissions
foreach ($file in $files) {
    New-Item -Path $file -ItemType "file"
    Set-ItemProperty -Path $file -Name IsReadOnly -Value $false
}

Write-Host "Files and README.md created."
