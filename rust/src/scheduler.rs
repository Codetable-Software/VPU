use std::collections::VecDeque;
pub struct Scheduler<T>{q:VecDeque<T>}
impl<T> Scheduler<T>{pub fn new()->Self{Self{q:VecDeque::new()}}pub fn submit(&mut self,t:T){self.q.push_back(t)}pub fn run_one<F:FnOnce(T)>(&mut self,f:F)->bool{if let Some(t)=self.q.pop_front(){f(t);true}else{false}}pub fn len(&self)->usize{self.q.len()}}
#[cfg(test)]mod tests{use super::*;#[test]fn queue(){let mut s=Scheduler::new();s.submit(3);let mut x=0;s.run_one(|v|x=v);assert_eq!(x,3);}}
