# API

Public declarations live under `include/vpu/`. `vpu_init` accepts an optional configuration, `vpu_shutdown` releases all owned allocations, and `vpu_core_get` obtains a configured virtual core. Register, memory, ALU, vector, task, queue, scheduler, decoder, and executor APIs return `vpu_status_t` values for invalid input and execution errors.
