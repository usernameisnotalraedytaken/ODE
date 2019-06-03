#include<bits/stdc++.h>
using namespace std;
double f(double x, double y)
{
	return y - 2.0 * x / y;
}
/**
x, y: Init val
h: step length.
*/
double MEuler(double x, double y, double h)
{
	double Yn = y + h * f(x + h / 2.0, y + h / 2.0 * f(x, y));
	return Yn;
}
double RK2(double x, double y, double h)
{
	double Yn = y + h / 2.0 * (f(x, y) + f(x + h, y + h * f(x, y)));
	return Yn;
}
double RK4(double x, double y, double h)
{
	double K1 = f(x, y);
	double K2 = f(x + h / 2.0, y + h / 2.0 * K1);
	double K3 = f(x + h / 2.0, y + h / 2.0 * K2);
	double K4 = f(x + h, y + h * K3);
	double Yn = y + h / 6.0 * (K1 + 2.0 * K2 + 2.0 * K3 + K4);
	return Yn;
}
int main()
{
	double x = 0, y11 = 1, y12 = 1, y13 = 1, h = 0.1;
	cout << "M-Euler\tRK2\tRK4\tFunc" << endl;
	for(int i = 0; i <= 20; ++i)
	{
		y11 = RK4(x, y11, h);
		y12 = RK2(x, y12, h);
		y13 = MEuler(x, y13, h);
		x += h;
		cout << y13 << '\t' << y12 << '\t'  << y11 << '\t' << sqrt(x * 2 + 1) << endl;
	}
}
