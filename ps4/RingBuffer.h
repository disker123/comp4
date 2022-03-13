// "Copyright [2020] <greg kaplowitz>"  [legal/copyright]
#ifndef RINGBUFFER   // include guard
#define RINGBUFFER

#include <iostream>
#include <stdint.h>
#include <queue>
#include <memory>
#include <vector>
using namespace std;
//using namespace sf;

class RingBuffer {
 public:
  explicit RingBuffer();
  explicit RingBuffer(int passCapacity);
  int  get_size();
  bool    isEmpty();
  bool    isFull();
  void    enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
 private:
  int capacity;
  int first;
  int last;
  int size;
  std::vector<int16_t> buff;
};

#endif
