#include <iostream>
#include <math.h>
#define PI 3.1415926
using namespace std;

int main()
{
	double a, z1, z2;
	cout << "Let's calculate the value z1, z2."<< "\n";
	cout << "Enter an angle: ";
	cin >> a;
	
	z1 = cos(a) + cos(3 * a) + sin(a) + sin(3 * a);
	cout << "z1="<< z1 << "\n";

	z2 = 2 * sqrt(2) * cos(a) * sin(PI / 4 + 2 * a);
	cout << "z2=" << z2 << "\n";

	system("pause");
} 

