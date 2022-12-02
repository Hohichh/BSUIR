#include<math.h>
#include <iostream>
#include <stdio.h>
using namespace std;

double sqr(double n)
{
	return pow(n, 2);
}
void check(double &n) {
	while (!(cin >> n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error!" << "\n";
	}
}
void checkdiv(double &d) {
	if (d == 0) {
		cout << "Error! Division by 0" << "\n";
		exit(0);
	}
}
void checksqrt(double s) {
	if (s < 0) {
		cout << "Error! Minus under the sign of the arithmetic root" << "\n";
		exit(0);
	}
}

int main()
{
	double x, z, a, b, den;
	cout << "calculate the value y!" << "\n";
	cout << "input a: ";
	check(a);
	cout << "input b: ";
	check(b);
	cout << "input z: ";
	check(z);

	if (z<a*b)
	{
		checksqrt(sqr(a) + sqr(a) * z);
		x = sqrt(sqr(a) + sqr(a)*z);
		cout << "z<a*b. Calculations are made according to the first option" << "\n";
	}

	if (z>=a*b)
	{
		x = sqr(sin(z)) + fabs(a * b * z);
		cout << "z>=a*b. Calculations are made according to the second option" << "\n";
	}
	den = x + a * b;
	checkdiv(den);

	cout <<"y="<< a * x + b * x * cos(sqrt(x)) / den << "\n";

	system("pause");
}

