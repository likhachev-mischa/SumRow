#include <iostream>
#include <iomanip>
#include <functional>
using namespace std;

void menu()
{
	cout << "1. ����� ��������� ���������� ���������." << '\n';
	cout << "2. ����� � �������� ���������." << '\n';
	cout << "3. ��������� ������." << '\n';
}

void output(double num, string msg)
{
	cout << setw(25) << left << msg << " = " << fixed << setprecision(10) << num << '\n';
}
