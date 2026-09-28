# VPU — Virtual Processing Unit

VPU 1.0.0 is a small, embeddable virtual processing engine written primarily in C. It provides virtual cores, registers, flags, an ALU, vector operations, bounded virtual memory, cache/buffer primitives, a fixed-width instruction format, decoder/executor, task queue, scheduler, runtime dispatch, a C++ compute layer, Rust FFI helpers, and a Go cgo wrapper.

VPU is not an operating system, CPU emulator, or GPU. Its ISA is an application-level execution format interpreted by the VPU core.

## Build

C/C++/ASM:

```sh
cmake -S . -B build-cmake
cmake --build build-cmake
ctest --test-dir build-cmake --output-on-failure
```

Or:

```sh
make
make test
```

Rust uses the C static library produced by the C build:

```sh
cargo build
cargo test
```

Go uses cgo and the C static library. Build the C library first, then:

```sh
cd go && go build ./... && go test ./...
```

## Tools

`vpu-info` reports the default runtime configuration. `vpu-as` assembles the textual ISA into 12-byte instructions. `vpu-dump` decodes bytecode, and `vpu-run` executes it.

Example source:

```asm
MOV R0, 10
MOV R1, 20
ADD R0, R1
HALT
```

## Design

A core has R0-R7, PC, SP, FLAGS, and IR. Memory is bounded and explicitly allocated. Instructions use little-endian signed immediates and fixed 12-byte records. Tasks execute through function pointers and are tracked through READY/RUNNING/DONE/FAILED states.
