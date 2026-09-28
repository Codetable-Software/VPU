package vpu
import "sync"
type Task func() error
type Scheduler struct{mu sync.Mutex;q []Task}
func(s *Scheduler)Submit(t Task){s.mu.Lock();s.q=append(s.q,t);s.mu.Unlock()}
func(s *Scheduler)RunOne()error{s.mu.Lock();if len(s.q)==0{s.mu.Unlock();return nil};t:=s.q[0];s.q=s.q[1:];s.mu.Unlock();return t()}
