#include <iostream>
using namespace std;

int Search_Binary(int arr[], int left, int right, int c)
{		
		int midd = (left + right) / 2;
		if (left > right)             //если с > правой границы   либо < левой границы
			return -1;

		if (c < arr[midd])       // если c < среднего значения 
			return Search_Binary(arr, left, midd - 1, c); // смещаем правую границу поиска
		else if (c > arr[midd])  // если с > среднего значения 
			return Search_Binary(arr, midd + 1, right, c);      // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return midd;          
}

int main()
{
	const int SIZE = 10;
	int array[SIZE] = {};
	int c; 
	int index = 0; 

	cout << "\nUr array: \n";
	for (int i = 0; i < SIZE; i++) 
	{
		array[i] = i + 1;
		cout << array[i] << " ";
	}

	cout << "\n\ninput any number: ";
	cin >> c;

	index = Search_Binary(array, 0, SIZE, c);

	if (index >= 0)
		cout << "your number is in the cell with the index: " << index << "\n\n";
	else
		cout << "there is no such number in the array!\n\n";

	return 0;
}