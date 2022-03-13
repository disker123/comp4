#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
using namespace std;
using namespace sf;


class bodies : public sf::Drawable{
public:
	bodies();
	sf::Sprite sprite;
	//bodies(double xpossition, double ypossition, double xvelocity, double yvelocity, double size, std::string imagename);//construcot
	friend std::istream& operator>> (std::istream &in, bodies& body){//insertion for taking the data from inputfiles
	in >> body.xpos;
	in >> body.ypos;
	in >> body.xvel;
	in >> body.yvel;
	in >> body.mass;
	in >> body.filename;
	body.Fx = 0;
	body.Fy = 0;
	return in;
	}
	void virtual draw(sf::RenderTarget& target, sf::RenderStates blend) const;
	void createBody(double rad, int universe_size);
	double getxpos(){
		return xpos;
	}
	double getypos(){
		return ypos;
	}
	double getxvel(){
		return xvel;
	}
	double getyvel(){
		return yvel;
	}
	double getmass(){
		return mass;
	}
	
	double getFx(){
		return Fx;
	}
	double getFy(){
		return Fy;
	}
	
	void setxpos(double x){
		xpos = x;
		return;
	}
	void setypos(double y){
		ypos = y;
		return;
	}
	void setxvel(double x){
		xvel = x;
		return; 
	}
	void setyvel(double y){
		yvel = y;
		return;
	}
	void setspritePos(double x, double y){
		sprite.setPosition(sf::Vector2f(x, y));
		return;
	}
	void setFx(double x){
		Fx = x;
		return;
	}
	void setFy(double y){
		Fy = y;
		return;
	}
private:
	double xpos;	
	double ypos;
	double xvel;
	double yvel;
	double mass;
	std::string filename;
	Texture texture;
	//sf::Sprite sprite;
	double Fx;
	double Fy;
};




class universe : public bodies{
public:
	universe();
	void addBody(unique_ptr<bodies> body);
	void draw_universe(RenderWindow &window);
	void update();
	void travel(double rad, int universe_size);
private:
	vector <unique_ptr<bodies>> solarSystem;
	
};

