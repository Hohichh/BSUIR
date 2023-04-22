#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
#include <regex>

using namespace std;


struct product {
	string name, unit_number, unit_price, receipt_date;
};

void FileCreate(char* path, vector<product>& Product);
void ReadFromFile(char* path, vector<product>& Product);
void ShowingFile(char* path);
void WriteToFile(char* path, vector<product>& Product);
void LineSearch(vector<product>& Product);
void SelectionSort(vector<product>& Product);
void QuickSort(vector<product>& Product, int first, int last);
void ChooseSort(vector<product>& Product);
void BinarySearch(vector<product>& Product, string name);

void ChooseOption(char* path, int option, vector<product>& Product ) {
	switch (option) {
	case 1:  cout << "Reading...\n";
		ShowingFile(path);
		break;
	case 2: cout << "Writing...\n";
		WriteToFile(path, Product);
		break;
	case 3: cout << "Searching...\n";
		LineSearch(Product);
		break;
	case 4: cout << "Sorting...\n";
		ChooseSort(Product);
		break;
	default:
		cout << "Choose from the suggested options!\n";
		while (!(cin >> option) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Choose from the suggested options!\n";
		}
		ChooseOption(path, option, Product);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int choise, option;
	char path[150];
	ofstream fout;
	vector <product> Product;

	cout << "Start! Choose an option:\n" << endl;
	do {
		cout << "1 --- Create new file \n2 --- Work with present file" << endl;

		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Choose 1 or 2" << "\n";
		}

		switch (choise) {
		case 1: cout << "Creating file...\n";

			FileCreate(path, Product);
			break;

		case 2:
			strcpy_s(path, "D:/Study/OAiP/labs/Sem2/ProductBase.txt");
			cout << "You're working with ProductBase.txt\n";
			ReadFromFile(path, Product);
			cout << "Choose an operation:\n";
			cout << "1 --- Read from file\n";
			cout << "2 --- Write in file\n";
			cout << "3 --- Search in file(linesearch)\n";
			cout << "4 --- Sorting alphabetically,cost, date\n";
			cin >> option;
			ChooseOption(path, option, Product);
			break;
		default: cout << "Choose from the suggested options!\n";
		}

	} while (choise != 1 && choise != 2);
}
//Na chuj mi kurwa Twoje kwiaty

void FileCreate(char* path, vector<product>& Product) {
	cin >> path;
	ofstream foutnew;
	foutnew.open(path);
	if (foutnew.is_open())
	{
		cout << "File is open!" << endl;
		WriteToFile(path, Product);
	}
	else {
		cout << "Opa! Your file is close" << endl;
		return;
	}
	
	foutnew.close();
}

void WriteToFile(char* path, vector<product>& Product) {
	ofstream fout;
	fout.open(path, ios_base::app);
	cout << " Enter product information in the following:\n";
	cout << "[Product_name] [Number of units] [Unit price] [dd.mm.yyyy]" << endl;
	product addprod;
	char var;
	do {
		cout << "Input product name(with symbol '_'):\n";
		cin >> addprod.name;
		cout << "Input nuber of product units:\n";
		cin >> addprod.unit_number;
		cout << "Input unit price:\n";
		cin >> addprod.unit_price;

		regex checkdate("((0?[1-9]|[12][0-9]|3[01])\.(0?[1-9]|1[012])\.((19|20)\\d\\d))");
		do {
			cout << "Input date of receipt:\n";
			cin >> addprod.receipt_date;
		} while (regex_match(addprod.receipt_date, checkdate) == false);

		Product.push_back(addprod);
		fout << "\n" << addprod.name << " " << addprod.unit_number << " " << addprod.unit_price << " " << addprod.receipt_date << "\t";

		cout << "Wanna continue?(Y/N)\n";
		cin >> var;
	} while (var != 'N' && var != 'n');
	fout.close();
	cout << "Wanna continue working with file?" << endl;
	char opt;
	cin >> opt;
	switch (opt) {
	case 'n':
	case 'N': 
		cout << "Ok, bye" << endl;
		return;
		break;
	case 'y':
	case 'Y': cout << "Choose an operation:\n";
		cout << "1 --- Read from file\n";
		cout << "2 --- Write in file\n";
		cout << "3 --- Search in file(linesearch)\n";
		cout << "4 --- Sorting alphabetically,cost, date\n";
		int option;
		cin >> option;
		ChooseOption(path, option, Product);
		break;
	}
	
};

void ReadFromFile(char* path, vector<product>& Product) {
	ifstream fin;
	product readprod;
	fin.open(path, ios::in);
	while (!fin.eof()) {
		fin >> readprod.name >> readprod.unit_number >> readprod.unit_price >> readprod.receipt_date;
		Product.push_back(readprod);
		/*cout << readprod.name << " " << readprod.unit_number << " " << readprod.unit_price << " " << readprod.receipt_date << "\n";*/
	}
	/*for (int i = 0; i < Product.size(); i++) {
		cout << Product[i].name<< " " << Product[i].unit_number << " " << Product[i].unit_price << " " << Product[i].receipt_date << "\n";
	}*/
	fin.close();
}

void ShowingFile(char* path) {
	fstream fin;
	fin.open(path);
	cout << "Ur file:" << endl;
	string s;
	while (!fin.eof()) {
		getline(fin, s);
		cout << s << endl;
	}
	fin.close();
}

void LineSearch(vector<product>& Product) {
	cout << "Enter product name, you want to find information about:"<< endl;
	int find = 0;
	string name;
	cin >> name;
	for (int i = 0; i < Product.size(); i++) {
		if (name == Product[i].name) {
			cout << "There it is:\n";
			cout << "Name: "<< Product[i].name <<"\n";
			cout << "Quantity: " << Product[i].unit_number << "\n";
			cout << "Price: " << Product[i].unit_price << "\n";
			cout << "Recipt date: " << Product[i].receipt_date << "\n";
			find = 1;
		}
	}
	if (find == 0) {
		cout << "Opa! There is no such product.\n";
	}

}


void ChooseSort(vector<product>& Product) {
	cout << "What kind of sort whould you like to try?" << endl;
	cout << "1 --- SelectionSort   \n2 --- QuickSort" << endl;
	regex morethanmounth("(((0?[1-9]|[12][0-9]|3[01])\\.(0[21])\\.(2023))|((0?[1-9]|[12][0-9]|3[01])\\.(0?[1-9]|1[012])\\.((202[0-2])|(20[10]\\d))))");
	vector<product> SortProduct;

	for (int i = 0; i < Product.size(); i++) {
		if (stoi(Product[i].unit_price) > 100 && regex_match(Product[i].receipt_date, morethanmounth)) {
			/*cout << Product[i].name << " " << Product[i].unit_price << " " << Product[i].receipt_date << endl;*/
			SortProduct.push_back(Product[i]);
		}
	}

	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
		cout << "You have chosen Selectionsort\n";
		SelectionSort(SortProduct);
		for (int i = 0; i < SortProduct.size(); i++) {
			cout << SortProduct[i].name << " " << SortProduct[i].unit_number << " " << SortProduct[i].unit_price << " " << SortProduct[i].receipt_date << endl;
		}
		break;
	case 2:
		cout << "You have chosen Quicksort\n";
		int first = 0;
		int last = (SortProduct.size()) - 1;
		QuickSort(SortProduct, first, last);
		for (int i = 0; i < SortProduct.size(); i++) {
			cout << SortProduct[i].name << " " << SortProduct[i].unit_number << " " << SortProduct[i].unit_price << " " << SortProduct[i].receipt_date << endl;
		}
		break;
	dafault:
		return;
	}

	char var;
	cout << "Wanna try Binary Search?" << endl;
	
	cin >> var;
	if (var == 'N' || var == 'n') {
		cout << "Ok, bye";
		return;
	}
	else if (var == 'Y' || var == 'y') {
		cout << "Enter product name, you want to find information about:" << endl;
		int left = 0; int right = (SortProduct.size()) - 1;
		string name;
		cin >> name;
		BinarySearch(SortProduct, name);
	}
}

void SelectionSort(vector<product>& Product) {
	string tmp;
	for (int i = 0; i < (Product.size() - 1); i++) {
		for (int j = i + 1; j < Product.size(); j++) {
			if (Product[i].name.compare(Product[j].name) > 0) {
				tmp = Product[i].name;
				Product[i].name = Product[j].name;
				Product[j].name = tmp;
			}
		}
	}
}

void QuickSort(vector<product>& Product, int first, int last) {
	string mid, tmp;
	int f = first, l = last;
	mid = Product[(f + l) / 2].name;
	do {
		while (Product[f].name.compare(mid) < 0) f++;
		while (Product[l].name.compare(mid) > 0) l--;
		if (f <= l) {
			tmp = Product[f].name;
			Product[f].name = Product[l].name;
			Product[l].name = tmp;
			f++;
			l--;
		}
	} while (f<l);
	if (first < l) QuickSort(Product, first, l);
	if (f < last) QuickSort(Product, f, last);
}

void BinarySearch(vector<product>& Product, string name) {
	int left = 0; int right = (Product.size())-1;
	bool flag = false;
	int mid = 0;

	while ((left <= right) && (flag != true)) {
		mid = (left + right) / 2;

		if (Product[mid].name.compare(name) == 0) {
			flag = true;
			
		}
		else if (Product[mid].name.compare(name) > 0) right = mid - 1;
		else if (Product[mid].name.compare(name) < 0) left = mid + 1;	

		if (flag) {
			cout << "There it is:\n";
			cout << "Name: " << Product[mid].name << "\n";
			cout << "Quantity: " << Product[mid].unit_number << "\n";    
			cout << "Price: " << Product[mid].unit_price << "\n";
			cout << "Recipt date: " << Product[mid].receipt_date << "\n";
		}
	}
}
