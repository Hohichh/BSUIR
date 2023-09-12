#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void ReadFromFile(int**& matrix, string& test, int kolvo_nodes, vector<vector<int>>& graph);
bool dfs(int v, vector<int>& p, vector<char>& cl, vector<vector<int>>& graph, int& cycle_end, int& cycle_st);
string choosetest(int& num);
void Final(string num);


int main()
{
	cout << "choose number of test(from 1 to 7)\n";        //интерактив с пользователем: выбираем тест, который хотим запустить 
	int num;
	cin >> num;
	choosetest(num);
	cout << "you choosed test No " << num << "\n";
	Final(choosetest(num));
	return 0;
}

//функция для выбора теста
string choosetest(int& num) {       
	string test;
	switch (num) {
	case 1: {
		test = "D:/Study/PiOIvIS/RR/test1.txt";
		break;
	}
	case 2: {
		test = "D:/Study/PiOIvIS/RR/test2.txt";
		break;
	}
	case 3: {
		test = "D:/Study/PiOIvIS/RR/test3.txt";
		break;
	}
	case 4: {
		test = "D:/Study/PiOIvIS/RR/test4.txt";
		break;
	}
	case 5: {
		test = "D:/Study/PiOIvIS/RR/test5.txt";
		break;
	}
	case 6: {
		test = "D:/Study/PiOIvIS/RR/test6.txt";
		break;
	}
	case 7: {
		test = "D:/Study/PiOIvIS/RR/test7.txt";
		break;
	}
	}
	return test;
}       

//функция для чтения матрицы смежности из файла
void ReadFromFile(int**& matrix, string& test, int kolvo_nodes, vector<vector<int>>& graph) {

	ifstream fin(test);          //считываем непосредственно матрицу
	string s;
	getline(fin, s);
	for (int i = 0; i < kolvo_nodes; i++)
	{
		for (int j = 0; j < kolvo_nodes; j++)
		{
			fin >> matrix[i][j];
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < kolvo_nodes; i++)          //заносим в вектор в виде СС 
	{
		graph.push_back({ i });
		for (size_t j = 0; j < kolvo_nodes; j++)
		{
			if (matrix[i][j] != 0)
			{
				graph[i].push_back(j);
			}
		}
	}
	fin.close();
}

//поиск в глубину с проверкой на (а-)цикличность
bool dfs(int v, vector<int>& p, vector<char>& cl, vector<vector<int>>& graph, int& cycle_end, int& cycle_st)
{

	for (size_t i = 1; i < graph[v].size(); i++)
	{
		cl[v] = 1;
		int to = graph[v][i];
		if (p[v] != to)
			if (cl[to] == 0) {
				p[to] = v;
				if (dfs(to, p, cl, graph, cycle_end, cycle_st))  return true;
				
			}
			else if (cl[to] == 1 && v != to) {
				cycle_end = v;
				cycle_st = to;
				return true;
			}
	}
	cl[v] = 2;
	return false;
}

//функция запуска тестов и вывода найденного цикла
void Final(string num) {

	ifstream fin(num);
	string s;
	getline(fin, s);
	int kolvo_nodes = stoi(s);

	vector <vector<int>> graph;

	int** matrix;
	matrix = new int* [kolvo_nodes];
	for (int i = 0; i < kolvo_nodes; i++)
	{
		matrix[i] = new int[kolvo_nodes];
	}

	ReadFromFile(matrix, num, kolvo_nodes, graph);
	vector<char> cl;
	vector<int> p;
	int cycle_st = -1, cycle_end = -1;

	p.assign(kolvo_nodes, -1);
	cl.assign(kolvo_nodes, 0);
	for (int i = 0; i < kolvo_nodes; ++i) {
		if (dfs(i, p, cl, graph, cycle_end, cycle_st));
		break;
	}
	if (cycle_st == -1)
		puts("Acyclic");
	else {
		puts("Cyclic");
		vector<int> cycle;
		cycle.push_back(cycle_st);
		for (int v = cycle_end; v != cycle_st; v = p[v])
			cycle.push_back(v);

		cycle.push_back(cycle_st);
		reverse(cycle.begin(), cycle.end());
		for (size_t i = 0; i < cycle.size(); ++i)
			printf("%d ", cycle[i] + 1);
	}
	delete[] matrix;
	fin.close();
}