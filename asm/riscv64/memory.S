.text
.globl vpu_arch_memcpy8
vpu_arch_memcpy8:
 ld t0,0(a1)
 sd t0,0(a0)
 ret
