#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Set {
	vector <string> S;
	void remsame(vector <string> &s) {
		auto end = s.end();
		for (auto it = s.begin(); it != end; ++it) {
			end = remove(it + 1, end, *it);
		}
		s.erase(end, s.end());
	}
public:


	//adds element into set
	void Add(string element) {
		S.push_back(element);
	}
	//delets element from set
	void Del(string element) {
		for (auto it = S.begin(); it != S.end(); it++) {
			if (*it == element) {
				S.erase(it);
				break;
			}
		}
	}
	//returns index of adjusted element
	int Find(string el) {
		for (int i = 0; i < S.size(); i++) {
			if (S.at(i) == el) {
				return i;
			}
		}
		return -1;
	}


	Set Union(Set& S2) {
		Set res;
		for (auto it = S.begin(); it != S.end(); it++) { //adding first set in union set 'res'
			res.Add(*it);
		}
		for (auto it = S2.S.begin(); it != S2.S.end(); it++)  { //adding second set in union set 'res'
			res.Add(*it);
		}
		
		remsame(res.S);
		return res;
	}
	Set Intersec(Set &S2) {
		Set res;
		for (int i = 0; i < S.size(); i++) {
			for (int j = 0; j < S2.S.size(); j++) {
				if (S.at(i) == S2.S.at(j)) {
					res.Add(S.at(i));
				}
				else continue;
			}
		}
		return res;
	} 
	void PrintSet() {
		cout << "{ ";
		for (auto it = S.begin(); it != S.end(); it++) {
			cout << *it << " ";
		}
		cout << "}\n";
	}

};