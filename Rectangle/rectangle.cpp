#include<iostream>
#include "Rectangle.h"

using namespace std;

istream& operator >>(istream& in, Rectangle& a)
{
	in >> a.x >> a.y >> a.width >> a.height;
	
	return in;
}

ostream& operator <<(ostream& out, Rectangle a)
{
	out << '(' << a.x << ',' << a.y << ')' << '-' << '<' << a.width << ',' << a.height << '>';
	
	return out;
}

int Rectangle::operator &(Rectangle a)
{
	if(x<=a.x)
	{
		if((a.x-x)>=width)
			return 0;
	}
	else
		if((x-a.x)>=a.width)
			return 0;
			
	if(y>=a.y)
	{
		if((y-a.y)>=a.height)
			return 0;
	}
	else
		if((a.y-y)>=height)
			return 0;
	
	
	//if rectangles intersect
	
	//if first one contains second one
	if(x<=a.x && ((x+width)>=(a.x+a.width)) && y<=a.y && ((y+height)>=(a.y+a.height)))
		return a.width*a.height;
	
	//if second one contains first one
	if(a.x<=x && ((a.x+a.width)>=(x+width)) && a.y<=y && ((a.y+a.height)>=(y+height)))
		return width*height;
		
	if(x<=a.x)
	{
		if(y<=a.y)
		{
			if((x+width <= a.x+a.width) && (y+height <= a.y+a.height))
				return ((x+width)-a.x)*((y+height)-a.y);
			else
			{
				if(y+height <= a.y+a.height)
					return a.width*((y+height)-a.y);
				else
					return a.height*((x+width)-a.x);
			}
		}
		else
		{
			if((x+width <= a.x+a.width) && (a.y <= y))
			{
				if(y+height >= a.y+a.height)
					return ((x+width)-a.x)*((a.y+a.height)-y);
				else
					return height * ((x+width)-a.x);
			}
			else
			{
				if(a.y+a.height <= y+height)
					return a.width * ((a.y+a.height)-y);
				else
					return height * a.width;
			}
		}
	}
	else
	{
		if(y<=a.y)
		{
			if((a.y+a.height) >= (y+height))
			{
				if(x+width >= a.x+a.width)
					return ((a.x+a.width)-x)*((y+height)-a.y);
				else
					return width * ((y+height)-a.y);
			}
			else
			{
				if(a.x+a.width <= x+width)
					return a.height * ((a.x+a.width)-x);
				else
					return a.height * width;
			}
		}
		else
		{
			if(a.y+a.height <= y+height)
			{
				if(a.x+a.width <= x+width)
					return ((a.x+a.width)-x)*((a.y+a.height)-y);
				else
					return width * ((a.y+a.height)-y);
			}
			else
				return height * ((a.x+a.width)-x);
		}
	}
}

int Rectangle::operator |(Rectangle a)
{
	return (width*height)+(a.width*a.height)-((*this)&a);
}

int Rectangle::operator ^(Rectangle a)
{
	int w, h;
	if(x<=a.x)
		w = (x+width)>=(a.x+a.width) ? width : ((a.x+a.width)-x);
	else
		w = (x+width)<=(a.x+a.width) ? a.width : ((x+width)-a.x);
	
	if(y<=a.y)
		h = (y+height)>=(a.y+a.height) ? height : ((a.y+a.height)-y);
	else
		h = (y+height)<=(a.y+a.height) ? a.height : ((y+height)-a.y);
		
	return w*h;
}
