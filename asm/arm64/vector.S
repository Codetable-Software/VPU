.text
.global vpu_arch_vec_add2
vpu_arch_vec_add2:
 ldr d0,[x0]
 ldr d1,[x1]
 fadd d0,d0,d1
 str d0,[x2]
 ret
