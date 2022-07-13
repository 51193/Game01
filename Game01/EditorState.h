#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "Button.h"

class EditorState :public State {
public:
	EditorState(sf::RenderWindow* window, std::map<std::string, int>* keyBinds, sf::Font* font, std::map<std::string, State*>* stateLib, State** activeState);
	virtual ~EditorState();

	void initButton();

	void endState();
	void updateInput(const float& dt);
	void updateStateChange();
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
private:

	std::map<std::string, Button*>buttons;

};

#endif