section .data
    hello db 'Hello, world!', 0

section .text
    global _start

_start:
    ; write syscall
    mov edi, 1
    mov rsi, hello
    mov rdx, 13
    mov rax, 1
    syscall

    ; exit syscall
    xor rdi, rdi
    mov rax, 60
    syscall
