#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

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

enum class ActiveState {
	Idle_North, Idle_NorthEast, Idle_East, Idle_SouthEast, Idle_South, Idle_SouthWest, Idle_West, Idle_NorthWest,
	Walk_North, Walk_NorthEast, Walk_East, Walk_SouthEast, Walk_South, Walk_SouthWest, Walk_West, Walk_NorthWest
};

class MovementComponent {
public:

	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponent();

	const sf::Vector2f& getVelocity() const;
	const ActiveState getActiveState() const;

	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float& dt);

private:

	sf::Sprite& sprite;

	int active_state;

	float maxVelocity;

	float acceleration;
	float deceleration;
	sf::Vector2f velocity;
	

};

#endif