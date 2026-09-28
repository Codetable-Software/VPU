.text
.globl vpu_arch_vec_add2
.type vpu_arch_vec_add2,@function
vpu_arch_vec_add2:
    movsd (%rdi),%xmm0
    addsd (%rsi),%xmm0
    movsd %xmm0,(%rdx)
    ret
