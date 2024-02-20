
#include <iostream>
using namespace std;

int check_prime(int);

int main() {

    int n1, n2;
    string ch;
    bool flag;

    cout << "Enter two positive integers: ";
    cin >> n1 >> n2;

    // swapping n1 and n2 if n1 is greater than n2
    if (n1 > n2) {
        n2 = n1 + n2;
        n1 = n2 - n1;
        n2 = n2 - n1;
    }

    cout << "Prime numbers between " << n1 << " and " << n2 << " are:\n";

    for (int i = n1 + 1; i < n2; ++i) {
        // if i is a prime number, flag will be equal to 1
        flag = check_prime(i);

        switch (i) {
        case 1:
            cout << "i equals 1" << endl;
            break;
        case 2:
            cout << "i equals 2" << endl;
            break;
        case 3:
            cout << "i equals 3" << endl;
            break;
        default:
            cout << "i not equal 1, 2 or 3" << endl;
            break;
        }

        if (flag)
            cout << i << ", " << endl;
    }

    return 0;
}

// user-defined function to check prime number
int check_prime(int n) {
    bool is_prime = true;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        is_prime = false;
    }

    for (int j = 2; j <= n / 2; ++j) {
        if (n % j == 0) {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}
