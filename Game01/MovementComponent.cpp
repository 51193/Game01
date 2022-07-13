#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration) :sprite{ sprite }, maxVelocity{ maxVelocity }, acceleration{ acceleration + deceleration }, deceleration{ deceleration }, active_state{ 4 } {

}

MovementComponent::~MovementComponent() {

}

const sf::Vector2f& MovementComponent::getVelocity() const {
	return this->velocity;
}

const ActiveState MovementComponent::getActiveState() const{
	return ActiveState(active_state);
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt) {
	if (dir_x > 0 && dir_y > 0) {
		this->active_state = 11;
	}
	else if (dir_x > 0 && dir_y == 0) {
		this->active_state = 10;
	}
	else if (dir_x > 0 && dir_y < 0) {
		this->active_state = 9;
	}
	else if (dir_x == 0 && dir_y > 0) {
		this->active_state = 12;
	}
	else if (dir_x == 0 && dir_y == 0 && active_state >= 8) {
		this->active_state -= 8;
	}
	else if (dir_x == 0 && dir_y < 0) {
		this->active_state = 8;
	}
	else if (dir_x < 0 && dir_y > 0) {
		this->active_state = 13;
	}
	else if (dir_x < 0 && dir_y == 0) {
		this->active_state = 14;
	}
	else if (dir_x < 0 && dir_y < 0) {
		this->active_state = 15;
	}

	float current_acceleration = sqrt((dir_x * acceleration) * (dir_x * acceleration) + (dir_y * acceleration) * (dir_y * acceleration));
	if (current_acceleration > this->acceleration) {
		this->velocity.x += (this->acceleration * dir_x) * (this->acceleration / current_acceleration);
		this->velocity.y += (this->acceleration * dir_y) * (this->acceleration / current_acceleration);
	}
	else {
		this->velocity.x += this->acceleration * dir_x;
		this->velocity.y += this->acceleration * dir_y;
	}

	float current_velocity = sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y);

	if (current_velocity > this->maxVelocity) {
		this->velocity.x = this->velocity.x * (this->maxVelocity / current_velocity);
		this->velocity.y = this->velocity.y * (this->maxVelocity / current_velocity);
	}

	this->sprite.move(this->velocity * dt);
}

void MovementComponent::update(const float& dt) {


	float current_deceleration_x{ 0 }, current_deceleration_y{ 0 };

	if (this->velocity.x > 0.f) {
		if (deceleration > this->velocity.x) {
			current_deceleration_x = this->velocity.x;
		}
		else {
			current_deceleration_x = this->deceleration;
		}
	}
	else if (this->velocity.x < 0.f) {
		if (deceleration > this->velocity.x * -1) {
			current_deceleration_x = this->velocity.x;
		}
		else {
			current_deceleration_x = this->deceleration * -1;
		}
	}

	if (this->velocity.y > 0.f) {
		if (deceleration > this->velocity.y) {
			current_deceleration_y = this->velocity.y;
		}
		else {
			current_deceleration_y = this->deceleration;
		}
	}
	else if (this->velocity.y < 0.f) {
		if (deceleration > this->velocity.y * -1) {
			current_deceleration_y = this->velocity.y;
		}
		else {
			current_deceleration_y = this->deceleration * -1;
		}
	}

	float current_deceleration{ sqrt(current_deceleration_x * current_deceleration_x + current_deceleration_y * current_deceleration_y) };

	if (current_deceleration > this->deceleration) {
		this->velocity.x -= current_deceleration_x * (deceleration / current_deceleration);
		this->velocity.y -= current_deceleration_y * (deceleration / current_deceleration);
	}
	else {
		this->velocity.x -= current_deceleration_x;
		this->velocity.y -= current_deceleration_y;
	}

	this->sprite.move(this->velocity * dt);
}
