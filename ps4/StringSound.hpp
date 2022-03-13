// "Copyright [2020] <Greg Kaplowitz>"  [legal/copyright]
#ifndef STRINGSOUND
#define STRINGSOUND

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cmath>
#include <math.h>
#include <iostream>
#include <stdint.h>
#include <queue>
#include <string>
#include <vector>
#include <memory>

#include "RingBuffer.h"
using namespace std;
// using namespace sf;

class StringSound{
public:
	explicit StringSound();
	explicit StringSound(double frequency);
	explicit  StringSound(vector<sf::Int16> given);
	void pluck();
	void tic();
	sf::Int16 sample();
	int time();
private:
	//unique_ptr<RingBuffer> ring_buffer;
	RingBuffer ring_buffer;
	int tic_count;
	int freq;
};

#endif