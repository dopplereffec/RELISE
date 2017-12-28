//hero.h
#include "Entity.h"

#ifndef __HERO_H__ 
#define __HERO_H__ 
class Player :public Entity {
public:
	enum { left, right, up, down, jump, stay } state;//добавляем тип перечисления - состояние объекта
	int playerScore;//эта переменная может быть только у игрока
Player();
void control()
	 void checkCollisionWithMap(float, float );
	  void update(float time);
};
#endif