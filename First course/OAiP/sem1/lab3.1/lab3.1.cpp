#include <iostream>
using namespace std;

void check(double &n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << "\n";
    }
}

double funkY(double x) {
    return(-log(fabs(2 * sin(x / 2)))) ;
}

int main()
{
    cout << "Lets's calculate the function Y(x)!\n";
    double a, b, h, max, min;
    cout << "Input first number of the range: ";
    check(a);
    cout << "Input last number of the range: ";
    check(b);
    cout << "Input increment: ";
    check(h);

    max = funkY(a);
    min = funkY(a);
    for (int i = 1; a <= b; a += h, i++)
    {
        cout << i << "\t" << a << "\t" << funkY(a) << "\n";
        if (min > funkY(a)) min = funkY(a);
        if (max < funkY(a)) max = funkY(a);
    }
    cout << "min = " << min << "; max= " << max << "\n";

    system("pause"); 
}
