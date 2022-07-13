#include "Game.h"

Game::Game() : sfwindow{ nullptr }, isFullscreen{ 0 }, dt{ 0.f } {
	this->initWindow();
	this->initFont();
	this->initKeys();
	this->initState();
}

Game::~Game() {
	delete this->sfwindow;

	for (auto it = this->stateLib.begin(); it != this->stateLib.end(); it++) {
		delete it->second;
	}
	std::cout << "Memory released" << std::endl;
}

void Game::endApplication() {
	std::cout << "End the game" << std::endl;
	this->sfwindow->close();
}

void Game::updateDt() {
	this->dt = this->dtClock.restart().asSeconds();

//	system("cls");
//	std::cout << static_cast<int>(60/dt) << std::endl;
}

void Game::updateSFMLEvent() {
	while (this->sfwindow->pollEvent(sfevent)) {
		if (this->sfevent.type == sf::Event::Closed) {
			this->sfwindow->close();
		}
	}
}

void Game::update() {
	this->updateSFMLEvent();

	activeStates->update(this->dt);
	
	if (activeStates == stateLib.at("MainMenu") && dynamic_cast<MainMenu*>(activeStates)->getterForQuit()) {
		this->activeStates->endState();
		this->endApplication();
	}
}

void Game::render() {
	this->sfwindow->clear();

	activeStates->render(this->sfwindow);

	this->sfwindow->display();
}

void Game::run() {
	while (this->sfwindow->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

void Game::initWindow() {

	std::ifstream input("Config/window.ini", std::ios::in);
	this->videomode = sf::VideoMode::getFullscreenModes();

	std::string title = "Unnamed";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	unsigned int framerate_limit{ 120 };
	bool vertical_sync_enabled{ 0 };
	unsigned int antialiasing_level{ 0 };

	if (input.is_open()) {
		std::getline(input, title);
		input >> window_bounds.width >> window_bounds.height;
		input >> isFullscreen;
		input >> framerate_limit;
		input >> vertical_sync_enabled;
		input >> antialiasing_level;


		this->windowSettings.antialiasingLevel = antialiasing_level;
		if (this->isFullscreen) {
			this->sfwindow = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
		}
		else {
			this->sfwindow = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);
		}
		this->sfwindow->setFramerateLimit(framerate_limit);
		this->sfwindow->setVerticalSyncEnabled(vertical_sync_enabled);
		std::cout << "Windowsetting loaded" << std::endl;
	}
	else {
		std::ofstream output("Config/window.ini", std::ios::out);
		output << "You forgot to name it" << std::endl;
		output << sf::VideoMode::getDesktopMode().width << std::endl;
		output << sf::VideoMode::getDesktopMode().height << std::endl;
		output << false << std::endl;
		output << 120 << std::endl;
		output << false << std::endl;
		output << 0 << std::endl;
		output.close();
		initWindow();
	}
	input.close();
}

void Game::initState() {
	this->stateLib["MainMenu"] = new MainMenu(this->sfwindow, &this->keyBinds, &this->font, &this->stateLib, &this->activeStates);
	this->stateLib["TestState"] = new GameState(this->sfwindow, &this->keyBinds, &this->font, &this->stateLib, &this->activeStates);
	this->stateLib["Editor"] = new EditorState(this->sfwindow, &this->keyBinds, &this->font, &this->stateLib, &this->activeStates);
	this->activeStates = stateLib.at("MainMenu");
}

void Game::initKeys() {

	if (!keyBinds.empty()) {
		keyBinds.clear();
	}

	std::ifstream input("Config/keybinds.ini", std::ios::in);

	std::string movement{ "empty" };
	int key_number{ -1 };
	while (input.is_open() && input.get() != EOF) {
		std::getline(input, movement);
		input >> key_number;
		keyBinds[movement] = key_number;
	}
	if (!input.is_open()) {
		std::ofstream output("Config/keybinds.ini", std::ios::out);
		output << std::endl << "QUIT";
		output << std::endl << sf::Keyboard::Escape ;
		output << std::endl << "MOVE_LEFT" ;
		output << std::endl << sf::Keyboard::A ;
		output << std::endl << "MOVE_RIGHT" ;
		output << std::endl << sf::Keyboard::D ;
		output << std::endl << "MOVE_UP" ;
		output << std::endl << sf::Keyboard::W ;
		output << std::endl << "MOVE_DOWN" ;
		output << std::endl << sf::Keyboard::S ;
		output.close();
		initKeys();
	}
	input.close();
	std::cout << "Keybinds loaded" << std::endl;
}

void Game::initFont() {
	if (font.loadFromFile("Fonts/LXGWWenKai-Regular.ttf"))
		std::cout << "Font loaded" << std::endl;
}
