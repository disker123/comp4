// "Copyright 2020 <Greg Kaplowitz>"

#ifndef MARKOV_H
#define MARKOV_H

#include <map>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>

class MarkovModel {
 public:
  MarkovModel(std::string text, int k);
  int k_order();
  int freq(std::string _kgram);
  int freq(std::string _kgram, char c);
  char kRand(std::string _kgram);
  std::string generate(std::string _kgram, int L);

  friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm);

 private:
  std::string txt;
  int order;
  std::map <std::string, int> kgram;
  std::string symtab;
};

int countFreq(std::string &pat, std::string &txt);  //NOLINT
int count_following_freq(std::string &pat, std::string &txt, char c);  //NOLINT

#endif

