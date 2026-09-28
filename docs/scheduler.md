# Scheduler

Tasks contain an ID, priority, state, callback, payload, result pointer, and final status. The queue is a bounded FIFO ring. The scheduler stores configured worker capacity and exposes `submit`, `run_one`, and `run_all`. Execution is synchronous in 1.0.0, which keeps lifecycle and error propagation deterministic while preserving a worker-oriented API boundary.
