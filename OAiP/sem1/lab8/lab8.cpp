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
void checkn(int &n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << "\n";
    }
}

double funkY(double x) {
    return(x * atan(x) - log(sqrt(1 + pow(x, 2))));
}

void Out_Rez(double f) {
    cout << f << "\n";
}

int main()
{
    cout << "Lets's calculate the function Y(x)!\n";
    double a, b, h;
    int n;
    cout << "Input first number of the range: ";
    check(a);
    cout << "Input last number of the range: ";
    check(b);
    cout << "Input increment h: ";
    check(h);
    cout << "Input parameter n(natural number): ";
    checkn(n);

    cout << "|Y(x)-S(x)| \n";

    for (int i = 1; a <= b; a += h, i++)
    {
        double s, f, y;
        s = 0;
        for (int k = 1; k <= n; k++)
        {
            s += pow(-1, k + 1) * (pow(a, 2 * k) / (2 * k * (2 * k - 1)));
        }
        f = fabs(s - funkY(a));
        Out_Rez(f);
    }

    system("pause");
}

