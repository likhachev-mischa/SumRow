#include <iostream>
#include "RowFunc.h"
#include <functional>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int choice;
	do
	{
		menu();
		double x;
		read_check(choice, [](int x)->bool {return (x < 4 && x > 0); });
		if (choice != 3)
		{
			cout << "Введите значение x (|x|<1): " << '\n';
			read_check(x, [](double x)->bool {return abs(x) < 1; });
			double sum = 1;

			if (choice == 1)
			{
				cout << "Введите количество слагаемых : " << '\n';
				double count;
				read_check(count, [](double x)->bool {return x < 151 && x > 0; });
				solution(sum, x, count, [](double x, double y, double z)->bool {return z <= x; });
			}

			else
			{
				cout << "Введите точность вычислений : " << '\n';
				double eps;
				read_check(eps, [](double x)->bool {return x < DBL_MAX&& x > 0; });
				solution(sum, x, eps, [](double x, double y, double z)->bool {return y > x; });
			}

			double ref = 1 / (sqrt(1 - x * x));
			output(ref, "Точное значение");
			endTask(choice);

		}
	} while (choice != 3);
}

template <typename Condition>
void solution(double& sum, double x, double check, Condition state)
{
	double numerator = 1., denomerator = 1., mult = 1., add = 1., i = 1.;
	while (state(check, add, i))
	{
		numerator *= 2 * i - 1;
		denomerator *= 2 * i;
		mult *= x * x;
		add = (numerator / denomerator) * mult;
		sum += add;
		++i;
	}
	output(sum, "Приближенное значение");
}

template<typename T, typename Condition>
void read_check(T& x, Condition state)
{
	while (!(cin >> x) || !state(x))
	{
		cout << "Неверный ввод! " << '\n';
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
}

void endTask(int& choice)
{
	cout << "Завершить работу (Y/N-любая клавиша)\n";
	char x;
	read_check(x, [](char x)->bool {return true; });
	if (x == 'Y' || x == 'y')
		choice = 3;
}

