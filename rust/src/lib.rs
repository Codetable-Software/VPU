pub mod bindings; pub mod memory; pub mod scheduler; pub mod runtime;
use bindings::{Vpu,VpuConfig,VPU_OK};
#[repr(C,align(8))] struct Storage([u64;512]);
pub struct CRuntime { storage:Box<Storage> }
impl CRuntime { pub fn new(memory_size:usize,cores:u32)->Result<Self,i32>{let mut storage=Box::new(Storage([0;512]));let cfg=VpuConfig{memory_size,cache_lines:64,queue_capacity:64,core_count:cores};let s=unsafe{bindings::vpu_init((&mut *storage as *mut Storage).cast::<Vpu>(),&cfg)};if s==VPU_OK{Ok(Self{storage})}else{Err(s)}} }
impl Drop for CRuntime { fn drop(&mut self){unsafe{bindings::vpu_shutdown((&mut *self.storage as *mut Storage).cast::<Vpu>())}} }
#[cfg(test)]mod tests{use super::*;#[test]fn ffi_symbols_are_linked(){assert!(CRuntime::new(4096,1).is_ok());}}
