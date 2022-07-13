#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include<iostream>
#include<map>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class AnimationComponent {
public:
	AnimationComponent(sf::Sprite& sprite);
	virtual ~AnimationComponent();

	void addAnimation(const std::string key, sf::Texture& animation_texture_sheet, float animation_timer, int width, int height, short int frame);
	void play(const std::string key, const float& dt);
	void reset(const std::string key);

private:
	class Animation {
	public:

		sf::Sprite& sprite;
		sf::Texture& animation_texture_sheet;
		float animation_timer;
		float timer;
		int width;
		int height;
		short int frame;

		short int current_frame;

		Animation(sf::Sprite& sprite,
			sf::Texture& animation_texture_sheet,
			float animation_timer,//每帧时间单位是毫秒
			int width, int height,
			short int frame)//总帧数大于等于1
			:sprite{ sprite }, animation_texture_sheet{ animation_texture_sheet },
			animation_timer{ animation_timer }, timer{ 0.f },
			width{ width }, height{ height },
			frame{ frame }, current_frame{ 1 }{}

		void play(const float& dt) {
			sprite.setTexture(this->animation_texture_sheet);
			this->timer += 1000.f * dt;
			if (this->timer >= this->animation_timer) {
				this->timer = 0.f;
				if (this->current_frame != frame) {
					current_frame++;
				}
				else {
					current_frame = 1;
				}
			}
			this->sprite.setTextureRect(sf::IntRect(this->width* (current_frame - 1), 0, this->width, this->height));
		}

		void reset() {
			current_frame = 1;
			timer = 0.f;
		}
	};

	sf::Sprite& sprite;
	std::map<std::string, Animation*>animations;

};

#endif