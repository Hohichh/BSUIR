#include <iostream>
#include <math.h>
#define PI 3.1415926
using namespace std;

void check(double &n) {
	while (!(cin >> n) || (cin.peek() != '\n'))	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error!" << "\n" ;
	}
}

int main()
{
	double a, z1, z2;
	cout << "Let's calculate the value z1, z2." << "\n";
	cout << "Enter the angle: ";
	check(a);

	if (1 - sin(3 * a - PI) == 0) {
		cout << "Error! Diviion by zero." << "\n";
		return 0;
	}
	z1 = sin(PI / 2 + 3 * a) / (1 - sin(3 * a - PI));
	
	if (sin(5 / 4 * PI + 3 / 2 * a) == 1) {
		cout << "Tangent 90 degrees does not exist" << "\n";
		return 0;
	}

	if (tan(5 / 4 * PI + 3 / 2 * a) == 0) {
		cout << "Cotangent 180 degrees does not exist." << "\n";
		return 0;
	}
	z2 = 1 / tan(5 / 4 * PI + 3 / 2 * a);

	cout << "z1=" << z1 << "\n";
	cout << "z2=" << z2 << "\n";
	
	system("pause");
}

