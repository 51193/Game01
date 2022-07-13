#ifndef ENTITY_H
#define ENTITY_H

#include"MovementComponent.h"
#include"AnimationComponent.h"
#include"HitboxComponent.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	//¹¦ÄÜ

	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	void createAnimationComponent();

	virtual void initTexturesheets() = 0;
	virtual void initCorrespondingsheet() = 0;
	virtual void applyTexturesheets() = 0;

	virtual void initComponent() = 0;

	virtual void setPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt);

	virtual void updateInput(const float& dt) = 0;
	virtual void updateAnimation() = 0;

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);

protected:
	sf::Sprite sprite;

	std::map<std::string, sf::Texture>texture_sheets;
	std::map<ActiveState, std::string>corresponding_sheet;

	std::string playing_animation;

	HitboxComponent* hitbox_component;
	MovementComponent* movement_component;
	AnimationComponent* animation_component;

private:
	
};

#endif