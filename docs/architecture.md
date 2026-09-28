# Architecture

The C core owns the virtual processing state. `vpu_t` contains configuration, an array of `vpu_core_t`, and a scheduler. Each core owns a context, bounded memory, and a fixed-size cache. The executor decodes one instruction at a time and advances PC unless an instruction changes control flow. The scheduler stores task values in a bounded ring queue and executes submitted function payloads synchronously through `run_one`/`run_all`.

The C++ library is a thin native compute layer over the C API. Rust provides safe Rust-side memory/scheduling helpers and a small FFI runtime wrapper. Go provides a cgo runtime handle and Go-side scheduling API.
