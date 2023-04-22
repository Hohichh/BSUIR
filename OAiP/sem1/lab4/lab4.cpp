#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void checkarr(int &n) {
    while (!(cin >> n) || (cin.peek() != '\n') || (n <= 0) || (n > 20)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << "\n";
    }
}
void check(int &n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << "\n";
    }
}
int main()
{
    int *array;
    int size;
    cout << "Enter size of array(0-20]\n";
    checkarr(size);
    array = new int[size];
    cout << "Ur array size is "<<size<<"\n\n";
    
    cout << "Do you want to fill in elements of array randomly or manually?\n";
    cout << "1 -- randomly\t 2 -- manually\n";

    int option;
    check(option);
    switch (option) {
    case 1:              //random
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            array[i] = rand();
        }
        break;

    case 2:              //manual
        for (int i = 0; i < size; i++)
        {
            cout << "Input element number " << i << "\n";
            check(array[i]);
        }
        break;

    default:
        cout << "che ty vvel suka";
        return 0;
        break;
    }
    

    cout << "Ur array:\n";          //how it started 
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\n";
    }

    int zero1=-1, zero2=-1, i,j;
    cout << "The first zero element(num)\n";     //first 0
    
    for (i = 0; i < size; i++)
    {
        if (array[i] == 0) {
            zero1 = i;
            break;
        }
    }
    cout << zero1 << "\n";

    cout << "The last zero element(num)\n";      //last 0
    for (j = size; j >= 0; j--)
    {
        if (array[j] == 0) {
            zero2 = j;
            break;
        }
    }
    cout << zero2 << "\n";
 
    if ((array[zero1] != 0) || array[zero2] != 0) {
        cout << "there are no elements equal to zero in the array, or there is only one zero element\n";
    }
    else {
        cout << "Sum of elements between first and last zero element:\n";  //how it's going 
        int sum = 0;
        for (int k = zero1 + 1; k < zero2; k++)
        {
            sum += array[k];
        }
        cout << "Sum= " << sum << "n";
    }
    
    delete [] array;
    system("pause");
}

