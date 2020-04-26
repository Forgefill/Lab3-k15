#pragma once
#include<iostream>

class vector_2D
{
private:
	double x;
	double y;
public:
	vector_2D();
	vector_2D(vector_2D&);
	vector_2D(double, double);
	vector_2D(std::string);
	void set_x();
	void set_y();
	double get_x();
	double get_y();
	double get_len();
	void pr_on_scal(int);
	void normalize();
	void turn(double);
	double scl_prd(vector_2D&);
	bool operator == (const vector_2D&);
	bool operator != (const vector_2D&);
	bool operator < (const vector_2D&);
	bool operator > (const vector_2D&);
	bool operator >= (const vector_2D&);
	bool operator <= (const vector_2D&);
	double operator * (const vector_2D&);
	vector_2D operator *(const double);
	vector_2D operator +=(const vector_2D&);
	vector_2D operator -=(const vector_2D&);
	vector_2D operator - (const vector_2D&);
	vector_2D operator + (const vector_2D&);
	vector_2D operator = (const vector_2D&);
	friend std::istream& operator >> (std::istream&, vector_2D&);
	const double Sx = 0;
	const double Sy = 0;
};

std::ostream& operator <<(std::ostream&, vector_2D&);