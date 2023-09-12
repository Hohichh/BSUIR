#include <iostream>
#include <math.h>
using namespace std;

void check(double &n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << "\n";
    }
}

double funkY(double x) {
    return(x * atan(x) - log(sqrt(1 + pow(x, 2))));
}

double funkS(int n, double a) {
    double s = 0;
    for (int k = 1; k <= n; k++)
    {
        s += pow(-1, k + 1) * (pow(a, 2 * k) / (2 * k * (2 * k - 1)));
    }
    return s;
}

int main()
{
    double a, b, h, s, e;
    int n;
    cout << "Input first number of the range: ";
    check(a);
    cout << "Input last number of the range: ";
    check(b);
    cout << "Input increment h: ";
    check(h);
    cout << "Input increment Epsilon: ";
    check(e);

    cout << "No\tn\t  Y(x)\t  S(x)\t  |Y(x) - S(x)|\n";
    
    for (int i = 1; a <= b; a += h, i++)
    {
        n = 1;
        while (fabs(funkS(n, a) - funkY(a)) >= e) { n++; }
        cout << i << "\t" << n <<"\t " << funkY(a) << "\t    " << funkS(n, a) << "\t   " << fabs(funkY(a) - funkS(n, a)) <<  "\n";
    }

    system("pause");
}

