#ifndef GAME_H
#define GAME_H

#include"MainMenu.h"
#include"GameState.h"
#include"EditorState.h"

class Game{
public:

	//Ctor Dtor

	Game();
	virtual~Game();

	//功能

	void endApplication();

	void updateDt();
	void updateSFMLEvent();
	void update();
	void render();
	void run();

private:

	//变量

	sf::RenderWindow* sfwindow;
	sf::ContextSettings windowSettings;
	bool isFullscreen;

	sf::Event sfevent;
	std::vector<sf::VideoMode>videomode;

	sf::Clock dtClock;
	float dt;

	std::map<std::string, State*> stateLib;
	State* activeStates;

	std::map<std::string, int> keyBinds;

	sf::Font font;

	//初始化功能

	void initWindow();
	void initState();
	void initKeys();
	void initFont();
};

#endif