#include <iostream>
#include <cmath>
#include"PA4.h"

using namespace std;

int abso(int x)
{
	if(x<0) return -x;
	return x;
}

Point DispWindow::current()
{
	return curr;
}

void DispWindow::current(Point p)
{
	curr.Set(p.x, p.y);
}

void Dot::draw(DispWindow &a)
{
	if (a.inBuff(m_p))
	{
		a.Get_Buff()[(int)m_p.y][(int)m_p.x] = '*';
		a.current(m_p);
	}
}

Point Point::right(int i)
{
	x += i;
	return *this;
}

Point Point::left(int i)
{
	x -= i;
	return *this;
}

Point Point::up(int i)
{
	y -= i;
	return *this;
}

Point Point::down(int i)
{
	y += i;
	return *this;
}

bool DispWindow::inBuff(Point a)
{
	return ((a.x < x) && (a.y < y)) ? true : false;
}

Point Point::operator/(double a)
{
	Point temp;
	temp.x = x/a;
	temp.y = y/a;
	
	return temp;
}

void Line::draw(DispWindow &a)
{
	Point v(p1.x- p2.x, p1.y - p2.y);
	v.vector();
	
	a.current(Point(p1.x, p1.y));
	if(p1.x>p2.x && p1.y<p2.y)	a.current(Point(p1.x+1,p1.y));
	if(p1.x<p2.x && p1.y>p2.y)	a.current(Point(p1.x,p1.y+1));
	
	
	if(!((p1.x>p2.x && p1.y<p2.y) || (p1.x<p2.x && p1.y>p2.y)))
		if(a.inBuff(a.current()))	a.Get_Buff()[(int)a.current().y][(int)a.current().x] = '*';
	
	//if the line straight
	if(v.x==0 || v.y==0)
	{
		while(a.current() != p2)
		{	
			a.current(a.current() - v);	
			if(a.inBuff(a.current()))	a.Get_Buff()[(int)a.current().y][(int)a.current().x] = '*';
		}
	}
	//if the line sloopy
	while(((int)a.current().x != (int)p2.x) && ((int)a.current().y != (int)p2.y))
	{
		a.current(a.current() - v);
		
		if(a.inBuff(a.current()))	a.Get_Buff()[(int)a.current().y][(int)a.current().x] = '*';
	}
	if(a.inBuff(a.current()))	a.Get_Buff()[(int)a.current().y][(int)a.current().x] = '*';
	
	a.current(p2);
}


void Point::vector()
{
	int min = (abso(x) < abso(y)) ? (abso(x)) : (abso(y));
	
	if(min==0) min++;
	for (int i = 1; i <= min; i++)
	{
		if(x==0)
		{ 
			if(y<0) y=-1;
			else
				{y=1; break;}
		}
		if(y==0)
		{ 
			if(x<0)	x=-1;
			else
				{x=1; break;}
		}
		if ((int)x%i == 0 && (int)y%i == 0)	x /= i, y /= i;
	}
	
	double norm = sqrt(x*x+y*y);
	x /= norm;
	y /= norm;

	if(!(x==0 || y==0))
		*this = *this / 10000;
}

void Rectangle::draw(DispWindow& a)
{
	Point left = (p1.x < p2.x) ? (p1) : (p2);
	Point right = (p1.x > p2.x) ? (p1) : (p2);
		if (left.y > right.y)
		{
			for (int i = left.y; i >= right.y; i++)
			{
				if (a.inBuff(Point(i,left.x)))	a.Get_Buff()[i][(int)left.x] = '*';
				if (a.inBuff(Point(i,right.x)))	a.Get_Buff()[i][(int)right.x] = '*';
			}
			
			for (int i = left.x; i <= right.x; i++)
			{
				if (a.inBuff(Point(right.y,i))) a.Get_Buff()[(int)right.y][i] = '*';
				if (a.inBuff(Point(left.y,i)))	a.Get_Buff()[(int)left.y][i] = '*';
			}
		}
		else
		{
			for (int i = left.y; i <= right.y; i++)
			{
				if (a.inBuff(Point(i, left.x)))	a.Get_Buff()[i][(int)left.x] = '*';
				if (a.inBuff(Point(i, right.x)))	a.Get_Buff()[i][(int)right.x] = '*';
			}

			for (int i = left.x; i <= right.x; i++)
			{
				if(a.inBuff(Point(right.y, i)))	a.Get_Buff()[(int)right.y][i] = '*';
				if (a.inBuff(Point(left.y, i)))	a.Get_Buff()[(int)left.y][i] = '*';
			}
		}
		a.current(this->se());
}

