#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Bad {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite hp_bar;
	sf::Texture bad_bar;
	float BAD_HP = 300000;
	bool del = false;
	size_t zaderzka = 1000;
	size_t stop = 10;
	sf::Clock clock;
	float da = 1.f;
	int a = 0;
public:
	Bad();
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();

	void takedamage(float);
	float badHp();
	void setDel(bool);
	bool getDel();
	void setPos(int x, int y);
};