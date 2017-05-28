// PIRMA DALIS, VECTOR ir LIST. Saraso rusiavimas pagal skirtingus parametrus, irasu itraukimas ir istrinimas. Tie patys veiksmai atliekami ir su Vector ir su List

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace std;


struct Item
{
	string name;
	int iid;
	double value;

};

istream& operator >> (istream& is, Item& a)
{
	string name;
	int iid;
	double value;
	is >> name >> iid >> value;
	if (!is) return is;
	a.name = name;
	a.iid = iid;
	a.value = value;
	return is;
}

bool nameCmp(Item const & a, Item const & b) 
{
	return a.name < b.name;
}

bool iidCmp(Item const & a, Item const & b)
{
	return a.iid < b.iid;
}

bool valueCmp(Item const & a, Item const & b)
{
	return a.value < b.value;
}


int main()
{
	vector<Item>vi;
	Item a;
	string iname = "abc.txt";
	ifstream ist(iname.c_str());
	if (!ist)std::cout << "can't write from input file " << iname;
	while (ist >> a) vi.push_back(a);
	for (int i = 0; i < vi.size(); ++i)
		cout << vi[i].name << ',' << vi[i].iid << ',' << vi[i].value << ';' << '\n';
	
	cout << '\n' <<"Isrusiavus pagal name:" << endl;
	std::sort(vi.begin(), vi.end(), nameCmp);
	for (int i = 0; i < vi.size(); ++i)
		cout << vi[i].name << ',' << vi[i].iid << ',' << vi[i].value << ';' << '\n';

	cout << '\n' << "Isrusiavus pagal iid:" << endl;
	std::sort(vi.begin(), vi.end(), iidCmp);
	for (int i = 0; i < vi.size(); ++i)
		cout << vi[i].name << ',' << vi[i].iid << ',' << vi[i].value << ';' << '\n';

	cout << '\n' << "Isrusiavus pagal value:" << endl;
	std::sort(vi.begin(), vi.end(), valueCmp);
	for (int i = vi.size() - 1; i >= 0; --i) // nuo didziausio iki maziausio
		cout << vi[i].name << ',' << vi[i].iid << ',' << vi[i].value << ';' << '\n';

	Item horse;
	horse.name = "horse shoe";
	horse.iid = 99;
	horse.value = 12.34;
	vi.push_back(horse);
	cout << '\n' << "Pridejus horse shoe:" << endl;
	for (int i = 0; i < vi.size(); ++i)
		cout << vi[i].name << ',' << vi[i].iid << ',' << vi[i].value << ';' << '\n';

	for (int i = 0; i < vi.size(); ++i)
		if (vi[i].name == "vardas2")
			vi.erase(vi.begin() + i);
	cout << '\n' << "Istrynus vardas2:" << endl;
	for (int i = 0; i < vi.size(); ++i)
		cout << vi[i].name << ',' << vi[i].iid << ',' << vi[i].value << ';' << '\n';
		
	keep_window_open();
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////
// LIST
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace std;


struct Item
{
	string name;
	int iid;
	double value;

};

istream& operator >> (istream& is, Item& a)
{
	string name;
	int iid;
	double value;
	is >> name >> iid >> value;
	if (!is) return is;
	a.name = name;
	a.iid = iid;
	a.value = value;
	return is;
}

bool nameCmp(Item const & a, Item const & b)
{
	return a.name < b.name;
}

bool iidCmp(Item const & a, Item const & b)
{
	return a.iid < b.iid;
}

bool valueCmp(Item const & a, Item const & b)
{
	return a.value < b.value;
}

std::ostream& operator << (std::ostream& os, const Item& item)
{
	return os << item.name << " " << item.iid << " " << item.value;
}
void print(const list<Item>& s) {
	list<Item>::const_iterator i;
	for (i = s.begin(); i != s.end(); ++i)
		cout << *i << '\n';
	cout << endl;
}

bool nameremove(string a, Item const & b)
{
	return (a == b.name);
}

int main()
{
	list<Item>li;
	Item a;
	string iname = "abc.txt";
	ifstream ist(iname.c_str());
	if (!ist)std::cout << "can't write from input file " << iname;
	while (ist >> a) li.push_back(a);
	print(li);

	cout << '\n' << "Isrusiavus pagal name:" << endl;
	li.sort(nameCmp);
	print(li);

	cout << '\n' << "Isrusiavus pagal iid:" << endl;
	li.sort(iidCmp);
	print(li);

	cout << '\n' << "Isrusiavus pagal value:" << endl;
	li.sort(valueCmp);
	print(li);

	
	Item horse;
	horse.name = "horse shoe";
	horse.iid = 99;
	horse.value = 12.34;
	li.push_back(horse);
	cout << '\n' << "Pridejus horse shoe:" << endl;
	print(li);

	for (std::list<Item>::iterator i = li.begin(); i != li.end(); ++i)
		if (i->name == "vardas1")
		{
			li.erase(i);
			break;
		}
	cout << '\n' << "Istrynus vardas1:" << endl;
	print(li);

	for (std::list<Item>::iterator i = li.begin(); i != li.end(); ++i)
		if (i->iid == 25)
		{
			li.erase(i);
			break;
		}

	keep_window_open();
	return 0;
}
*/



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ANTRA DALIS MAP. Vardu ir amziu sarasas.
/*
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace std;

void printmap(const map<string, int>& s) {
	map<string, int>::const_iterator i;
	for (i = s.begin(); i != s.end(); ++i)
		cout << i->first << " " << i->second << '\n';
	cout << endl;
}

void sumage(const map<string, int>& s) {
	map<string, int>::const_iterator i;
	int a = 0;
	for (i = s.begin(); i != s.end(); ++i)
		a = a + i->second;
	cout << "Amziu suma yra: " << a <<endl;
}

void copymap(const map<string, int>& s, map<int, string>& d) {
	map<string, int>::const_iterator i;
	for (i = s.begin(); i != s.end(); ++i)
			d.insert(make_pair(i->second, i->first));
}

void printmap2(const map<int, string>& s) {
	map<int, string>::const_iterator i;
	for (i = s.begin(); i != s.end(); ++i)
		cout << i->first << " " << i->second << '\n';
	cout << endl;
}

int main()
{
	map<string, int> msi;
	msi["Jonas"] = 25;
	msi["Kobe"] = 37;
	msi["Petras"] = 79;
	msi["Antanas"] = 17;
	msi["Jurgis"] = 34;
	printmap(msi);

	std::cout << '\n' << "Pasalinus elementa:" << '\n';
	msi.erase("Kobe");
	printmap(msi);

	string vardas = "";
	int amzius = 0;
	while (true)
	{
		std::cout << "Iveskite varda" << '\n';
		std::cin >> vardas;
		std::cout << "Iveskite amziu" << '\n';
		std::cin >> amzius;
		msi[vardas] = amzius;
		std::cout << "testi? (y/n)" << '\n';;
		char c;
		std::cin >> c;
		if (c != 'y')
			break;
	}
	cout << '\n' << "Pridejus elementus:" << '\n';
	printmap(msi);
	sumage(msi);

	map<int, string> mis;

	copymap(msi, mis);
	printmap2(mis);

	keep_window_open();
	return 0;
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TRECIA DALIS VEKTORIAI. Veiksmai su is failo ikeltu vektoriumi.
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace std;

int main()
{
	vector<double> vd;
	double d;
	string iname = "vektorius.txt";
	ifstream ist(iname.c_str());
	if (!ist)std::cout << "can't write from input file " << iname;
	while (ist >> d) vd.push_back(d);
	cout << "Vektoriaus reiksmes" << '\n';
	for (int i = 0; i < vd.size(); ++i)
		cout << vd[i] << '\n';

	vector<int> vi(16);
	cout << '\n';
	cout << "Vektoriaus reiksmes paverstos i sveikuosius skaicius ir orgionalios vektoriaus reiksmes" << '\n';
	for (int i = 0; i < vi.size(); ++i)
	{
		vi[i] = vd[i];
		cout << vi[i] << '\t' << vd[i] << '\n';
	}

	double vdsuma = 0;
	for (int i = 0; i < vd.size(); ++i)
	{
		vdsuma = vdsuma + vd[i];	
	}
	cout << '\n' << "Vektoriaus vd suma: " << vdsuma << '\n';

	double skirt = 0;
	for (int i = 0; i < vd.size(); ++i)
	{
		skirt = skirt + vd[i] - vi[i];
	}
	cout << '\n' << "Skirtumas tarp vd ir vi: " << skirt << '\n';

	cout << '\n' << "Apvertus vektoriu vd: " << '\n';
	std::reverse(vd.begin(), vd.end());
	for (int i = 0; i < vd.size(); ++i)
		cout << vd[i] << '\n';

	cout << '\n' << "Vektoriaus vd vidurkis: " << vdsuma/vd.size() << '\n';

	vector<double> vd2;
	cout << '\n' << "Mazesnes uz vidurki reiksmes: " << '\n';
	for (int i = 0; i < vd.size(); ++i)
	{
		if (vd[i] < (vdsuma / vd.size()))
		{
			vd2.push_back(vd[i]);
			cout << vd[i] << '\n';
		}
	}

	std::sort(vd.begin(), vd.end());
	cout << '\n' << "Isrusiavus vektoriu vd: " << '\n';
	for (int i = 0; i < vd.size(); ++i)
		cout << vd[i] << '\n';

	keep_window_open();
	return 0;
}*/