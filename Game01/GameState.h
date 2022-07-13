#ifndef GAMESTATE_H
#define GAMESTATE_H

#include"State.h"

class GameState :public State {
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* keyBinds, sf::Font* font, std::map<std::string, State*>* stateLib, State** activeState);
	virtual ~GameState();

	//¹¦ÄÜ

	void endState();
	void updateStateChange();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
private:

	void initPlayer();

	Player* player;
};

#endif