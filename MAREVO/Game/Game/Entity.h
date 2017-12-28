//Entity.h
#include "SFML/Graphics.hpp"
#include "map.h"
using namespace sf;

#ifndef __CLASSESS_H__ 
#define __CLASSESS_H__ 
class Entity
{
public:
float dx, dy, x, y, speed,moveTimer;
int w,h,health;
bool life, isMove, onGround;
void update(float time)
String name;
Texture texture;
Sprite sprite;
};
#endif