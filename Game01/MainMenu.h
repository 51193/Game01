#ifndef MAINMENU_H
#define MAINMENU_H

#include "State.h"
#include "Button.h"

class MainMenu :public State {
public:
	MainMenu(sf::RenderWindow* window, std::map<std::string, int>* keyBinds, sf::Font* font, std::map<std::string, State*>* stateLib, State** activeState);
	virtual ~MainMenu();

	void initBackground();
	void initButton();

	const bool& getterForQuit() const;

	void endState();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
private:
	
	bool isQuit;

	sf::Texture bg_texture;
	sf::RectangleShape background;
	std::map<std::string, Button*>buttons;

};

#endif