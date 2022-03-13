#include "ED.hpp"

#include <SFML/System.hpp>

using namespace sf;
using namespace std;
int main(int argc, const char* argv[]){
	Clock count;
	Time t;

	string string1;
	string string2;
	cin >> string1 >> string2;
	ED ed1(string1, string2);
	int distance = ed1.OptDistance();
	string ali = ed1.Alignment();

	//cout << "distance = " << distance << endl;
	cout << ali<<endl;
	cout << "Execution time is: " << t.asSeconds()<<"seconds"<<endl;;
	
	
	return 0;
}