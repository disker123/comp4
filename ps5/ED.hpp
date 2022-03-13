#ifndef ED_HPP
#define ED_HPP

#include <SFML/System.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept> 

using namespace std;
using namespace sf;
class ED
{
  public:
	ED();//default
	ED(string pass_string_x, string pass_string_y);//the 2 strings
	~ED();//destructor
	int penalty(char x, char y);
	int min(int x, int y, int z);
	int OptDistance();
	string Alignment();

  private:
	string string_x;
	string string_y;
	vector<vector<int> > matrix;
};
#endif