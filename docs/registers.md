# Registers

R0-R7 are 64-bit general-purpose registers. PC is a byte offset into the current program, SP is a byte address into the virtual memory stack region, FLAGS contains ZERO/NEGATIVE/CARRY/OVERFLOW bits, and IR stores the last decoded opcode. Register access rejects invalid GPR indices.
