
#include "Multiset.h"
using namespace std;
/*!
	parsing a string into a set
	\param setString a string from which a set is formed
*/
void Multiset::parsStrToSet(const string& setString) {
	size_t openBracket = 0, closeBracket = 0;
	openBracket = count(setString.begin(), setString.end(), '{');
	closeBracket = count(setString.begin(), setString.end(), '}');
	if (openBracket != closeBracket) {
		cout << "Input error! number of brackets does not match." << endl;
		return;
	}
	size_t depth = 0;
	string elStr, subsetStr;
	int subsetStart = -1;
	for (int i = 0; i < setString.length(); i++) {
		if (setString[i] == '{') {
			depth++;
			if (depth == 2) {
				subsetStart = i;
			}
		}
		else if (setString[i] == '}') {
			if (depth == 2) {
				subsetStr = setString.substr(subsetStart, i - subsetStart + 1);
				Multiset subset(subsetStr);
				subsets_.emplace_back(subset);
				depth--;
			}
			else if (depth > 2) {
				depth--;
			}
			else {
				if (!elStr.empty()) {
					elements_.push_back(elStr);
					elStr.clear();
				}
				return;
			}
		}
		else if (depth == 1) {
			if (setString[i] == ',') {
				if (!elStr.empty()) {
					elements_.push_back(elStr);
					elStr.clear();
				}
			}
			else if (setString[i] == ' ') {
				continue;
			}
			else {
				elStr += setString[i];
			}
		}
	}

}
/*!
	forms a string from the class object
	\return a string
*/
string Multiset::toString() const {
	string result;
	result += '{';
	for (size_t i = 0; i < elements_.size(); i++) {
		result += elements_[i];
		if (i != elements_.size() - 1 || !subsets_.empty()) {
			result += ',';
			result += ' ';
		}
	}
	for (int i = 0; i < subsets_.size(); i++) {
		result += subsets_[i].toString();
		if (i != subsets_.size() - 1) {
			result += ',';
			result += ' ';
		}
	}
	result += '}';
	return result;
}
/*!
	counts occurrences of a given element in the set
	\param element an element, the occurrences of which are counted
	\return result of std::count() function
*/
size_t Multiset::countEls(const string& element) const {
	return count(elements_.begin(), elements_.end(), element);
}
/*!
	determines whether an element in the set
	\param element an element, the occurrences of which are counted
	\return result of std::find() function
*/
bool Multiset::findEls(const string& element) const {
	bool find = std::find(elements_.begin(), elements_.end(), element) != elements_.end();
	return find;
}
/*!
	overloaded function countEls()
	\param subset
	\return result of std::count() function
*/
size_t Multiset::countEls(const Multiset& subset) const {
	return std::count(subsets_.begin(), subsets_.end(), subset);
}
/*!
	overloaded function findEls()
	\param subset
	\return result of std::find() function
*/
bool Multiset::findEls(const Multiset& subset) const {
	bool find = std::find(subsets_.begin(), subsets_.end(), subset) != subsets_.end();
	return find;
}
/*!
	adds string element to vector <string> elements amount times
	\param element,amount
*/
void Multiset::addToRes(const string& element, size_t amount) {
	for (size_t k = 0; k < amount; k++) {
		addElement(element);
	}
}
/*!
	overloaded function addToRes()
	\param set,amount
*/
void Multiset::addToRes(const Multiset& set, size_t amount) {
	for (size_t k = 0; k < amount; k++) {
		addSubset(set);
	}
}
/*!
	subfunction for the "+" operator
	\param set1,set2
*/
void Multiset::addAll(const Multiset& set1, const Multiset& set2) {
	if (set1.elements_.empty()) {
		for (size_t i = 0; i < set2.elements_.size(); i++) {
			addElement(set2.elements_[i]);
		}
	}
	else if (set2.elements_.empty()) {
		for (size_t i = 0; i < set1.elements_.size(); i++) {
			addElement(set1.elements_[i]);
		}
	}
	if (set1.subsets_.empty()) {
		for (size_t i = 0; i < set2.subsets_.size(); i++) {
			addSubset(set2.subsets_[i]);
		}
	}
	else if (set2.subsets_.empty()) {
		for (size_t i = 0; i < set1.subsets_.size(); i++) {
			addSubset(set1.subsets_[i]);
		}
	}
}
/*!
	constructor with initialization list
*/
Multiset::Multiset() : cardinality_(0), maxNesting_(0) {}
/*!
	constructor with parameter
	\param element
*/
Multiset::Multiset(const string& element) {
	parsStrToSet(element);
	cardinality_ = elements_.size() + subsets_.size();
}
/*!
	constructor with parameter
	\param element
*/
Multiset::Multiset(const char* element) {
	parsStrToSet(element);
	cardinality_ = elements_.size() + subsets_.size();
}
/*!
	copy constructor
	\param set
*/
Multiset::Multiset(const Multiset& set) {
	elements_ = set.elements_;
	cardinality_ = set.cardinality_;
	subsets_ = set.subsets_;
	maxNesting_ = set.maxNesting_;
}
/*!
	a method for determining the emptiness of the set
	\return result for std::empty() finction for elements_ and subsets_
*/
bool Multiset::isEmpty() const {
	return elements_.empty() && subsets_.empty();
}
/*!
	a method for forming the booleans of the set
	\return result boolean set
*/
Multiset Multiset::boolean() const {
	Multiset result;
	Multiset temp;
	for (size_t i = 0; i < elements_.size(); i++) {
		temp.addElement(elements_[i]);
	}
	for (size_t i = 0; i < subsets_.size(); i++) {
		temp.addElement(subsets_[i].toString());
	}

	for (int i = 0; i < (1 << temp.elements_.size()); i++) {
		Multiset subset;
		for (int j = 0; j < temp.elements_.size(); j++) {
			if (i & (1 << j)) {
				subset.addElement(temp.elements_[j]);
			}
		}
		result.addSubset(subset);
	}
	return result;
}
/*!
	adds an element to set
	\param element
*/
void Multiset::addElement(const string& element) {
	elements_.push_back(element);
	cardinality_++;
}
/*!
	adds an element to set
	\param element
*/
void Multiset::addElement(const char* element) {
	elements_.push_back(element);
	cardinality_++;
}
/*!
	adds a subset to set
	\param set
*/
void Multiset::addSubset(const Multiset& set) {
	subsets_.emplace_back(set);
	cardinality_++;
}

/*!
	deletes an element from set
	\param element
*/
void Multiset::delElement(const string& element) {
	elements_.erase(std::remove(elements_.begin(), elements_.end(), element), elements_.end());
	cardinality_ = elements_.size();
}
/*!
	deletes an element from set
	\param element
*/
void Multiset::delElement(const char* element) {
	elements_.erase(std::remove(elements_.begin(), elements_.end(), element), elements_.end());
	cardinality_ = elements_.size();
}

/*!
	deletes a subset from set
	\param set
*/
void Multiset::delSubset(const Multiset& set) {
	subsets_.erase(std::remove(subsets_.begin(), subsets_.end(), set), subsets_.end());
	cardinality_ = subsets_.size();
}

/*!
	overloaded operator "[]"
	\param element
	\return result of findEls() function
*/
bool Multiset::operator[](const string& element) const {
	return findEls(element);
}
/*!
	overloaded operator "[]"
	\param element
	\return result of findEls() function
*/
bool Multiset:: operator[](const char* element) const {
	string el = element;
	return findEls(el);
}
/*!
	overloaded operator "[]"
	\param subset
	\return result of findEls() function
*/
bool Multiset::operator[](const Multiset& subset) const {
	return findEls(subset);
}
/*!
	overloaded operator "=="
	\param set
	\return true if two sets are equal
*/
bool Multiset::operator==(const Multiset& set) const {
	if (elements_.size() != set.elements_.size() || maxNesting_ != set.maxNesting_) {
		return false;
	}
	if (!std::is_permutation(elements_.begin(), elements_.end(), set.elements_.begin())) {
		return false;
	}
	for (size_t i = 0; i < subsets_.size(); i++) {
		if (!(subsets_[i] == set.subsets_[i])) {
			return false;
		}
	}
	return true;
}
/*!
	overloaded operator "!="
	\param set
	\return true if two sets are not equal
*/
bool Multiset::operator!=(const Multiset& set) const {
	return (!(*this == set));
}
/*!
	overloaded operator "+"
	\param set
	\return union of current set and parameter-set
*/
Multiset Multiset::operator+(const Multiset& set) const {
	Multiset result;
	result.addAll(*this, set);

	for (size_t i = 0; i < elements_.size(); i++) {
		for (size_t j = 0; j < set.elements_.size(); j++) {
			if (elements_[i] == set.elements_[j] && !result.findEls(elements_[i])) {

				if (countEls(elements_[i]) >= set.countEls(elements_[i])) {
					result.addToRes(elements_[i], countEls(elements_[i]));
				}
				else {
					result.addToRes(set.elements_[j], set.countEls(elements_[i]));
				}
			}
			else if (elements_[i] != set.elements_[j] && !result.findEls(set.elements_[j])) {

				if (set.countEls(set.elements_[j]) <= 1 && countEls(set.elements_[j]) <= 1) {
					result.addElement(set.elements_[j]);
				}
				else if (set.countEls(set.elements_[j]) > 1 && countEls(set.elements_[j]) == 0) {
					result.addToRes(set.elements_[j], set.countEls(set.elements_[j]));
				}
			}
		}
		if (!result.findEls(elements_[i])) {
			result.addToRes(elements_[i], countEls(elements_[i]));
		}
	}

	for (size_t i = 0; i < subsets_.size(); i++) {
		for (size_t j = 0; j < set.subsets_.size(); j++) {
			if (subsets_[i] == set.subsets_[j] && !result.findEls(subsets_[i])) {

				if (countEls(subsets_[i]) >= set.countEls(subsets_[i])) {
					result.addToRes(subsets_[i], countEls(subsets_[i]));
				}
				else {
					result.addToRes(set.subsets_[j], set.countEls(subsets_[i]));
				}
			}
			else if (subsets_[i] != set.subsets_[j] && !result.findEls(set.subsets_[j])) {

				if (set.countEls(set.subsets_[j]) <= 1 && countEls(set.subsets_[j]) <= 1) {
					result.addSubset(set.subsets_[j]);
				}
				else if (set.countEls(set.subsets_[j]) > 1 && countEls(set.subsets_[j]) == 0) {
					result.addToRes(set.subsets_[j], set.countEls(set.subsets_[j]));
				}
			}
		}
		if (!result.findEls(subsets_[i])) {
			result.addToRes(subsets_[i], countEls(subsets_[i]));
		}
	}

	return result;
}
/*!
	overloaded operator "+="
	\param set
	\return union of current set and parameter-set that assigned to the current set
*/
Multiset Multiset::operator+= (const Multiset& set) {
	return *this = *this + set;
}
/*!
	overloaded operator "*"
	\param set
	\return intersection of current set and parameter-set
*/
Multiset Multiset::operator*(const Multiset& set)const {
	Multiset result;
	for (size_t i = 0; i < elements_.size(); i++) {
		for (size_t j = 0; j < set.elements_.size(); j++) {

			if (elements_[i] == set.elements_[j]) {

				if (countEls(elements_[i]) <= set.countEls(set.elements_[j]) && !result.findEls(elements_[i])) {
					result.addToRes(elements_[i], countEls(elements_[i]));
				}
				else if (countEls(elements_[i]) >= set.countEls(set.elements_[j]) && !result.findEls(elements_[i])) {
					result.addToRes(elements_[i], set.countEls(set.elements_[j]));
				}
			}
		}
	}

	for (size_t i = 0; i < subsets_.size(); i++) {
		for (size_t j = 0; j < set.subsets_.size(); j++) {

			if (subsets_[i] == set.subsets_[j]) {

				if (countEls(subsets_[i]) <= set.countEls(set.subsets_[j]) && !result.findEls(subsets_[i])) {
					result.addToRes(subsets_[i], countEls(subsets_[i]));
				}
				else if (countEls(subsets_[i]) >= set.countEls(set.subsets_[j]) && !result.findEls(subsets_[i])) {
					result.addToRes(subsets_[i], set.countEls(set.subsets_[j]));
				}
			}
		}
	}
	return result;
}
/*!
	overloaded operator "*="
	\param set
	\return intersection of current set and parameter-set that assigned to the current set
*/
Multiset Multiset::operator*= (const Multiset& set) {
	return *this = *this * set;
}
/*!
	overloaded operator "-"
	\param set
	\return difference of current set and parameter-set
*/
Multiset Multiset::operator-(const Multiset& set) const {
	Multiset result;
	for (size_t i = 0; i < elements_.size(); i++) {
		for (size_t j = 0; j < set.elements_.size(); j++) {

			if (elements_[i] == set.elements_[j]) {

				if (countEls(elements_[i]) > set.countEls(set.elements_[j]) && !result.findEls(elements_[i])) {
					result.addToRes(elements_[i], countEls(elements_[i]) - set.countEls(set.elements_[j]));
				}
			}
		}
	}
	for (size_t i = 0; i < subsets_.size(); i++) {
		for (size_t j = 0; j < set.subsets_.size(); j++) {

			if (subsets_[i] == set.subsets_[j]) {

				if (countEls(subsets_[i]) > set.countEls(set.subsets_[j]) && !result.findEls(subsets_[i])) {
					result.addToRes(subsets_[i], countEls(subsets_[i]) - set.countEls(set.subsets_[j]));
				}
			}
		}
	}
	return result;
}
/*!
	overloaded operator "-="
	\param set
	\return difference of current set and parameter-set that assigned to the current set
*/
Multiset Multiset::operator-= (const Multiset& set) {
	return *this = *this - set;
}
/*!
	Console output of a set, its capacity and whether it is empty
*/
void Multiset::printSetInfo() const {
	cout << "\n Multiset info:" << endl;
	cout << "Set's cardinality: " << cardinality_ << endl;
	cout << "Emptyness: " << isEmpty() << endl;
	printSet();
}
/*!
	Console output of a set
*/
void Multiset::printSet() const {
	cout << "{";
	for (int i = 0; i < elements_.size(); i++) {
		cout << elements_[i];
		if (i != elements_.size() - 1 || !subsets_.empty()) {
			cout << ", ";
		}
	}
	for (int i = 0; i < subsets_.size(); i++) {
		subsets_[i].printSet();
		if (i != subsets_.size() - 1) {
			cout << ", ";
		}
	}
	cout << "}";
}