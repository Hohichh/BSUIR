
#include <iostream>
using namespace std;


int main()
{
    const int N = 100;
    int arr[N];
    int n;
    cout << "input N: \n";
    cin >> n;
    if (cin.fail() || n <= 0 || n > 100) {
        cin.clear();
        cin.ignore();
        exit(0);
    }
    else cout << "ur array size is " << n << endl;

    cout << "ur array: \n";
    for (int i = 0; i < n; i++) { //максимальная нагрузка 
        arr[i] = rand() % 20;
        cout << arr[i] << " ";
    }
    float s = 0;
    for (int i = 0; i < n; i++) {//максимальная нагрузка 
        s += arr[i] * arr[i];
    }
    cout << "\nsrednee arifm. = " << s / n;
    return 0;
}
//Время: 19*3+n
//
//память n+3