#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void check(int &n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {            //checking for numeric input
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << "\n";
    }
}
void checkarr(int &n) {
    while (!(cin >> n) || (cin.peek() != '\n') || (n <= 0)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << "\n";
    }
}
int main()
{
	int n, m;
	int **arr;                                     //matrix arr[n][m]
	cout << "enter matrix size:\n";
    checkarr(n);
    checkarr(m);
	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

    int* b;
    b = new int[n];                                 //vector b   

    cout << "Do you want to fill in elements of array randomly or manually?\n";
    cout << "1 -- randomly\t 2 -- manually\n";
 
    int option;
    check(option);
    switch (option) {
    case 1:              //random
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = rand()%40 + (-20);
            }
        }
        break;

    case 2:              //manual
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "Enter array elements a[" << i << "][" << j << "] = ";
                check(arr[i][j]);
            }
        }
        break;

    default:
        cout << "Error! Invalid input.";
        return 0;
        break;
    }
   
    cout << "Ur array:\n";                 //matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << "\t";
       }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {

        bool chk = true;
        for (int j = 1; j < m-1; j++)
        {
            if (arr[i][j] < arr[i][j + 1])
            {
                chk = false;
                break;
            }

        }
        if (chk) b[i] = 1;
        else b[i] = 0;
        cout << b[i] << "\n";
    }

    delete [] b;
    delete [] arr;
    system("pause");
}

