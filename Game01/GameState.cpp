#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* keyBinds, sf::Font* font, std::map<std::string, State*>* stateLib, State** activeState) :State(window, keyBinds, font, stateLib, activeState) {
	this->initPlayer();
}

GameState::~GameState() {
	delete this->player;
}

void GameState::endState() {
	player->setPosition(0, 0);
	std::cout << "End the game state" << std::endl;
}

void GameState::updateStateChange() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("QUIT")))) {
		this->endState();
		*this->activeState = this->stateLib->at("MainMenu");
	}

}

void GameState::update(const float& dt) {
	this->updateStateChange();
	this->updateMousePositions();
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target) {
	if (!target)target = this->window;
	this->player->render(*target);
}

void GameState::initPlayer() {
	this->player = new Player(0.f, 0.f, keyBinds);
}
