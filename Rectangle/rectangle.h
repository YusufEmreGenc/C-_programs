#include<iostream>

using namespace std;

class Rectangle
{
private:
	int x, y;
	int width, height;
public:
	
	Rectangle(int cx=0, int cy=0, int w=0, int h=0)
		:x(cx), y(cy), width(w), height(h)	{}
		
	friend istream& operator >>(istream& in, Rectangle& a);
	friend ostream& operator <<(ostream& out, Rectangle a);
	int operator &(Rectangle a);
	int operator |(Rectangle a);
	int operator ^(Rectangle a);
};
