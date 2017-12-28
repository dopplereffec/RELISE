
#include "Hero.h"



Player(Image &image, float X, float Y,int W,int H,String Name):Entity(image,X,Y,W,H,Name){
		   playerScore = 0; state = stay;
		   if (name == "Player"){
			   sprite.setTextureRect(IntRect(20, 134, w, h));//������ ������ ����� ���������� ��������
		   }
	   }
 
	   void control(){
		   if (Keyboard::isKeyPressed){//���� ������ �������
			   if (Keyboard::isKeyPressed(Keyboard::Left)) {//� ������ �����
				   state = left; speed = 0.1;
			   }
			   if (Keyboard::isKeyPressed(Keyboard::Right)) {
				   state = right; speed = 0.1;
			   }
 
			   if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {//���� ������ ������� ����� � �� �� �����, �� ����� �������
				   state = jump; dy = -0.6; onGround = false;//�������� ������ ������
			   }
 
			   if (Keyboard::isKeyPressed(Keyboard::Down)) {
				   state = down;
			   }
		   }
	   } 
 
	   void checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
	   {
		   for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������� �����
		   for (int j = x / 32; j<(x + w) / 32; j++)
		   {
			   if (TileMap[i][j] == '0')//���� ������� ��� ������ �����? ��
			   {
				   if (Dy>0){ y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
				   if (Dy<0){ y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
				   if (Dx>0){ x = j * 32 - w; }//� ������ ����� �����
				   if (Dx<0){ x = j * 32 + 32; }// � ����� ����� �����
			   }
			   //else { onGround = false; }//���� ������ �.� �� ����� ���������� � �� ������ ����������� ��� ��������� ������� �������� ����
		   }
	   }
	    
	   void update(float time)
	   {
		   control();//������� ���������� ����������
		   switch (state)//��� �������� ��������� �������� � ����������� �� ���������
		   {
		   case right:dx = speed; break;//��������� ���� ������
		   case left:dx = -speed; break;//��������� ���� �����

		   case stay: break;//� ����� ����		
		   }
		   x += dx*time;
		   checkCollisionWithMap(dx, 0);//������������ ������������ �� �
		   y += dy*time;
		   checkCollisionWithMap(0, dy);//������������ ������������ �� Y
		   sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
		   if (health <= 0){ life = false; }
		   if (!isMove){ speed = 0; }
		   if (life) { setPlayerCoordinateForView(x, y); }
		   dy = dy + 0.0015*time;//��������� ������������� � �����
	   } 
};