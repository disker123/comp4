// "Copyright 2020 <Greg Kaplowitz>"

#include "markov.h"
#include <vector>
#include <utility>

MarkovModel::MarkovModel(std::string text, int k) {
  order = k;  // set order
  // make text circular
  for (int i = 0; i < order-1; i++) {
  text.push_back(text[i]);
  }
  std::cout << text.length() << std::endl;
  symtab.push_back(text.at(0));
  for (unsigned int i = 0; i < text.length(); i++) {
  bool present = false;

  for (unsigned int j=0; j < symtab.length(); j++) {  // checks if the current
  //  char of the text is already in or symbol table
  // std::cout<<symtab.length()<<std::endl;
  if (symtab.at(j) == text.at(i)) {  // if yes
  present = true;  // then say so
  }
  }
  if (!present) {  // if it isnt present then add it
  symtab.push_back(text.at(i));
  }
  }
  // we should have a filled out sybol table here
  std::cout << symtab << std::endl;
  for (unsigned int i=0; i < text.length()-1; i++) {  // fill out the kgram and
  // freq sections of markov chart
  std::string kgram_string = text.substr(i, order);  // gets the kgram
  int freq = countFreq(kgram_string, text);  // gets the freq
  kgram.insert(std::pair<std::string, int>(kgram_string, freq));
  // adds the kgram key with its freq data
  }
  // now we should have a filled out map representing the kgram and freqency
  // for each
  /*for (std::map<std::string, int>::iterator it = kgram.begin();it !=kgram.end();it++){
  std::cout<< it->first <<"  "<<it->second<<std::endl;// test
  }*/ //this prints out the map 
  txt = text;
  }


int MarkovModel::k_order() {
	return order;
}

int MarkovModel::freq(std::string _kgram) {
  if (_kgram.length() != (unsigned)order){
  throw 
  std::invalid_argument("kgram not of length k 1");
  }
  if (kgram.find(_kgram) == kgram.end()) {
  return 0;
  }
  std::map<std::string, int > ::iterator it;
  it = kgram.find(_kgram);
  return it->second;
}

int MarkovModel::freq(std::string _kgram, char c) {
  if (_kgram.length() != (unsigned) order) {
  throw 
  std::invalid_argument("kgram not of length k 2");
  }
  if (kgram.find(_kgram) == kgram.end()) {
  return 0;
  }
  return count_following_freq(_kgram, txt, c);
}

char MarkovModel::kRand(std::string _kgram) {
  if (_kgram.length() != (unsigned) order) {
  throw 
  std::invalid_argument("kgram not of length k 3");
  }
  char result;
  int freq = this->freq(_kgram);
  int RNG = rand() % freq + 1;
  //std::cout<<RNG;
  bool is_zero = false;
//	The way I implement the weighted random sallection here starts a random
// 	integer between
//	1 and the frequency of the kgram then subtract the character freqency
//	so if there are 3 symbols in the symtab a/c/g with 5 kgram frequency 
//	we get a random int of 3 and the char freq's are a=3 c=0 g=2
//	we subtract 3 from the freq and check to see if the running count is <=0
//	we are at 0 so a is returned
  for (unsigned int i =0; i<symtab.length(); i++) {  // iterate through the 
  // symtab
  int diff = this->freq(_kgram, symtab[i]);
  RNG -= diff;
  if (RNG<=0 && !is_zero) {
  result = symtab[i];
  is_zero = true;
  }
  }
  return result;
 }

  std::string MarkovModel::generate(std::string _kgram, int L) {
  if (_kgram.length() != (unsigned) order){
  throw 
  std::invalid_argument("kgram not of length k 4");
  }
  std::string txt = "";
  txt += "" + _kgram;
	
  for (int i=0; i<L-order;i++) {
  char x = this->kRand(txt.substr(i, order));
  // std::cout<<x<<std::endl;
  txt.push_back(x);
  }
  return txt;
  }

  std::ostream& operator<< (std::ostream &out, MarkovModel &markov) {
  out<<"First the map: "<<std::endl;
  for (std::map<std::string, int>::iterator it = markov.kgram.begin();it !=markov.kgram.end();it++) {// no lint
  out<< it->first <<"  "<<it->second<<std::endl;// print the map;
  }
  
  out << "The symtab: "<< std::endl;
  out << markov.symtab << std::endl;

  out << "The order: "<<std::endl;
  out << markov.order << std::endl;

  return out;
}

int countFreq(std::string &pat, std::string &txt) { 
  int M = pat.length(); 
  int N = txt.length(); 
  int res = 0; 
    
  /* A loop to slide pat[ ] one by one */
  for (int i = 0; i <= N - M; i++) {
  /* For current index i, check for  
  pattern match */
  int j;
  for (j = 0; j < M; j++)
  if (txt[i+j] != pat[j])
  break;

  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
  if (j == M) {
  res++;
  j = 0;
  }
  }
  return res;
}

int count_following_freq(std::string &pat, std::string &txt, char c) {//NOLINT
  int M = pat.length();
  int N = txt.length();
  int res = 0;
  /* A loop to slide pat[ ] one by one */
  for (int i = 0; i <= N - M; i++) {
  /* For current index i, check for
  pattern match */
  int j;
  for (j = 0; j < M; j++)
  if (txt[i+j] != pat[j])
  break;
  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
  if (j == M) {
  if (txt[i + j] == c) {
  res++;
  }
  j = 0;
  }
  }
  return res;
}
