//hero.h
#include "Entity.h"

#ifndef __HERO_H__ 
#define __HERO_H__ 
class Player :public Entity {
public:
	enum { left, right, up, down, jump, stay } state;//��������� ��� ������������ - ��������� �������
	int playerScore;//��� ���������� ����� ���� ������ � ������
Player();
void control()
	 void checkCollisionWithMap(float, float );
	  void update(float time);
};
#endif