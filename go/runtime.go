package vpu
type RuntimeInfo struct{Version string; Cores uint32; Memory uint64}
func (r *Runtime) Info() RuntimeInfo{return RuntimeInfo{Version:"1.0.0",Cores:1,Memory:1024*1024}}
