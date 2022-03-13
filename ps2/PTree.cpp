#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
//#include <SFML/Transform.hpp>
using namespace std;
using namespace sf;
//scale = size*1/sqrt(2)
//brown RGB(210, 105, 30)
class drawable{
		public:
					//drawable();//constructor
					void draw(RectangleShape rectangle, int depth, RenderWindow &window);
	};

void draw(RectangleShape rectangle, int depth, RenderWindow &window);

int main(int argc, char*argv[]){
	int size = atoi(argv[1]);
	int depth = atoi(argv[2]);
	drawable draw;
	sf::RenderWindow window(sf::VideoMode(800, 500), "ping");
	window.setFramerateLimit(60);
	sf::RectangleShape rectangle(sf::Vector2f(size, size));
	rectangle.setPosition(400-(size/2), 400); 
	rectangle.setFillColor(sf::Color(210, 105, 30));
	rectangle.setOrigin(rectangle.getPoint(0));
	window.draw(rectangle);
	draw.draw(rectangle, depth, window);
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
	}
	return 0;
}

void drawable::draw(RectangleShape rectangle, int depth, RenderWindow &window){	
	int angle = 45;
	if(depth == 0) return;//base case
	sf::RectangleShape left;//declaring next left
	sf::RectangleShape right;//declaring next right
	//prepare the new left and right rectangles for drawing 
	left.setSize(rectangle.getSize());
	right.setSize(rectangle.getSize());
	left.setOrigin(left.getPoint(3));
	right.setOrigin(right.getPoint(2));
	left.setPosition(rectangle.getTransform().transformPoint(rectangle.getPoint(0)));
	right.setPosition(rectangle.getTransform().transformPoint(rectangle.getPoint(1)));
	left.setRotation(rectangle.getRotation()-angle);
	right.setRotation(rectangle.getRotation()+(90-angle));
	left.setScale(rectangle.getScale().x*1/sqrt(2),rectangle.getScale().y*1/sqrt(2));
	right.setScale(rectangle.getScale().x*1/sqrt(2),rectangle.getScale().y*1/sqrt(2));

	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window.close();
		}
	}
	left.setFillColor(sf::Color(depth*rand(), depth*rand(), depth*rand()));//makes colors "random"
	right.setFillColor(sf::Color(depth*rand(), depth*rand(), depth*rand()));//makes colors "random"
	window.draw(left);
	window.draw(right);
	window.display();
	draw(left, depth-1, window);//recusrive call
	//rectangle.setFillColor(sf::Color(depth*rand(), depth*rand(), depth*rand()));
	draw(right, depth-1, window);//recursive call
	
}