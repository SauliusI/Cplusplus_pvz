#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <complex>
#include "Matrix.h"

inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace Numeric_lib;


int main()
{

	int abc = 0;
	while (true)
	{
		std::cout << "Iveskite skaiciu" << '\n';
		std::cin >> abc;
		if (abc > 0)
		{
			std::cout << '\n' << "Skaiciaus saknis yra: " << sqrt(abc) << '\n';
		}
		else std::cout << '\n' << "Skaiciaus " << abc << " saknis neegzistuoja" << '\n';
		std::cout << "testi? (y/n)" << '\n';
		char ch;
		std::cin >> ch;
		if (ch != 'y')
			break;
	}


	//Daugybos lentele:
	int n = 0;
	int m = 0;
	std::cout << '\n' << "Iveskite n ir m (daugybos lenteles iðmatavimus) :" << '\n';
	std::cin >> n >> m;
	Matrix <int, 2> lentele(n+1, m+1);
	for (int i = 1; i < lentele.dim1(); ++i)
	{
		for (int j = 1; j < lentele.dim2(); ++j)
			lentele(i, j) = i*j;
	}

	for (int i = 1; i < lentele.dim1(); ++i)
	{
		for (int j = 1; j < lentele.dim2(); ++j)
			std::cout << lentele(i, j) << '\t';
		std::cout << '\n';
	}


	keep_window_open();
	return 0;
}