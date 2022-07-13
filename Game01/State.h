#ifndef STATE_H
#define STATE_H

#include"Player.h"

class State {
public:

	State(sf::RenderWindow* window, std::map<std::string, int>* keyBinds, sf::Font* font, std::map<std::string, State*>* stateLib, State** activeState);
	virtual ~State();

	//纯虚功能函数

	virtual void endState() = 0;
	virtual void updateMousePositions();
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;

protected:
	std::map<std::string, State*>* stateLib;
	State** activeState;
	sf::RenderWindow* window;
	std::map<std::string, int>* keyBinds;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//资源

	sf::Font* font;
private:

};

#endif