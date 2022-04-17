#include "bad.h"
#include "settings.h"



Bad::Bad() {
	texture.loadFromFile(IMAGES_FOLDER + BAD_SHIP );
	sprite.setScale(1.4f, 1.3f);
	sprite.setTexture(texture);
	texture.setSmooth(true);
	bad_bar.loadFromFile(IMAGES_FOLDER + HP_BAR);
	hp_bar.setTexture(bad_bar);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sf::FloatRect h_bounds = hp_bar.getGlobalBounds();
	sprite.move(100, -300);
	
	hp_bar.setPosition(g_bounds.width / 1.75 , 80);
	
}

void Bad::update() {
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	if (a <=0) {
		sprite.setPosition(WINDOW_WIDTH / 2 - g_bounds.width / 2,
			WINDOW_HEIGHT / 6);
		a++;
	}
	sf::Vector2f position = sprite.getPosition();
	
	sf::Vector2f polozenie = hp_bar.getPosition();
	sf::FloatRect h_bounds = hp_bar.getGlobalBounds();
	sf::Time now = clock.getElapsedTime();
	if (now.asMilliseconds() > zaderzka) {
		size_t dodge = rand() % 1000;
		if (dodge >= 500) {
			sprite.move(40.0f, 0.0f);
			hp_bar.move(40.f, 0.f);
		}
		else if (dodge < 500) {
			sprite.move(-40.0f, 0.0f);
			hp_bar.move(-40.f, 0.f);
		}
		if (position.x > WINDOW_WIDTH - g_bounds.height) { sprite.move(-70.0f, 0.f); hp_bar.move(-70.f, 0.f);
		}
		if (position.x < 0) { sprite.move(70.0f, 0.f); hp_bar.move(70.f, 0.f);
		}
		clock.restart();
	}
	da = BAD_HP / 300000.f;
	hp_bar.setScale(da, 1.f);
	if (BAD_HP <= 0) { sprite.move(100, -300); }
}
	
void Bad::draw(sf::RenderWindow& window) { window.draw(sprite); window.draw(hp_bar);
}
sf::FloatRect Bad::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Bad::getPosition() { return sprite.getPosition(); }
void Bad::takedamage(float damage) {BAD_HP -= damage ; }
float Bad::badHp() { return BAD_HP; }
void Bad::setDel(bool a) { del = a; }
bool Bad::getDel() { return del; }
void Bad::setPos(int x, int y) { sprite.setPosition(x, y); }