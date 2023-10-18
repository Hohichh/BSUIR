#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*!
	\brief Implementation of the Multiset class
	\author Verkovich E. V.
	\version 1.0
	\date October 2023
	\details Multiset class contains 2 vector fields for storing multiset elements,
	a field showing the capacity of the set and its maximum nesting; a constructor with an initialization list,
	with a parameter, as well as a copy constructor;
	methods for adding and removing elements;
	a method for determining the emptiness of the set; a method for forming the booleans of the set;
	overloaded operators "+", "+=", "*", "*=", "-", "-=", "[]"; other additional methods.
*/
class Multiset
{
public:
	vector<string>elements_;
	vector<Multiset>subsets_;
	size_t cardinality_;

	void parsStrToSet (const string& elements);
	string toString() const;
	size_t countEls(const string& element) const;
	size_t countEls(const Multiset& subset) const;
	bool findEls(const string& element) const;
	bool findEls(const Multiset& subset) const;

	void addToRes(const string& element, size_t amount);
	void addToRes(const Multiset& set, size_t amount);
	void addAll(const Multiset& set1, const Multiset& set2);
public:
	Multiset();
	Multiset(const string &elements);
	Multiset(const char* elements);
	Multiset(const Multiset& set);

	bool isEmpty() const;
	Multiset boolean() const;

	void addElement(const string& element);
	void addElement(const char* element);
	void addSubset(const Multiset& set);
	void delElement(const string &element);
	void delElement(const char* element);
	void delSubset(const Multiset& set);

	bool operator[](const string& element) const;
	bool operator[](const char* element) const;
	bool operator[](const Multiset& subset) const;
	bool operator==(const Multiset& Set) const;
	bool operator!=(const Multiset& Set) const;
	Multiset operator+(const Multiset& Set) const;
	Multiset operator+= (const Multiset& Set);
	Multiset operator*(const Multiset& Set) const;
	Multiset operator*= (const Multiset& Set);
	Multiset operator-(const Multiset& Set) const;
	Multiset operator-= (const Multiset& Set);

	void printSetInfo() const;
	void printSet() const;
};

