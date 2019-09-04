#include <SFML/Graphics.hpp>
#include "Game.h"
#include <cmath>
using namespace sf;

bool loadImages(Image*);
void printBar(Game, Image*, RenderWindow*);

int main()
{
	Image images[20];

	Game test = Game(50);

	if (loadImages(images))
		cout << "Images loaded sucessfuly!\n";
	else
		cout << "Problem loading images!\n";

	RenderWindow window(VideoMode(800, 600), "Minesweeper");

	test.printBoard(images, &window);
	printBar(test, images, &window);
	window.display();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) {
				Coordenate temp = { (double)event.mouseButton.x / 32 , (double)event.mouseButton.y / 32 };

				if (event.mouseButton.button == Mouse::Left) {

					if (temp.y >= 18) {}

					else if (temp.y >= 16) {

						if (temp.x < 11.5) {}

						else if (temp.x <= 13.5)
							test = Game(50);

						else if (temp.x < 15.5) {}

						else if (temp.x <= 17.5)
							test.setDev();

						else if (temp.x <= 19.5)
							test = Game("./boards/testboard1.brd");

						else if (temp.x <= 21.5)
							test = Game("./boards/testboard2.brd");

						else if (temp.x <= 23.5)
							test = Game("./boards/testboard3.brd");
					}
					else
						test.clickTile(temp);
				}
				else if (event.mouseButton.button == Mouse::Right) {

					if (temp.y >= 16) {}

					else
						test.flagTile(temp);
				}
				window.clear();
				test.printBoard(images, &window);
				printBar(test, images, &window);
				window.display();
			}
		}
	}
	return 0;
}

bool loadImages(Image* images) {
	return (
		images[0].loadFromFile("./images/debug.png") &&
		images[1].loadFromFile("./images/digits.png") &&
		images[2].loadFromFile("./images/face_happy.png") &&
		images[3].loadFromFile("./images/face_lose.png") &&
		images[4].loadFromFile("./images/face_win.png") &&
		images[5].loadFromFile("./images/flag.png") &&
		images[6].loadFromFile("./images/tile_revealed.png") &&
		images[7].loadFromFile("./images/number_1.png") &&
		images[8].loadFromFile("./images/number_2.png") &&
		images[9].loadFromFile("./images/number_3.png") &&
		images[10].loadFromFile("./images/number_4.png") &&
		images[11].loadFromFile("./images/number_5.png") &&
		images[12].loadFromFile("./images/number_6.png") &&
		images[13].loadFromFile("./images/number_7.png") &&
		images[14].loadFromFile("./images/number_8.png") &&
		images[15].loadFromFile("./images/mine.png") &&
		images[16].loadFromFile("./images/test_1.png") &&
		images[17].loadFromFile("./images/test_2.png") &&
		images[18].loadFromFile("./images/test_3.png") &&
		images[19].loadFromFile("./images/tile_hidden.png")
		);
}

void printBar(Game game, Image* images, RenderWindow* window) {
	Texture texture;
	Sprite sprite;
	int temp, mines = game.getMines();
	bool drewSomething = false;

	//draw counter

	if (mines < 0) {
		if (!texture.loadFromImage(images[digits], IntRect(10 * 21, 0, 21, 32)))
			cout << "Problem loading - sign.";
		sprite.setPosition(Vector2f(0, 16 * 32));
		sprite.setTexture(texture);
	}

	window->draw(sprite);

	for (int i = 0; i < 3; i++) {
		temp = abs(mines) / pow(10, 2 - i); //current digit
		texture.loadFromImage(images[digits], IntRect(temp * 21, 0, 21, 32));
		sprite.setPosition(Vector2f(21 * (i + 1), 16 * 32));
		sprite.setTexture(texture);
		window->draw(sprite);
		drewSomething = true;
		mines = abs(mines) - pow(10, 2 - i) * temp;
	}

	//draw face

	switch (game.getState()) {
	case active:
		texture.loadFromImage(images[face_happy]);
		break;
	case lost:
		texture.loadFromImage(images[face_lose]);
		break;
	case won:
		texture.loadFromImage(images[face_win]);
		break;
	}

	sprite = Sprite();
	sprite.setTexture(texture);
	sprite.setPosition(Vector2f(368, 512));
	window->draw(sprite);

	//draw buttons
	texture.loadFromImage(images[debug]);
	sprite.setPosition(Vector2f(496, 512));
	window->draw(sprite);

	texture.loadFromImage(images[test_1]);
	sprite.setPosition(Vector2f(560, 512));
	window->draw(sprite);

	texture.loadFromImage(images[test_2]);
	sprite.setPosition(Vector2f(624, 512));
	window->draw(sprite);

	texture.loadFromImage(images[test_3]);
	sprite.setPosition(Vector2f(688, 512));
	window->draw(sprite);
}
