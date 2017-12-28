#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include <iostream>
#include <sstream>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Hero.h"



 void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	menuTexture3.loadFromFile("images/333.png");
	aboutTexture.loadFromFile("images/about.png");
	menuBackground.loadFromFile("images/Scott.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;//логическая переменная (надо рисовать меню или нет)
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menuBg.setPosition(0, 0);
 

	Music music;//создаем объект музыки
	music.openFromFile("menu.ogg");//загружаем файл
	music.play();//воспроизводим музыку
////МЕНЮ/////
	while (isMenu)
	{
		menu1.setColor(Color::White);//окрашеваем в белый возвращаем картинке её оригинальный цвет 
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
 
		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }// если мы наводим курсор на одну из табличек мы окрашиваем их в голубой цвет ,тем самым мы определяем на какой из элементов мы навели  
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
 
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3)  { window.close(); isMenu = false; }
 
		}
 
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		
		window.display();
	}
	////////////////////////////////////////////////////
}
int main()
{
RenderWindow window(sf::VideoMode(1173, 779), "8");
	menu(window);//вызов меню
	view.reset(FloatRect(0, 0, 640, 480));


 
	Music music;//создаем объект музыки
	music.openFromFile("action.wav");//загружаем файл
	music.play();//воспроизводим музыку	
	music.setLoop(true); 

	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	
	Image heroImage;
	heroImage.loadFromFile("images/hero3.png");
 
	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("images/Vrag.png");
	easyEnemyImage.createMaskFromColor(Color(255, 0, 0));//сделали маску по цвету
 
 
	Player p(heroImage, 750, 500,40,30,"Player");//объект класса игрока
	Enemy easyEnemy(easyEnemyImage, 850, 671,200,97,"EasyEnemy");//простой враг, объект класса врага
	
	Clock clock;
	while (window.isOpen())
	{
 
		float time = clock.getElapsedTime().asMicroseconds();
 
		clock.restart();
		time = time / 800;
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();	
		}		
		p.update(time);// Player update function
		
		


		easyEnemy.update(time);//easyEnemy update function
		window.setView(view);
		window.clear();
 
		
			for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
				if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
				s_map.setPosition(j * 32, i * 32);
				
				window.draw(s_map);
			}
		window.draw(easyEnemy.sprite);
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}