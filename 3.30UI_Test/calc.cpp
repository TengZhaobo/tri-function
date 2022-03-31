#include <iostream>
#include <cstdlib>
#include <iomanip>
#include"calc.h"
#include "pch.h"
constexpr auto PI = 3.1415926;

//int menu_select() {
//	int select;
//	std::cout << "-------Welcome to Snow Calculator-------" << std::endl;
//	std::cout << "               1. sin x                 " << std::endl;
//	std::cout << "               2. cos x                 " << std::endl;
//	std::cout << "               3. arcsin x              " << std::endl;
//	std::cout << "               4. arctan x              " << std::endl;
//	std::cout << "               5. Clean screen          " << std::endl;
//	std::cout << "               0. to quit               " << std::endl;
//	std::cout << "----------------------------------------" << std::endl;
//	std::cin >> select;
//	return select;
//}

//double inputtrans(void) 
double inputtrans(double x)
{
	//double x;

	//std::cout << "Please input x: " << std::endl;
	//std::cin >> x;
	while (x >= 360.0)//设置x的范围
	{
		x -= 360.0;
	}
	return (x * PI / 180.0);//角度or弧度
}


//double inputasin(void)
//{
//	double x;
//	//std::cout << "Please input x: " << std::endl;
//	//std::cin >> x;
//	while (x > 1 || x < -1)
//	{
//		//std::cout << "输入错误，请重新输入:" << std::endl;
//		//std::cin >> x;
//	}
//
//	return x;
//}

double factorial(double n) {//阶乘
	if (n <= 1) {
		return n;
	}
	else {
		return n * factorial(n - 1);
	}
}


//下面为求绝对值函数
double myabs(double num1)
{
	return((num1 > 0) ? num1 : -num1);
}

//下面为求sin(x)的值
double snowsin(double num2)
{
	while (num2 >= 360.0)//设置x的范围
	{
		num2 -= 360.0;
	}
	num2 = (num2 * PI / 180.0);
	int i = 1, negation = 1;//取反
	double sum;
	double index = num2;//指数
	double Factorial = 1;//阶乘
	double TaylorExpansion = num2;//泰勒展开式求和
	do
	{
		Factorial = Factorial * ((__int64)i + 1) * ((__int64)i + 2);//求阶乘
		index *= num2 * num2;//求num2的次方
		negation = -negation;//每次循环取反
		sum = index / Factorial * negation;
		TaylorExpansion += sum;
		i += 2;
	} while (myabs(sum) > 1e-15);
	return(TaylorExpansion);
}

//求cos
double snowcos(double x)
{
	double sin = snowsin(x);//先求出SIN的值
	double cos = 1 - sin * sin;//在通过公式减去SIN

	return sqrt(cos);//开方
}

//求arcsin x的范围要变化（-1，1）
float snowarcsin(float x)
{
	float result = x, result_a = 1.0f, result_b = 1.0f, result_c = 1.0f;//定义变量
	unsigned int i = 0, ii = 0;//此方法有一定的精度误差，越靠近1精度误差越大
	for (i = 0; i < 1000; i++)
	{
		for (ii = 0; ii < (2 * i + 1); ii++)
		{
			result_a *= (float)(2 * ii + 1) / (float)(2 * ii + 2);
			result_b *= (x*x);
		}
		result_b = x;
		result_c = result_a / (float)(ii + 2);
		result += (float)(result_c)*(float)result_b;
		result_a = 1.0f; result_a = 1.0f;

	}
	return result;

}

double snowarctan(double x) {
	double sqr = x * x;
	double e = x;
	double r = 0;
	int i = 1;
	if (e >= -1 && e <= 1)//泰勒级数
	{
		while (fabs(e / i) > 1e-7)
		{
			double f = e / i;
			r = (i % 4 == 1) ? r + f : r - f;
			e = e * sqr;
			i += 2;
		}
	}
	if (e <= -1 || e >= 1)//arctan(x)+arctan(1/x)=π/2
	{
		e = 1 / e;
		double h = e * e;
		while (fabs(e / i) > 1e-7)
		{
			double f = e / i;
			r = (i % 4 == 1) ? r + f : r - f;
			e = e * h;
			i += 2;
		}
		if (e > 0)
			r = PI / 2 - r;
		else
			r = -PI / 2 - r;
	}
	return r;
}