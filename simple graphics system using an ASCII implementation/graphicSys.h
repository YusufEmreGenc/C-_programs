#include <iostream>
using namespace std;

class Point
{
public:
	double x, y;
public:
	Point(double i=0, double j=0)	:x(i), y(j)	{}

	void Set(double i, double j) { x = i, y = j; }

	Point right(int i=1);
	Point left(int i=1);
	Point up(int i=1);
	Point down(int i=1);

	Point(const Point& a)
	{
		x = a.x;
		y = a.y;
	}

	Point& operator=(const Point& a)
	{
		x = a.x;
		y = a.y;
		return *this;
	}

	Point operator-(const Point& a)
	{
		Point temp;
		temp.x = x - a.x;
		temp.y = y - a.y;
		return temp;
	}

	Point operator+(const Point& a)
	{
		Point temp;
		temp.x = x + a.x;
		temp.y = y + a.y;
		return temp;
	}

	bool operator!=(const Point& a)
	{
		return (x != a.x || y != a.y) ? true : false;
	}
	
	Point operator/(double a);

	void vector();
};

class DispWindow
{
protected:
	char **p;
	Point curr;
	int x, y;
public:
	DispWindow(int i=0, int j=0)
		:x(i), y(j)
	{
		p = new char*[y];
		for (int a = 0; a < y; a++)
			p[a] = new char[x];

		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
				p[i][j] = ' ';
	}
		
	char** Get_Buff() { return p; }

	Point current();
	void current(Point p);

	bool inBuff(Point);

	template<class T>
	void draw(T s)
	{
		s.draw(*this);
	}
		
	void show()
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
				cout << p[i][j];
			cout << endl;
		}
	}
	
	~DispWindow()
	{
		for (int i = 0; i < y; i++)
			delete[] p[i];
		delete[] p;
	}
};

class Shape
{
private:

public:
	virtual void draw(DispWindow &a) = 0;
};

class Dot : public Shape
{
private:
	Point m_p;
public:
	Dot(Point p)	:m_p(p)	{}

	void draw(DispWindow &a);
};

class Line : public Shape
{
private:
	Point p1;
	Point p2;
public:
	Line(Point x, Point y)
		:p1(x), p2(y)	{}

	Point c() { return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2); }
	Point n() { return (p1.y > p2.y) ? (p1) : (p2); }
	Point s() { return (p1.y < p2.y) ? (p1) : (p2); }
	Point e() { return (p1.x > p2.x) ? (p1) : (p2); }
	Point w() { return (p1.x < p2.x) ? (p1) : (p2); }
	Point nw()
	{
		if (p1.y == p2.y)	return w();
		return (p1.y > p2.y) ? (p1) : (p2);
	}
	Point ne()
	{
		if (p1.y == p2.y)	return e();
		return (p1.y > p2.y) ? (p1) : (p2);
	}
	Point sw()
	{
		if (p1.y == p2.y)	return w();
		return (p1.y < p2.y) ? (p1) : (p2);
	}
	Point se()
	{
		if (p1.y == p2.y)	return e();
		return (p1.y < p2.y) ? (p1) : (p2);
	}

	void draw(DispWindow& a);
};

class Rectangle: public Shape
{
private:
	Point p1;
	Point p2;
public:
	Rectangle(Point x, Point y)
	{
		p1 = x;
		p2 = y;
	}

	Point c() { return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2); }
	Point n() {	return (p1.y < p2.y) ? (Point(((p1.x + p2.x) / 2), p1.y)) : (Point((p1.x + p2.x) / 2, p2.y)); }
	Point s() {	return (p1.y > p2.y) ? (Point(((p1.x + p2.x) / 2), p1.y)) : (Point((p1.x + p2.x) / 2, p2.y)); }
	Point e() { return (p1.x > p2.x) ? (Point(p1.x, (p1.y + p2.y) / 2)) : (Point(p2.x, (p1.y + p2.y) / 2)); }
	Point w() { return (p1.x < p2.x) ? (Point(p1.x, (p1.y + p2.y) / 2)) : (Point(p2.x, (p1.y + p2.y) / 2)); }
	Point ne()
	{ 
		int max_x = (p1.x > p2.x) ? (p1.x) : (p2.x);
		int min_y = (p1.y < p2.y) ? (p1.y) : (p2.y);
		return Point(max_x, min_y); 
	}
	Point nw() 
	{ 
		int min_x = (p1.x < p2.x) ? (p1.x) : (p2.x);
		int min_y = (p1.y < p2.y) ? (p1.y) : (p2.y);
		return Point(min_x, min_y);
	}
	Point se()
	{
		int max_x = (p1.x > p2.x) ? (p1.x) : (p2.x);
		int max_y = (p1.y > p2.y) ? (p1.y) : (p2.y);
		return Point(max_x, max_y);
	}
	Point sw() 
	{ 
		int min_x = (p1.x < p2.x) ? (p1.x) : (p2.x);
		int max_y = (p1.y > p2.y) ? (p1.y) : (p2.y);
		return Point(min_x, max_y);
	}

	void draw(DispWindow& a);
};
