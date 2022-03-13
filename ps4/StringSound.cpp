#include <vector>
#include <memory>
#include <random>

#include "StringSound.hpp"
using namespace std;
using namespace sf;
using std::uniform_int_distribution;
using std::default_random_engine;

#define Random uniform_int_distribution;
#define gen default_random_engine;

const int samples_rate = 44100;
const double decay = 0.996;
int16_t MIN= 1<<15;
int16_t MAX= ~MIN;

StringSound::StringSound(){
	
}

StringSound::StringSound(double frequency):
	ring_buffer(ceil(samples_rate / frequency)) {
	freq = ceil(samples_rate / frequency);

	for (int i = 0; i < freq; i++) {
		ring_buffer.enqueue((int16_t)0);
	}
	tic_count = 0;
}

StringSound::StringSound(vector<sf::Int16> given):
	ring_buffer(given.size()) {
	freq = given.size();
	tic_count = 0;
	
	//RingBuffer _ring_buffer(freq);
	//ring_buffer = _ring_buffer;
	vector<sf::Int16>::iterator x;
	for (x = given.begin(); x < given.end(); x++) {
    ring_buffer.enqueue((int16_t)*x);
  }
}

void StringSound::pluck(){
	/*gen random_generator;
	for(int i =0;i<freq;i++){
		ring_buffer.dequeue();
	}
	Random<int16_t> generator = Random<int16_t>(MIN, MAX);
	while(!ring_buffer.isFull()){
		ring_buffer.enqueue(generator(random_generator));
	}
	return;*/
	for(int i=0; i<freq; i++){
		ring_buffer.dequeue();
	}
	
	for(int i=0; i<freq; i++){
		ring_buffer.enqueue((Int16)(rand() & 0xffff));
	}
	return;
}

sf::Int16 StringSound::sample(){
	return (sf::Int16)ring_buffer.peek();
}

void StringSound::tic(){
	int16_t temp = ring_buffer.dequeue();//get the first elem
	int16_t temp2 = ring_buffer.peek();//get the second elem now on top without removing
	int16_t avg = (temp + temp2)/2;//avg
	int16_t result = avg * .996;//get karplus algr result
	ring_buffer.enqueue((Int16)result);//add it to the buffer
	tic_count++;
	return;
}

int StringSound::time(){
	return tic_count;//counter
}

