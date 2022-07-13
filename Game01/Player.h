#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:

	Player(float x, float y, std::map<std::string, int>* keyBinds);
	virtual ~Player();

	void initTexturesheets();
	void initCorrespondingsheet();
	void applyTexturesheets();

	void updateInput(const float& dt);
	void updateAnimation();

private:
	std::map<std::string, int>* keyBinds;

	void initComponent();

};

#endif