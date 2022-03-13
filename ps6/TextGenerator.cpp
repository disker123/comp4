// "Copyright 2020 <Greg Kaplowitz>"
#include "markov.h"

int main(int argc, char *argv[]) {
  int k;
  int L;
  k = atof(argv[1]);
  L = atof(argv[2]);  // get cmd line args
  std::cout << k << "       " << L << std::endl;

  std::string input = "";
  std::string current_txt = "";

  while (std::cin >> current_txt) {
  input += " " + current_txt;
  current_txt = "";
  }
  std::cout << "The story:" << std::endl << std::endl;
  for (int a = 0; a < L; a++) {  // print the passing texted
  std::cout << input[a];


  if (input[a] == '.' || input[a] == '!') {
  std::cout << std::endl;  // auto enters at end of statement so I dont have to
  }
  }

  std::string output_string = "";
  MarkovModel amazing(input, k);
  output_string += "" + amazing.generate(input.substr(0, k), L);
  std::cout << std::endl;
  std::cout << "The fanfic:" << std::endl;

  for (int a = 0; a < L; a++) {
    std::cout << output_string[a];

    if (output_string[a] == '.' || output_string[a] == '!') {
      std::cout << std::endl;  // auto enters at end of statement so I
  // don't have to
    }
  }



  return 0;
}

