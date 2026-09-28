.text
.global vpu_arch_memcpy8
vpu_arch_memcpy8:
 ldr x3,[x1]
 str x3,[x0]
 ret
