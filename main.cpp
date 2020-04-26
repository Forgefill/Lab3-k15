#include<iostream>
#include "vector_2D.h"
#include "vector_3D.h"
#include <fstream>
#include <cmath>
#define PI 3.14159265

int main()
{
	std::string str = "behind";
	vector_3D vec1(str);
	vector_2D vec2(10, 20),vec3(vec2);
	std::cout << vec2 << "\n";
	if (vec2 == vec3) std::cout << vec2 * 2 * (vec2 * 3 - vec3 * 3);
	system("pause");
	return 0;
}