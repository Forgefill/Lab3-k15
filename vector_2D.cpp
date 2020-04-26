#include "vector_2D.h"
#include <iostream>
#define PI 3.14159265


vector_2D::vector_2D() :x(Sx),y(Sy)
{
}
vector_2D::vector_2D(vector_2D& V) : x(V.x),y(V.y)
{
}
vector_2D::vector_2D(double x_, double y_): x(x_),y(y_)
{
}
vector_2D::vector_2D(std::string str)
{
	if (str == "up") x = 0, y = 1;
	else if (str == "down") x = 0, y = -1;
	else if (str == "left") x = -1, y = 0;
	else if (str == "right") x = 1, y = 0;
	else x = 0, y = 0;
}
void vector_2D::set_x()
{
	std::cin >> x;
}
void vector_2D::set_y()
{
	std::cin >> y;
}
double vector_2D::get_x()
{
	return x;
}
double vector_2D::get_y()
{
	return y;
}
vector_2D vector_2D:: operator + (const vector_2D& vec)
{ 
	x = x + vec.x;
	y = y + vec.y;
	return *this;
}
vector_2D vector_2D:: operator = (const vector_2D& vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

std::ostream& operator <<(std::ostream& s, vector_2D& vec)
{
	s << "(" << vec.get_x() << ";" << vec.get_y() << ")";
	return s;
}

std::istream& operator >> (std::istream& s, vector_2D& vec)
{
	std::cout << "x = ";
	s >> vec.x;
	std::cout << "y = ";
	s >> vec.y;
	return s;
}

double vector_2D::get_len()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}
void vector_2D::pr_on_scal(int cnt)
{
	x *= cnt;
	y *= cnt;
}
double vector_2D::scl_prd(vector_2D& vec)
{
	return x*(vec.x) + y*(vec.y);
}
void vector_2D::normalize()
{
	x /= (*this).get_len();
	y /= (*this).get_len();
}
void vector_2D::turn(double angle)
{  
	double x1, y1, E = 0.000001;
	x1 = x*cos(angle * PI / 180) - y*sin(angle * PI / 180);
	y1 = x*sin(angle * PI / 180) + y*cos(angle * PI / 180);
	if (x1 < E&&x1>-E) x1 = 0;
	if (y1 < E&&y1>-E) y1 = 0;
	x = x1;
	y = y1;
}
bool vector_2D:: operator == (const vector_2D& vec)
{
	if (x == vec.x&&y == vec.y) return true;
	else return false;
}
bool vector_2D:: operator != (const vector_2D& vec)
{
	if (x != vec.x&&y != vec.y) return true;
	else return false;
}
vector_2D vector_2D::operator - (const vector_2D& vec)
{
	x = x - vec.x;
	y = y - vec.y;
	return *this;
}
bool vector_2D::operator < (const vector_2D& vec)
{
	if (x < vec.x&&y < vec.y) return true;
	else return false;
}
bool vector_2D::operator > (const vector_2D& vec)
{
	if (x > vec.x&&y > vec.y) return true;
	else return false;
}
bool vector_2D::operator <= (const vector_2D& vec)
{
	if (x <= vec.x&&y <= vec.y) return true;
	else return false;
}
bool vector_2D::operator >= (const vector_2D& vec)
{
	if (x >= vec.x&&y >= vec.y) return true;
	else return false;
}
vector_2D vector_2D::operator +=(const vector_2D& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}
vector_2D vector_2D::operator -=(const vector_2D& vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}
vector_2D vector_2D::operator *(const double constant)
{
	x *= constant;
	y *= constant;
	return *this;
}
double vector_2D::operator *(const vector_2D&vec)
{
	return  x*vec.x + y*vec.y;
}