
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.h"
//#include "RingBuffer.cpp"
#include "StringSound.hpp"
//#include "StringSound.cpp"

using namespace std;
using namespace sf;
 
#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/'";

vector<Int16> make_samples(StringSound string_sounds) {
vector<Int16> samples;

  string_sounds.pluck();
  int total_time = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * total_time; i++) {
    string_sounds.tic();
    samples.push_back(string_sounds.sample());
  }

  return samples;
}

int main() {
	//cout<<"flag"<<endl;
	Event event;
	double freq;
	RenderWindow window(VideoMode(500, 500), "rock_band");
	vector<Int16> samples;
	freq = CONCERT_A;
	//StringSound string_sounds1 = StringSound(freq);
	StringSound string_sounds1;
	Sound sound1;
	//cout<<"flag"<<endl;
	samples = make_samples(string_sounds1);
	cout<<"flag"<<endl;
	SoundBuffer buf1;
	cout<<"flag"<<endl;
	sound1.setBuffer(buf1);
	freq = CONCERT_A * pow(2, 3.0/12.0);
	StringSound string_sounds2 = StringSound(freq);
	Sound sound2;
	SoundBuffer buf2;
	samples = make_samples(string_sounds2);
	sound2.setBuffer(buf2);

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case Event::Closed:
        window.close();
        break;

      case Event::KeyPressed:
        switch (event.key.code) {
        case Keyboard::A:
          sound1.play();
          break;
        case Keyboard::C:
          sound2.play();
          break;
        default:
          break;
        }

      default:
        break;
      }

      window.clear();
      window.display();
    }
  }
  return 0;
}
