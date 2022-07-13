#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite) :sprite{ sprite } {

}

AnimationComponent::~AnimationComponent() {
	for (auto& i : this->animations) {
		delete i.second;
	}
}

void AnimationComponent::addAnimation(
	const std::string key, sf::Texture& animation_texture_sheet, 
	float animation_timer, 
	int width, int height, 
	short int frame) {
	animations[key] = new Animation(this->sprite, animation_texture_sheet, animation_timer, width, height, frame);
}

void AnimationComponent::play(const std::string key, const float& dt) {
	this->animations.at(key)->play(dt);
}

void AnimationComponent::reset(const std::string key) {
	this->animations[key]->reset();
}
