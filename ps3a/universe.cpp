#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "universe.hpp"
#include <memory>
#include <cmath>
using namespace std;
using namespace sf;

const double G = 6.67e-11;
double deltaT;
double T;
universe::universe() {
	return;
}

void universe::addBody(unique_ptr<bodies> body){
	solarSystem.push_back(move(body));
	return;
}

void universe::draw_universe(RenderWindow &window){
	for(std::size_t i=0; i<solarSystem.size(); ++i) {
		window.draw(*(solarSystem.at(i)));
	}
}

bodies::bodies() {
	return;
}

void bodies::createBody(double rad, int universe_size){
	double nxpos = ( (xpos / rad) * (universe_size / 2) ) + (universe_size / 2);//(pos / rads ) * (window size/2)
	double nypos = ( (ypos / rad) * (universe_size / 2) ) + (universe_size / 2);
	//sprite.setPosition(sf::Vector2f(xpos, ypos));
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(nxpos, nypos));
	cout<<xpos<<"	"<< ypos<<endl;
	
	return;
}


void bodies::draw(sf::RenderTarget& target, sf::RenderStates blend) const{
//	cout<<"flag"<<endl;
	target.draw(sprite);
	return;
}


void universe::update(){
	double totalForce;
	double r;
	double deltax;
	double deltay;
	double accelx;
	double accely;
	for(std::size_t i=0; i<solarSystem.size(); ++i) {
		for(std::size_t j=0; j<solarSystem.size(); ++j) {
			if(i!=j){
				deltax = solarSystem.at(j)->getxpos() -  solarSystem.at(i)->getxpos();
				deltay = solarSystem.at(j)->getypos() -  solarSystem.at(i)->getypos();
				r = hypot(deltax, deltay); 
				totalForce = ((G * solarSystem.at(i)->getmass() *  solarSystem.at(j)->getmass())/(r*r));//F=Gm1m2/r^2
				solarSystem.at(i)->setFx(solarSystem.at(i)->getFx() + (totalForce * (deltax / r)));
				solarSystem.at(i)->setFy(solarSystem.at(i)->getFy() + (totalForce * (deltay / r)));
			}
		}
		accelx = solarSystem.at(i)->getFx() / solarSystem.at(i)->getmass();
		accely = solarSystem.at(i)->getFy() / solarSystem.at(i)->getmass();
		solarSystem.at(i)->setxvel(solarSystem.at(i)->getxvel() + (deltaT * accelx));
		solarSystem.at(i)->setyvel(solarSystem.at(i)->getyvel() + (deltaT * accely));
		 
		 totalForce = 0;
		 r = 0;
		 deltax = 0;
		 deltay = 0;
		 accelx = 0;
		 accely = 0;
	}
	
}

void universe::travel(double rad, int universe_size){
	for(std::size_t i=0; i<solarSystem.size(); ++i) {
			
		solarSystem.at(i)->setxpos(solarSystem.at(i)->getxpos() + (deltaT * solarSystem.at(i)->getxvel()));
		solarSystem.at(i)->setypos(solarSystem.at(i)->getypos() + (deltaT * solarSystem.at(i)->getyvel()));
		
		double nxpos = (	(solarSystem.at(i)->getxpos() / rad) *	(universe_size/2) + (universe_size / 2)	);
		double nypos = (	(solarSystem.at(i)->getypos() / rad) *	(universe_size/2) + (universe_size / 2)	);
		
		solarSystem.at(i)->sprite.setPosition(sf::Vector2f(nxpos, nypos));
		
		cout<< rad << endl;
		cout<<solarSystem.at(i)->getxpos() <<"     "<<solarSystem.at(i)->getypos()<< "   " <<solarSystem.at(i)->getxvel() <<"     "<<solarSystem.at(i)->getyvel()<< endl;
		solarSystem.at(i)->setFx(0);
		solarSystem.at(i)->setFy(0);
	}
	cout<<endl;
	
}



int main(int argc, char *argv[]){
	//gets the heatdeath timer
	T = atof(argv[1]);
	deltaT = atof(argv[2]);
	cout<< T << "   "<<deltaT<<endl;
	//get the planet count from the the top of the planet file
	int planet_count;
	cin >> planet_count;
	cout<< planet_count<<endl;
	
	//get the radius from the planet file
	double radius;
	cin >> radius;
	cout<< radius<<endl;
	
	//setting up the viewing window with image background
	int size = 500;
	sf::RenderWindow window(sf::VideoMode(size, size), "Universe");
	sf::Music music;
	music.openFromFile("2001.wav");
	music.play();
	
	
	sf::Texture universal_Texture;
	universal_Texture.loadFromFile("starfield.jpg");
	sf::Sprite background;
	background.setTexture(universal_Texture);
	window.draw(background);
	universe system;
	//time to play god
	window.setFramerateLimit(60);
	for(int i=0; i<planet_count; i++){
		std::unique_ptr<bodies> body(new bodies);
		cin >> *body;
		body->createBody(radius, size);
		system.addBody(move(body));
	}
	system.draw_universe(window);
	
	//window.display();
	
	for(int i = 0; i<T; i+=deltaT){//run the physics
		window.clear();
		window.draw(background);
		system.update();
		system.travel(radius, size);
		system.draw_universe(window);
		window.display();
	}
		window.display();

	//window loop
	while (window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
			window.close();
			}
		}
	}
	
	return 0;

}