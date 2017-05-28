#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace std;

void wrong_patterns()
{
regex pat1("(|ghi)");    // missing alternative
regex pat2("[c-a]");     // not a range
}

std::ostream& operator << (std::ostream& os, const regex& a)
{
	return os << a;
}

int main()
{

	regex pattern;

	string pat;
	cout << "enter pattern: ";
	getline(cin, pat);
	pattern = pat;
	
	cout << "now enter lines:\n";
	string line;
	int lineno = 0;

	while (getline(cin, line)) {
		++lineno;
		smatch matches;
		if (regex_search(line, matches, pattern)) {
			cout << "line " << lineno << ": " << line << '\n';
			for (int i = 0; i<matches.size(); ++i)
				cout << "\tmatches[" << i << "]: "
				<< matches[i] << '\n';
		}
		else
			cout << "didn't match\n";
	}

	keep_window_open();
	return 0;
}