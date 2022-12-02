#include<math.h>
#include <iostream>
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

void checkopt(int &n) {
	while (!(cin >> n) || (cin.peek() != '\n') /*|| (n < 1) || (n > 3)*/)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error! Wrong option." << "\n";
	}
}

int main()
{
    double funk, x, z, a, b, den; 
	cout << "Calculate the value y!" << "\n";
	cout << "Input a: ";
	check(a);
	cout << "Input b: ";
	check(b);
	cout << "Input z: ";
	check(z);
	
	if (z < 1)
	{
		x = 2 + z;
		cout << "z<1. Calculations are made according to the first option" << "\n";
	}
	if (z >= 1)
	{
		x = sqr(sin(z));
		cout << "z>=1. Calculations are made according to the second option" << "\n";
	}

	cout << "Choose one of the functions(number):" << "\n";
	cout << "1)2x" "\t" "2)x^2" "\t" "3)x/3" << "\n";

	int option;
	checkopt(option);
	switch (option) {
	case 1:
		funk = 2 * x;
		break;
	case 2:
		funk = sqr(x);
		break;
	case 3:
		funk = x/3;
		break;
	default:
		cout << "Wrong option!\n";
		return 0;
	}

	den = sqr(x)+5;
	cout << "y=" << 2 * a * funk + b * cos(sqrt(fabs(x))) / den << "\n";

	system("pause");
}

