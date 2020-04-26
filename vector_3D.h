#pragma once
#include<iostream>

class vector_3D
{
private:
	double x;
	double y;
	double z;
public:
	vector_3D();
	vector_3D(vector_3D&);
	vector_3D(double, double, double);
	vector_3D(std::string);
	void set_x();
	void set_y();
	void set_z();
	double get_x();
	double get_y();
	double get_z();
	double get_len();
	void pr_on_scal(int);
	void normalize();
	void proection();
	void turn(double, double, double);
	double scl_prd(vector_3D&);
	bool operator == (const vector_3D&);
	bool operator != (const vector_3D&);
	bool operator < (const vector_3D&);
	bool operator > (const vector_3D&);
	bool operator >= (const vector_3D&);
	bool operator <= (const vector_3D&);
	vector_3D operator *(const double);
	double operator *(const vector_3D&);
	vector_3D operator - (const vector_3D&);
	vector_3D operator + (const vector_3D&);
	vector_3D operator = (const vector_3D&);
	vector_3D operator +=(const vector_3D&);
	vector_3D operator -=(const vector_3D&);
	friend std::istream& operator >> (std::istream&, vector_3D&);
	const double Sx = 0;
	const double Sy = 0;
	const double Sz = 0;
};
std::ostream& operator <<(std::ostream&, vector_3D&);