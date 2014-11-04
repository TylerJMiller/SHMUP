#include "MyMaths.h"
#include <math.h>

										//VECTOR2D
void Vector2D::Set(float ax, float ay)
{
	x = ax;
	y = ay;
}
float Vector2D::Length()
{
	return sqrt((x * x) + (y * y));
}
float Vector2D::Magnitude()
{
	return (x * x) + (y * y);
}
float Vector2D::Normal()
{
	float a = ((x / Length())*(x / Length())) + ((y / Length())*(y / Length()));
	return (sqrt(a));
}
//CONSTRUCTOR
Vector2D::Vector2D()
{
}
Vector2D::Vector2D(float ax, float ay)
{
	x = ax;
	y = ay;
}

										//POINT
void Point2D::Set(float ax, float ay)
{
	x = ax;
	y = ay;
}
//CONSTRUCTOR
Point2D::Point2D()
{
}
Point2D::Point2D(float ax, float ay)
{
	x = ax;
	y = ay;
}

										//CIRCLE
Circle::Circle()
{
}
Circle::Circle(float XPOS, float YPOS, float RADIUS)
{
	x = XPOS;
	y = YPOS;
	r = RADIUS;
}
void Circle::Set(float XPOS, float YPOS, float RADIUS)
{
	x = XPOS;
	y = YPOS;
	r = RADIUS;
}

										//LINE
void Line::Set(float startx, float starty, float endx, float endy)
{
	X1 = startx;
	Y1 = starty;
	X2 = endx;
	Y2 = endy;
}
void Line::Set(Point2D a_point1, Point2D a_point2)
{
	X1 = a_point1.x;
	Y1 = a_point1.y;
	X2 = a_point2.x;
	Y2 = a_point2.y;
}
float Line::Length()
{
	return (((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
}
float Line::LengthX()
{
	return (X2 - X1);
}
float Line::LengthY()
{
	return (Y2 - Y1);
}
Vector2D Line::GetVector()
{
	Vector2D v(LengthX(), LengthY());
	return v;
}
Point2D Line::Start()
{
	Point2D v(X1, Y1);
	return v;
}
Point2D Line::End()
{
	Point2D v(X2, Y2);
	return v;
}
//CONSTRUCTOR
Line::Line(Point2D a_point1, Point2D a_point2)
{
	X1 = a_point1.x;
	Y1 = a_point1.y;
	X2 = a_point2.x;
	Y2 = a_point2.y;
}

										//BOX
Point2D Box::GetLeftBot()
{
	Point2D p(X1, Y1);
	return p;
}
Point2D Box::GetLeftTop()
{
	Point2D p(X1, Y2);
	return p;
}
Point2D Box::GetRightBot()
{
	Point2D p(X2, Y1);
	return p;
}
Point2D Box::GetRightTop()
{
	Point2D p(X2, Y2);
	return p;
}
Line Box::GetBotLine()
{
	Line l(GetLeftBot(), GetRightBot());
	return l;
}
Line Box::GetRightLine()
{
	Line l(GetRightBot(), GetRightTop());
	return l;
}
Line Box::GetTopLine()
{
	Line l(GetRightTop(), GetLeftTop());
	return l;
}
Line Box::GetLeftLine()
{
	Line l(GetLeftTop(), GetLeftBot());
	return l;
}
void Box::Set(float ax, float ay, float ax2, float ay2)
{
	X1 = ax;
	Y1 = ay;
	X2 = ax2;
	Y2 = ay2;
}
void Box::Set(Point2D p1, Point2D p2)
{
	X1 = p1.x;
	Y1 = p1.y;
	X2 = p2.x;
	Y2 = p2.y;
}
//CONSTRUCTORS
Box::Box()
{
}
Box::Box(Point2D p1, Point2D p2)
{
	X1 = p1.x;
	Y1 = p1.y;
	X2 = p2.x;
	Y2 = p2.y;
}

Box::Box(float ax1, float ay1, float ax2, float ay2)
{
	X1 = ax1;
	Y1 = ay1;
	X2 = ax2;
	Y2 = ay2;
}

float Dot(Vector2D a, Vector2D b)		//DOT PRODUCT OF TWO VECTORS
{
	return ((a.x * b.x) + (a.y * b.y));
}

bool CheckPointBox(Point2D p, Box b)		//POINT-BOX COLLISION
{
	if (p.x > b.GetLeftBot().x && p.x < b.GetRightTop().x && p.y > b.GetLeftBot().y && p.y < b.GetRightTop().y)
		return true;
	return false;
}

bool CheckCircleCircle(Circle a, Circle b)	//COLLISION BETWEEN TWO CIRCLES
{
	return (a.r + b.r) > Distance(a.x, a.y, b.x, b.y);
}

bool CheckCircleCircle(float ax, float ay, float ar, float bx, float by, float br)	//CIRCLE CIRCLE OVERLOAD
{
	return (ar + br) > Distance(ax, ay, bx, by);
}

bool CheckLineLine(Line l1, Line l2)				//NOT DONE YET BECAUSE NOT DONE YET
{

	return false;
}

bool IsWithin(float anum, float amin, float amax)		//IF A GIVEN NUMBER IS BETWEEN TWO GIVEN NUMBERS
{
	if (anum >= amin && anum <= amax)
		return true;
	return false;
}

bool CheckBoxBox(Box b1, Box b2)		//BOX-BOX COLLISION - AABB ONE WAY
{
	if (CheckPointBox(b1.GetLeftBot(), b2) || CheckPointBox(b1.GetRightBot(), b2) || CheckPointBox(b1.GetRightTop(), b2) || CheckPointBox(b1.GetLeftTop(), b2))
		return true;
	return false;
}

float Distance(Point2D a, Point2D b)		//DISTANCE BETWEEN TWO POINTS
{
	return (((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}

float Distance(float ax, float ay, float bx, float by)
{
	if (((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)) == 0)
		return 0;
	return sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)));
}

bool CheckPointCircle(Point2D p, Circle c)
{
	if (Distance(p.x, p.y, c.x, c.y) < c.r)
		return true;
	return false;
}

bool CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
	if (Distance(px, py, cx, cy) <= cr)
		return true;
	return false;
}

bool CheckLineCircle(Circle c, Line l)
{
	Vector2D v1(l.X2 - l.X1, l.Y2 - l.Y1);
	Vector2D v2(c.x - l.X1, c.y - l.Y1);

	if (CheckPointCircle(l.Start(), c))
		return true;
	if (CheckPointCircle(l.End(), c))
		return true;

	Vector2D v3((Dot(v2, v1) / v1.Magnitude()) * v1.x, (Dot(v2, v1) / v1.Magnitude()) * v1.y);

	if (v3.Length() > v1.Length())
		return false;

	if (CheckPointCircle(v3.x,v3.y,v2.x,v2.y,c.r))
		return true;

	return false;
}