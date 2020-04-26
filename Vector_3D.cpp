#include "vector_3D.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

vector_3D::vector_3D() :x(vector_3D::Sx), y(vector_3D::Sy), z(vector_3D::Sz)
{
}
vector_3D::vector_3D(vector_3D& V) : x(V.x), y(V.y), z(V.z)
{
}
vector_3D::vector_3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_)
{
}
vector_3D::vector_3D(std::string str)
{
	if (str == "up") x = 0, y = 0, z = 1;
	else if (str == "down") x = 0, y = 0, z = -1;
	else if (str == "left") x = -1, y = 0, z = 0;
	else if (str == "right") x = 1, y = 0, z = 0;
	else if (str == "back")x = 0, y = -1, z = 0;
	else if (str == "front")x = 0, y = 1, z = 0;
	else x = 0, y = 0, z = 0;
}
void vector_3D::set_x()
{
	std::cin >> x;
}
void vector_3D::set_y()
{
	std::cin >> y;
}
void vector_3D::set_z()
{
	std::cin >> z;
}
double vector_3D::get_x()
{
	return x;
}
double vector_3D::get_y()
{
	return y;
}
double vector_3D::get_z()
{
	return z;
}
vector_3D vector_3D:: operator + (const vector_3D& vec)
{
	x = x + vec.x;
	y = y + vec.y;
	z = z + vec.z;
	return *this;
}
vector_3D vector_3D:: operator = (const vector_3D& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

std::ostream& operator <<(std::ostream& s, vector_3D& vec)
{
	s << "(" << vec.get_x() << ";" << vec.get_y() << ";" <<vec.get_z()<< ")";
	return s;
}

std::istream& operator >> (std::istream& s, vector_3D& vec)
{
	std::cout << "x = ";
	s >> vec.x;
	std::cout << "y = ";
	s >> vec.y;
	std::cout<<"z = ";
	s>> vec.z;
	
	return s;
}

double vector_3D::get_len()
{
	double len = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return len;
}
void vector_3D::pr_on_scal(int cnt)
{
	x *= cnt;
	y *= cnt;
	z *= cnt;
}
double vector_3D::scl_prd(vector_3D& vec)
{
	return x*(vec.x) + y*(vec.y)+z*(vec.z);
}
void vector_3D::normalize()
{
	x /= (*this).get_len();
	y /= (*this).get_len();
	z /= (*this).get_len();
}
void vector_3D::proection()
{
	z = 0;
}
bool vector_3D:: operator == (const vector_3D& vec)
{
	if (x == vec.x&&y == vec.y&&z == vec.z) return true;
	else return false;
}
bool vector_3D:: operator != (const vector_3D& vec)
{
	if (x != vec.x&&y != vec.y&&z != vec.z) return true;
	else return false;
}
vector_3D vector_3D::operator - (const vector_3D& vec)
{
	x = x - vec.x;
	y = y - vec.y;
	z = z - vec.z;
	return *this;
}
bool vector_3D::operator < (const vector_3D& vec)
{
	if (x < vec.x&&y < vec.y&&z < vec.z) return true;
	else return false;
}
bool vector_3D::operator > (const vector_3D& vec)
{
	if (x > vec.x&&y > vec.y&&z > vec.z) return true;
	else return false;
}
bool vector_3D::operator <= (const vector_3D& vec)
{
	if (x <= vec.x&&y <= vec.y&&z <= vec.z) return true;
	else return false;
}
bool vector_3D::operator >= (const vector_3D& vec)
{
	if (x >= vec.x&&y >= vec.y&&z >= vec.z) return true;
	else return false;
}
vector_3D vector_3D::operator +=(const vector_3D& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}
vector_3D vector_3D::operator -=(const vector_3D& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}
void vector_3D::turn(double angle1, double angle2, double angle3)
{
	double newx, newy, newz;
	angle1 = angle1 * M_PI / 180;
	angle2 = angle2 * M_PI / 180;
	angle2 = angle2 * M_PI / 180;
	double c1 = cos(angle1);
	double c2 = cos(angle2);
	double c3 = cos(angle3);
	double s1 = sin(angle1);
	double s2 = sin(angle2);
	double s3 = sin(angle3);
	newx = x * (c1 * c3 - s1 * c2 * s3) + y * (c1 * s3 + s1 * c2 * c3) + z * s1 * s2;
	newy = x * (-s1 * c3 - c1 * c2 * s3) + y * (-s1 * s3 + c1 * c2 * c3) + z * c1 * s2;
	newz = x * s2 * s3 + y * (-s2) * c3 + z * c2;
	x = newx;
	y = newy;
	z = newz;
}
vector_3D vector_3D::operator *(const double constant)
{
	x *= constant;
	y *= constant;
	z *= constant;
	return *this;
}
double vector_3D::operator *(const vector_3D&vec)
{
	return  x*vec.x + y*vec.y + z*vec.z;
}