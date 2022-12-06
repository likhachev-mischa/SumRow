#include <iostream>
#include <functional>
using namespace std;

void menu();

template <typename T, typename Condition>
void read_check(T&, Condition);

template <typename Condition>
void solution(double&, double, double, Condition);

void output(double, string);

void endTask(int&);
