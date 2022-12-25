#include <iostream>
#include <math.h>
#define PI 3.1415926
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

int main()
{
	double u, x, y, z, modul;
	cout << "Let's calculate the value u" << "\n";
	cout << "Enter x: " ;
	check(x); 
	cout << "Enter y: ";
	check(y); 
	cout << "Enter z: ";
	check(z); 

	if (sin(z) == 1) {
		cout << "tangent 90 does not exist" << "\n";
		return 0;
	}

	modul = fabs(x - y);
	u = pow(8 + pow(modul, 2) + 1, 1./3) / (pow(x,2) + pow(y,2) + 2) - exp(modul) * pow(pow(tan(z), 2) + 1, x);
	cout << "u=" << u << "\n";

	system("pause");
}


