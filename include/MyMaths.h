#ifndef MYMATHS_H
#define MYMATHS_H
class Vector2D		//VECTOR CLASS
{
public:
	float x;
	float y;
	//DECLARING DEFAULTS AND OVERLOADS
	Vector2D();
	Vector2D(float, float);
	void Set(float ax, float ay);

	//OVERLOADS
	void operator=(Vector2D &a);

	//GETTING VALUES
	float Length();
	float Normal();
	float Magnitude();
};

class Vector3D		//VECTOR CLASS
{
public:
	float x;
	float y;
	float z;
	//DECLARING DEFAULTS AND OVERLOADS
	Vector3D();
	Vector3D(float, float, float);
	void Set(float ax, float ay, float az);

	//OVERLOADS
	void operator=(Vector3D &a);

	//GETTING VALUES
	float Length();
	float Normal();
	float Magnitude();
};


class Point2D		//POINT CLASS
{
public:
	float x;
	float y;
	//CONSTRUCTORS
	Point2D();
	Point2D(float, float);
	//SETTING VALUES
	void Set(float ax, float ay);
};

class Circle	//CIRCLE CLASS
{
public:
	float x;
	float y;
	float r;
	Circle();
	Circle(float XPOS, float YPOS, float RADIUS);
	void Set(float XPOS, float YPOS, float RADIUS);
};

class Line		//LINE CLASS
{
public:
	float X1;
	float Y1;
	float X2;
	float Y2;
	//CONSTRUCTORS
	Line();
	Line(Point2D, Point2D);
	//SETTING VALUES
	void Set(float startx, float starty, float endx, float endy);
	void Set(Point2D a_point1, Point2D a_point2); //SET OVERLOAD USING POINT CLASS
	//GETTING VALUES
	float Length();
	float LengthX();
	float LengthY();
	Point2D Start();
	Point2D End();
	Vector2D GetVector();//GETTING LINE AS VECTOR (FOR SOME REASON)
};

class Box		//BOX CLASS
{
private:
	float X1, Y1, X2, Y2;
public:
	//CONSTRUCTORS
	Box();
	Box(Point2D, Point2D);
	Box(float, float, float, float);
	//SETTING VALUES
	void Set(float ax, float ay, float ax2, float ay2);
	void Set(Point2D p1, Point2D p2); //SET OVERLOAD USING POINTS
	//GETTING VALUES
	Point2D GetLeftBot();
	Point2D GetLeftTop();
	Point2D GetRightBot();
	Point2D GetRightTop();
	Line GetBotLine();
	Line GetRightLine();
	Line GetTopLine();
	Line GetLeftLine();
};



float Dot(Vector2D a, Vector2D b);		//DOT PRODUCT OF TWO VECTORS

bool CheckPointBox(Point2D p, Box b);		//POINT-BOX COLLISION
	
bool CheckCircleCircle(Circle a, Circle b);		//CIRCLE-CIRCLE COLLISION

bool CheckCircleCircle(float ax, float ay, float ar, float bx, float by, float br);		//CIRCLE-CIRCLE OVERLOAD

bool CheckLineLine(Line l1, Line l2);				//NOT DONE YET BECAUSE NOT DONE YET

bool IsWithin(float anum, float amin, float amax);		//IF GIVEN NUMBER IS WITHIN GIVEN RANGE

bool CheckBoxBox(Box b1, Box b2);		//BOX-BOX COLLISION - ONLY CHECKS POINTS NOT LINES

float Distance(Point2D a, Point2D b);	//DISTANCE BETWEEN TWO POINTS

float Distance(float ax, float ay, float bx, float by);		//DISTANCE OVERLOAD

bool CheckPointCircle(Point2D p, Circle c);

bool CheckPointCircle(float px, float py, float cx, float cy, float cr);

bool CheckLineCircle(Circle a, Line seg);

bool CheckLineCircle(float ax, float ay, float ar, float lx, float ly);





#endif