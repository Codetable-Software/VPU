.text
.globl vpu_arch_memcpy8
.type vpu_arch_memcpy8,@function
vpu_arch_memcpy8:
    mov (%rsi),%rax
    mov %rax,(%rdi)
    ret
