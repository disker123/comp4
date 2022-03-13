// "Copyright 2020 <Greg Kaplowitz>"
#ifndef FibLFSR_HPP
#define FibLFSR_HPP


#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
  // using namespace sf;
  using namespace std;

  class LFSR {
  public:
  LFSR(std::string Seed);// constructor
  int step();// simulates one step					
  int generate(int k);// generates an integer of k bits of the processes 
  friend std::ostream& operator<< (std::ostream &out, const LFSR &lFSR);
  private:
  std::string seed;
  };
#endif
