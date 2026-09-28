.text
.globl vpu_arch_add_u64
.type vpu_arch_add_u64,@function
vpu_arch_add_u64:
    mov %rdi,%rax
    add %rsi,%rax
    ret
.globl vpu_arch_mul_u64
.type vpu_arch_mul_u64,@function
vpu_arch_mul_u64:
    mov %rdi,%rax
    imul %rsi,%rax
    ret
