#include "EditorState.h"

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* keyBinds, sf::Font* font, std::map<std::string, State*>* stateLib, State** activeState)
	:State(window, keyBinds, font, stateLib, activeState) {
	this->initButton();
}

EditorState::~EditorState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++) {
		delete it->second;
	}
}

void EditorState::initButton() {
	//模板如下
	/*this->buttons["NewGame"] = new Button(
		(this->window->getSize().x - this->window->getSize().x / 5.12) / 2,
		this->window->getSize().y / 3,
		this->window->getSize().x / 5.12,
		this->window->getSize().y / 8,
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0),
		sf::Color(192, 192, 192), sf::Color(255, 255, 255), sf::Color(255, 215, 0),
		font, "New Game");*/


}

void EditorState::endState() {
	std::cout << "End the editor state" << std::endl;
}

void EditorState::updateInput(const float& dt) {
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("QUIT")))) {
		this->isQuit = 1;
	}*/
}

void EditorState::updateStateChange() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("QUIT")))) {
		this->endState();
		*this->activeState = this->stateLib->at("MainMenu");
	}

}

void EditorState::updateButtons() {
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}
	//模板如下
	/*if (buttons.at("NewGame")->isPressed()) {
		*activeState = stateLib->at("TestState");
	}*/
}

void EditorState::update(const float& dt) {
	this->updateMousePositions();
	this->updateButtons();
	this->updateInput(dt);
	this->updateStateChange();
}

void EditorState::renderButtons(sf::RenderTarget& target) {
	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void EditorState::render(sf::RenderTarget* target) {
	if (!target)target = this->window;

	this->renderButtons(*target);

}
