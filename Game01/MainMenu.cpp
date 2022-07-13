#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, std::map<std::string, int>* keyBinds, sf::Font* font, std::map<std::string, State*>* stateLib, State** activeState) :State(window, keyBinds, font, stateLib, activeState) {
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::White);
	this->initBackground();
	this->initButton();
}

MainMenu::~MainMenu() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++) {
		delete it->second;
	}
}

void MainMenu::initBackground() {
	this->background.setSize(
		sf::Vector2f
		(static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)));

	if (!this->bg_texture.loadFromFile("Resources\\Images\\Backgrounds\\MainMenu_bg1.png")) {
		std::cout << "Fail to load main menu background" << std::endl;
	}
	this->background.setTexture(&this->bg_texture);
}

void MainMenu::initButton() {
	this->buttons["NewGame"] = new Button(
		(this->window->getSize().x - this->window->getSize().x / 5.12) / 2,
		this->window->getSize().y / 3,
		this->window->getSize().x / 5.12,
		this->window->getSize().y / 8,
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0),
		sf::Color(192, 192, 192), sf::Color(255, 255, 255), sf::Color(255, 215, 0),
		font, "New Game");

	this->buttons["Settings"] = new Button(
		(this->window->getSize().x - this->window->getSize().x / 5.12) / 2,
		this->window->getSize().y / 2.1,
		this->window->getSize().x / 5.12,
		this->window->getSize().y / 8,
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0),
		sf::Color(192, 192, 192), sf::Color(255, 255, 255), sf::Color(255, 215, 0),
		font, "Settings");

	this->buttons["Quit"] = new Button(
		(this->window->getSize().x - this->window->getSize().x / 5.12) / 2,
		this->window->getSize().y / 1.6,
		this->window->getSize().x / 5.12,
		this->window->getSize().y / 8,
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0),
		sf::Color(192, 192, 192), sf::Color(255, 255, 255), sf::Color(255, 215, 0),
		font, "Quit");

	this->buttons["Editor"] = new Button(
		0,
		0,
		this->window->getSize().x / 5.12,
		this->window->getSize().y / 8,
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0),
		sf::Color(192, 192, 192), sf::Color(255, 255, 255), sf::Color(255, 215, 0),
		font, "Editor");
}

const bool& MainMenu::getterForQuit() const {
	return this->isQuit;
}

void MainMenu::endState() {
	std::cout << "End the menu state" << std::endl;
}

void MainMenu::updateInput(const float& dt) {
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("QUIT")))) {
		this->isQuit = 1;
	}*/
}

void MainMenu::updateButtons() {
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}
	if (buttons.at("Quit")->isPressed()) {
		this->isQuit = 1;
	}
	if (buttons.at("NewGame")->isPressed()) {
		*activeState = stateLib->at("TestState");
	}
	if (buttons.at("Editor")->isPressed()) {
		*activeState = stateLib->at("Editor");
	}
}

void MainMenu::update(const float& dt) {
	this->updateMousePositions();
	this->updateButtons();
	this->updateInput(dt);
}

void MainMenu::renderButtons(sf::RenderTarget& target) {
	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void MainMenu::render(sf::RenderTarget* target) {
	if (!target)target = this->window;

	target->draw(this->background);

	this->renderButtons(*target);

}