# Instruction set

The ISA contains NOP, MOV, LOAD, STORE, ADD, SUB, MUL, DIV, MOD, AND, OR, XOR, NOT, SHL, SHR, CMP, JMP, JE, JNE, JG, JL, PUSH, POP, CALL, RET, and HALT. Encoding is exactly 12 bytes: one-byte opcode, destination, source, flags, then an eight-byte little-endian signed immediate. Branch targets are byte offsets. `MOV R0, 10` encodes an immediate flag; `MOV R0, R1` uses a register source.
