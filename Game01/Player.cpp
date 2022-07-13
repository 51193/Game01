#include "Player.h"

Player::Player(float x, float y, std::map<std::string, int>* keyBinds) :keyBinds{ keyBinds } {
	this->playing_animation = "PLAYER_IDLE_SOUTH";
	this->initComponent();
	this->setPosition(x, y);
}

Player::~Player() {

}

void Player::initTexturesheets() {
	this->texture_sheets["PLAYER_IDLE_NORTH"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_north.png");
	this->texture_sheets["PLAYER_WALK_NORTH"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_north.png");

	this->texture_sheets["PLAYER_IDLE_NORTHEAST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_northeast.png");
	this->texture_sheets["PLAYER_WALK_NORTHEAST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_northeast.png");

	this->texture_sheets["PLAYER_IDLE_EAST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_east.png");
	this->texture_sheets["PLAYER_WALK_EAST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_east.png");

	this->texture_sheets["PLAYER_IDLE_SOUTHEAST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_southeast.png");
	this->texture_sheets["PLAYER_WALK_SOUTHEAST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_southeast.png");

	this->texture_sheets["PLAYER_IDLE_SOUTH"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_south.png");
	this->texture_sheets["PLAYER_WALK_SOUTH"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_south.png");

	this->texture_sheets["PLAYER_IDLE_SOUTHWEST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_southwest.png");
	this->texture_sheets["PLAYER_WALK_SOUTHWEST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_southwest.png");

	this->texture_sheets["PLAYER_IDLE_WEST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_west.png");
	this->texture_sheets["PLAYER_WALK_WEST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_west.png");

	this->texture_sheets["PLAYER_IDLE_NORTHWEST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_idle_northwest.png");
	this->texture_sheets["PLAYER_WALK_NORTHWEST"].loadFromFile("Resources\\Images\\Sprites\\Player\\Player_walk_northwest.png");
}

void Player::initCorrespondingsheet() {
	this->corresponding_sheet[ActiveState::Idle_North] = "PLAYER_IDLE_NORTH";
	this->corresponding_sheet[ActiveState::Walk_North] = "PLAYER_WALK_NORTH";

	this->corresponding_sheet[ActiveState::Idle_NorthEast] = "PLAYER_IDLE_NORTHEAST";
	this->corresponding_sheet[ActiveState::Walk_NorthEast] = "PLAYER_WALK_NORTHEAST";

	this->corresponding_sheet[ActiveState::Idle_East] = "PLAYER_IDLE_EAST";
	this->corresponding_sheet[ActiveState::Walk_East] = "PLAYER_WALK_EAST";

	this->corresponding_sheet[ActiveState::Idle_SouthEast] = "PLAYER_IDLE_SOUTHEAST";
	this->corresponding_sheet[ActiveState::Walk_SouthEast] = "PLAYER_WALK_SOUTHEAST";

	this->corresponding_sheet[ActiveState::Idle_South] = "PLAYER_IDLE_SOUTH";
	this->corresponding_sheet[ActiveState::Walk_South] = "PLAYER_WALK_SOUTH";

	this->corresponding_sheet[ActiveState::Idle_SouthWest] = "PLAYER_IDLE_SOUTHWEST";
	this->corresponding_sheet[ActiveState::Walk_SouthWest] = "PLAYER_WALK_SOUTHWEST";

	this->corresponding_sheet[ActiveState::Idle_West] = "PLAYER_IDLE_WEST";
	this->corresponding_sheet[ActiveState::Walk_West] = "PLAYER_WALK_WEST";

	this->corresponding_sheet[ActiveState::Idle_NorthWest] = "PLAYER_IDLE_NORTHWEST";
	this->corresponding_sheet[ActiveState::Walk_NorthWest] = "PLAYER_WALK_NORTHWEST";
}

void Player::applyTexturesheets() {
	this->animation_component->addAnimation("PLAYER_IDLE_NORTH", texture_sheets.at("PLAYER_IDLE_NORTH"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_NORTH", texture_sheets.at("PLAYER_WALK_NORTH"), 75, 100, 140, 4);

	this->animation_component->addAnimation("PLAYER_IDLE_NORTHEAST", texture_sheets.at("PLAYER_IDLE_NORTHEAST"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_NORTHEAST", texture_sheets.at("PLAYER_WALK_NORTHEAST"), 75, 100, 140, 4);

	this->animation_component->addAnimation("PLAYER_IDLE_EAST", texture_sheets.at("PLAYER_IDLE_EAST"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_EAST", texture_sheets.at("PLAYER_WALK_EAST"), 75, 100, 140, 4);

	this->animation_component->addAnimation("PLAYER_IDLE_SOUTHEAST", texture_sheets.at("PLAYER_IDLE_SOUTHEAST"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_SOUTHEAST", texture_sheets.at("PLAYER_WALK_SOUTHEAST"), 75, 100, 140, 4);

	this->animation_component->addAnimation("PLAYER_IDLE_SOUTH", texture_sheets.at("PLAYER_IDLE_SOUTH"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_SOUTH", texture_sheets.at("PLAYER_WALK_SOUTH"), 75, 100, 140, 4);

	this->animation_component->addAnimation("PLAYER_IDLE_SOUTHWEST", texture_sheets.at("PLAYER_IDLE_SOUTHWEST"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_SOUTHWEST", texture_sheets.at("PLAYER_WALK_SOUTHWEST"), 75, 100, 140, 4);

	this->animation_component->addAnimation("PLAYER_IDLE_WEST", texture_sheets.at("PLAYER_IDLE_WEST"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_WEST", texture_sheets.at("PLAYER_WALK_WEST"), 75, 100, 140, 4);

	this->animation_component->addAnimation("PLAYER_IDLE_NORTHWEST", texture_sheets.at("PLAYER_IDLE_NORTHWEST"), 100, 100, 140, 14);
	this->animation_component->addAnimation("PLAYER_WALK_NORTHWEST", texture_sheets.at("PLAYER_WALK_NORTHWEST"), 75, 100, 140, 4);
}

void Player::updateInput(const float& dt) {

	float dir_x{ 0 }, dir_y{ 0 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("MOVE_LEFT")))) {
		dir_x--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("MOVE_RIGHT")))) {
		dir_x++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("MOVE_UP")))) {
		dir_y--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds->at("MOVE_DOWN")))) {
		dir_y++;
	}
	this->movement_component->move(dir_x, dir_y, dt);
}

void Player::updateAnimation() {
	if (this->playing_animation != this->corresponding_sheet.at(this->movement_component->getActiveState())) {
		this->animation_component->reset(this->playing_animation);
		this->playing_animation = this->corresponding_sheet.at(this->movement_component->getActiveState());
	}
	else NULL;
}

void Player::initComponent() {
	this->createMovementComponent(200.f, 5.f, 5.f);
	this->createHitboxComponent(sprite, 0, 0, 100, 140);
	this->createAnimationComponent();
	this->initTexturesheets();
	this->initCorrespondingsheet();
	this->applyTexturesheets();
}