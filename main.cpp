#include "SFML/Graphics.hpp"
#include "const.h"
using namespace sf;
int main() {
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	//создание игровых объектов
	float r = 20.f;
	CircleShape circle(r, 100);
	circle.setPosition(400.f - r,300.f - r);
	float speedx = 10.5f;
	float speedy = 10.5f;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen()) {
		// 1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event)) {
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// 2 update (изменение игровыx объектов)
		circle.move(speedx,speedy);
		if (circle.getPosition().x + 2 * r >= WINDOW_WIDTH) {
			speedx = -speedx;
		}
		if (circle.getPosition().x <= 0) {
			speedx = -speedx;
		}
		if (circle.getPosition().y + 2 * r >= WINDOW_HEIGHT) {
			speedy = -speedy;
		}
		if (circle.getPosition().y <= 0) {
			speedy = -speedy;
		}
		// 3 Отрисовка окна	
		// 3-1 очистка окна 
		window.clear(Color(230, 200,100, 0));
		//3-2 рисуем игровые объекты (в памяти)
		window.draw(circle);
		//3-3 отображение на экран 
		window.display();
	}
	return 0;
}