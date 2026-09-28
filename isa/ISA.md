# VPU ISA 1.0

Instructions are fixed 12-byte records: opcode (1), dst (1), src (1), flags (1), signed immediate (8, little-endian). Registers are R0-R7.

`MOV R0, 10` uses flags bit 0 for an immediate. Register-register MOV clears that bit. Arithmetic uses dst and src registers. Branch immediates are byte offsets into the program. LOAD/STORE use an immediate memory address. PUSH/POP use the dst register. HALT stops the core.
