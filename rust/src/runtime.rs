use crate::scheduler::Scheduler;
pub struct Runtime<T>{pub scheduler:Scheduler<T>}
impl<T> Runtime<T>{pub fn new()->Self{Self{scheduler:Scheduler::new()}}pub fn submit(&mut self,t:T){self.scheduler.submit(t)}pub fn pending(&self)->usize{self.scheduler.len()}}
