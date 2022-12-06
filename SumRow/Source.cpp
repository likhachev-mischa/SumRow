#include <iostream>
#include <iomanip>
#include <functional>
using namespace std;

void menu()
{
	cout << "1. Сумма заданного количества слагаемых." << '\n';
	cout << "2. Сумма с заданной точностью." << '\n';
	cout << "3. Завершить работу." << '\n';
}

void output(double num, string msg)
{
	cout << setw(25) << left << msg << " = " << fixed << setprecision(10) << num << '\n';
}
