<<<<<<<<<<<<<<  ✨ Codeium Command ⭐ >>>>>>>>>>>>>>>>
section .data
    format db 'Hello, Holberton', 0

section .text
    global _start

_start:
    ; call printf function
    push format
    call printf
    add esp, 4

    ; exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80
<<<<<<<  6b56bce2-3662-4d5d-990c-3e25818f1712  >>>>>>>