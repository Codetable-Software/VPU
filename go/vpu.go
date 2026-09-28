package vpu
/*#cgo CFLAGS: -I../include
#cgo LDFLAGS: -L../build -lvpu
#include <stdlib.h>
#include "vpu/api.h"
*/
import "C"
import "fmt"
import "unsafe"
type Runtime struct{ raw *C.vpu_t }
func New() (*Runtime,error){r:=&Runtime{raw:(*C.vpu_t)(C.calloc(1,C.size_t(C.sizeof_vpu_t)))};if r.raw==nil{return nil,fmt.Errorf("allocation failed")};if s:=C.vpu_init(r.raw,nil);s!=0{C.free(unsafe.Pointer(r.raw));return nil,fmt.Errorf("vpu_init: %s",C.GoString(C.vpu_status_string(s)))};return r,nil}
func (r *Runtime) Close(){if r!=nil&&r.raw!=nil{C.vpu_shutdown(r.raw);C.free(unsafe.Pointer(r.raw));r.raw=nil}}
