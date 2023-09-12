#include<math.h>
#include <iostream>
using namespace std;

void check(double &n)
{
	while (!(cin >> n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error!" << "\n";
	}
}

double max(double &x, double &y, double &z) {
	if (x > y && x > z) return x;
	if (y > x && y > z) return y;
	else return z;
}

double min(double &x, double &y, double &z) {
	if (x + y > y - z) return y - z;
	else return x + y;
}

int main()
{
	double x, y, z;
	cout << "Let's calculate value m!" << "\n";
	cout << "Input x: ";
	check(x);
	cout << "Input y: ";
	check(y);
	cout << "Input z: ";
	check(z);

	if (max(x, y, z) == 0) {
		cout << "Error! Division by zero!\n";
		return 0;
	}

	cout << "m="<< min(x, y, z) / max(x, y, z);

	system("pause");
}

