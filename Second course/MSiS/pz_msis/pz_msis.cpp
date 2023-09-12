#include<ctime>
#include <iostream>
using namespace std;
int main()
{
    srand(time(0));
    const int N = 100;
    int arr[N];
    int n, x;
    cout << "input N: \n";
    cin >> n;
    cout << "ur array: \n";
    for (int i = 0; i < n; i++) {

        arr[i] = rand() % 20;
        cout << arr[i] << " ";
    }
    float s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i] * arr[i];

    }
    cout << "\nsrednee arifm. = " << s / n;
    cout << "\ntime = " << clock()/1000.0;
    return 0;
}

