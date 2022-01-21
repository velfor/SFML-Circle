#include "SFML/Graphics.hpp"
#include "const.h"
using namespace sf;
int main(){
	
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	//создание игровых объектов
	float r = 20.f;
	CircleShape circle(r,100);
	circle.setPosition(400.f - r, 300.f - r);
	float speedx = 2.5f;
	float speedy = 3.5f;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())	{
		// 1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// 2 update (изменение игровых объектов)
		//движение по экрану со скоростью speedx
		circle.move(speedx, speedy);
		//если коснулся или вышел за правую границу
		if (circle.getPosition().x + 2 * r >= WINDOW_WIDTH) {
			//поменять направление движения по оси х
			speedx = -speedx;
		}
		//если коснулся или вышел за левую границу
		if (circle.getPosition().x <= 0) {
			speedx = -speedx;
		}
		if (circle.getPosition().y + 2 * r >= WINDOW_HEIGHT) {
			//поменять направление движения по оси х
			speedy = -speedy;
		}
		if (circle.getPosition().y <= 0) {
			speedy = -speedy;
		}
		// 3 Отрисовка окна	
		// 3-1 Очистка окна
		window.clear(Color(0, 100, 0, 0));
		//3-2 Рисуем игровые объекты ( в памяти! )
		window.draw(circle);
		//3-3 Отображение на экран
		window.display();
	}
	return 0;
}