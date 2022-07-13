#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class HitboxComponent {
public:
	HitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	virtual ~HitboxComponent();


	bool checkIntersect(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;

	float offset_x;
	float offset_y;

};

#endif