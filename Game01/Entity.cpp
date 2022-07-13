#include "Entity.h"

Entity::Entity() :hitbox_component{ nullptr }, movement_component { nullptr }, animation_component{ nullptr }, playing_animation{ NULL } {

}

Entity::~Entity() {
	delete this->hitbox_component;
	delete this->movement_component;
	delete this->animation_component;
}

void Entity::createMovementComponent(const float maxVelocity,const float acceleration,const float deceleration) {
	this->movement_component = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height) {
	this->hitbox_component = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

void Entity::createAnimationComponent() {
	this->animation_component = new AnimationComponent(this->sprite);
}

void Entity::setPosition(const float x, const float y) {

	this->sprite.setPosition(x, y);

}

void Entity::move(const float dir_x, const float dir_y, const float& dt) {
	if (this->movement_component) {
		this->movement_component->move(dir_x, dir_y, dt);
	}
}

void Entity::update(const float& dt) {

	this->updateInput(dt);
	this->updateAnimation();

	if (this->movement_component) {
		this->movement_component->update(dt);
	}
	else {
		std::cout << "No movement component" << std::endl;
	}

	if (this->hitbox_component) {
		this->hitbox_component->update();
	}
	else {
		std::cout << "No hitbox component" << std::endl;
	}

	if (this->animation_component) {
		this->animation_component->play(this->playing_animation, dt);
	}
	else {
		std::cout << "No animation component" << std::endl;
	}
}

void Entity::render(sf::RenderTarget& target) {
		target.draw(this->sprite);

		if (this->hitbox_component) {
			this->hitbox_component->render(target);
		}
		else {
			std::cout << "No hitbox component" << std::endl;
		}
}
