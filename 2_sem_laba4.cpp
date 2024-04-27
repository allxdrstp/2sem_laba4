#include <deque>
#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class bank {
	string name;
	string valuta;
	string percent;
	double credit;
public:
	bank(string n, double c, string v, string p) : name(n), credit(c), valuta(v), percent(p) {}
	bank() : name(""), credit(0.0), valuta(""), percent("") {}

	void print(ostream& os) const {
		os << name << " " << credit << " " << valuta << " " << percent << endl;

	}
	friend ostream& operator<<(ostream& os, const bank& e) {
		os << e.name << ": " << e.valuta << ", " << e.percent << ", " << e.credit << "$";
		return os;
	}
	bool operator < (const bank& other) const {
		return credit > other.credit;
	}
	
};


int main() {
	deque<bank> t;
	ifstream file1("input.txt");
	string name, valuta, percent;
	double credit;

	while (getline(file1, name)) {
		getline(file1, valuta);
		file1 >> percent >> credit;
		file1.ignore();
		t.emplace_back(name, valuta, percent, credit);
	}
	file1.close();

	deque <bank> originalt = t;
	list <bank> copiedt;
	copiedt.resize(originalt.size());
	copy(originalt.begin(), originalt.end(), copiedt.begin());
	sort(t.begin(), t.end());
	list<bank> t_list(t.begin(), t.end());

	ofstream file2("output.txt");
	file2 << "\nSorted container:\n";
	cout << "\nSorted container:\n";
	for (const auto& e : t_list) {
		file2 << e << endl;
		cout << e << endl;
	}

	file2 << "\nCopied container:\n";
	cout << "\nCopied container:\n";
	for (const auto& e : copiedt) {
		file2 << e << endl;
		cout << e << endl;
	}
	file2.close();

	return 0;
}
