// "Copyright 2020 <Greg Kaplowitz>"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "FibLFSR.hpp"
// using namespace sf;
// using namespace std;

  LFSR::LFSR(std::string Seed) {
  seed = Seed;
  }
  int LFSR::step() {
  char endbit = seed[15];
  char stepBit;
  if (((seed[0] == '1') ^ (seed[2] == '1')) ^
  ((seed[3] == '1') ^ (seed[5] == '1'))) {
  stepBit = '1';
  } else {
  stepBit = '0';
  }
  std::string new_string =  seed.substr(1);
  seed = new_string + stepBit;
  if (endbit == '1') {
  return 1;
  }
  return 0;
  }
  std::ostream& operator<< (std::ostream &out, const LFSR &lFSR) {
  out << lFSR.seed;
  return out;
  }
  int LFSR::generate(int k) {
  int x = 0;
  int temp;
  for (int i = 0; i < k; i++) {  // run step k times
  temp = step();
  if (temp == 1) {
  x += pow(2, i);
  }
  }
  // cout<<"flag"<<x<<endl;
  // cout<<x;
  return x;
  }
