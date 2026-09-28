# Memory model

Each virtual core owns a byte-addressed contiguous allocation. `vpu_memory_alloc` uses a monotonic bump pointer with power-of-two alignment and never returns an address outside the allocation. Reads and writes validate both start address and length. `vpu_memory_free` clears a range; it does not recycle allocation metadata. The cache is an independent bounded byte store used as an optional cache layer.
