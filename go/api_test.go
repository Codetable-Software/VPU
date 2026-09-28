package vpu
import "testing"
func TestVersion(t *testing.T){if Version()!="1.0.0"{t.Fatalf("unexpected version: %s",Version())}}
func TestScheduler(t *testing.T){var s Scheduler;v:=0;s.Submit(func()error{v=7;return nil});if err:=s.RunOne();err!=nil||v!=7{t.Fatalf("scheduler failed: %v %d",err,v)}}
