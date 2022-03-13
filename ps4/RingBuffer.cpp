#include <iostream>
#include "RingBuffer.h"
#include <stdint.h>
#include <memory>
// "Copyright [2020] <Greg Kaplowitz>"  [legal/copyright]
using namespace std;
 RingBuffer::RingBuffer() {
  first = 0;
  last = 0;
  size = 0;
  //cout << capacity;
  capacity = 1;
  buff.resize(capacity);
  }

  RingBuffer::RingBuffer(int passCapacity) {
  if (passCapacity <1) {
  throw
  invalid_argument("RingBufferconstructor: capacity must be greater than zero");
  }
  first = 0;
  last = 0;
  size = 0;
  //cout << capacity;
  capacity = passCapacity;
  buff.resize(capacity);
  }
  int  RingBuffer::get_size() {
  //cout << size;
  return size;
  }
  bool RingBuffer::isEmpty() {  // is the buffer empty (size equals zero)?
  if (size == 0) {
  //cout << "empty";
  return true;
  }
  //cout << "not empty";
  return false;
  }
  bool RingBuffer::isFull() {   // is the buffer full  (size equals capacity)?
  if (size == capacity) {
  //cout << "full";
  return true;
  }
  //cout << "not full";
  return false;
  }
  void RingBuffer::enqueue(int16_t val) {        // add item x to the end
  if (!isFull()) {
    if(last >= capacity){
		last = 0;
	}
	buff.at(last) = val;
	size++;
	last++;
  } else {
  throw
  runtime_error("enqueue: can't enqueue to a full ring");
  }
  }
  
int16_t RingBuffer::dequeue() {    // delete and return item from the front
  if (isEmpty()) {
	throw
	runtime_error("dequeue: can't dequeue from an empty buffer");
  }
  int16_t temp  = buff.at(first);
  buff.at(first) = 0;
  if(first >= 0){
	first = 0;
  }
  //cout << temp;
  return temp;
  }
  
  int16_t RingBuffer::peek() {
  if(isEmpty()){
	throw
	runtime_error("dequeue: can't dequeue from an empty buffer");
  }
  return buff.at(first);
  }

/*	int main(){
  RingBuffer buffer(10);//creates queue of size 10
  buffer.size();//print size = 10
  cout<<endl;
  buffer.isEmpty(); //empty
  cout<<endl;
  buffer.isFull();//not full
  cout<<endl;
  for(int i=0; i<5; i++){
  buffer.enqueue(1);
  }
  cout<<endl;
  buffer.peek();//1
  cout<<endl;
  buffer.size();//5
  cout<<endl;
  buffer.isEmpty();//not empty
  cout<<endl;
  buffer.isFull();//not full
  cout<<endl;
  for(int i=0; i<5; i++){
  buffer.enqueue(2);
  }
  cout<<endl;
  buffer.size();//size = 10
  cout<<endl;
  buffer.isEmpty();//not empty
  cout<<endl;
  buffer.isFull();//full
  cout<<endl;
  for(int i=0; i<10; i++){
  buffer.dequeue();
  }
  cout<<endl;
  buffer.size();//size = 0
  cout<<endl;
  buffer.isEmpty();//empty
  cout<<endl;
  buffer.isFull();//not full
  cout<<endl;
  return 0;
  }
  */
