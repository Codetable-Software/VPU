use std::os::raw::{c_int,c_uint,c_ulonglong,c_size_t};
#[repr(C)] pub struct VpuConfig { pub memory_size:c_size_t,pub cache_lines:c_size_t,pub queue_capacity:c_size_t,pub core_count:c_uint }
#[repr(C)] pub struct Vpu { _private:[u8;0] }
extern "C" { pub fn vpu_init(v:*mut Vpu,cfg:*const VpuConfig)->c_int; pub fn vpu_shutdown(v:*mut Vpu); pub fn vpu_status_string(s:c_int)->*const std::os::raw::c_char; }
pub const VPU_OK:c_int=0;
