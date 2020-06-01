#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <cmath>
#include "My_List.h"
using namespace std;
#define MY_LIST

#ifdef MY_LIST
template<class List, class Binary = plus<>>
void Arithmetic(vector<List>&k, List &l, Binary bin = plus<>()) {
	int n, m, t;
	cout << "Первый полином - ";
	cin >> n;
	n--;
	cout << "Второй полином - ";
	cin >> m;
	m--;
	auto first = k[n].begin();
	auto second = k[m].begin();
	auto third = k[n].end();
	auto fourth = k[m].end();
	
	if (k[n].size() < k[m].size()) {
		swap(first, second);
		swap(third, fourth);
		t = k[m].size() - k[n].size();
	}
	else {
		t = k[n].size() - k[m].size();
	}

	for (; t != 0; t--, first++) {
		l.push_back(*first);
	}
	for (; first != third && second != fourth; first++, second++) {
		l.push_back(bin(*first, *second));
	}
	k.push_back(l);
	l.clear();
}

#else
template<class list, class Binary = plus<>>
void Arithmetic(vector<list>&k, list &l, Binary bin = plus<>()) {
	int n, m, t;
	cout << "Первый полином - ";
	cin >> n;
	n--;
	cout << "Второй полином - ";
	cin >> m;
	m--;
	auto first = k[n].begin();
	auto second = k[m].begin();
	auto third = k[n].end();
	auto fourth = k[m].end();

	if (k[n].size() < k[m].size()) {
		swap(first, second);
		swap(third, fourth);
		t = k[m].size() - k[n].size();
	}
	else {
		t = k[n].size() - k[m].size();
	}

	for (; t != 0; t--, first++) {
		l.push_back(*first);
	}
	for (; first != third && second != fourth; first++, second++) {
		l.push_back(bin(*first, *second));
	}
	k.push_back(l);
	l.clear();
}
#endif

#ifdef MY_LIST
template<class List>
void Polinom(List &l, vector<List> &k)
{
	int m, n;
	cout << "Какая степень?" << endl;
	cin >> m;
	m++;
	cout << "Введите коэффициенты" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		l.push_back(n);
	}
	k.push_back(l);
	l.clear();
}
#else
template<class list>
void Polinom(list &l, vector<list> &k)
{
	int m, n;
	cout << "Какая степень?" << endl;
	cin >> m;
	m++;
	cout << "Введите коэффициенты" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		l.push_back(n);
	}
	k.push_back(l);
	l.clear();
}
#endif
#ifdef MY_LIST
template<class List>
void Output_polinom(vector<List> &k)
{
	int n;
	cout << "Какой полином?" << endl;
	cin >> n;
	n--;
	int i = 0;
	for (auto &f : k[n])
	{
		i++;
		if (f != 0)         
		{
			if (f > 0 && i == 1)
				cout << f << "x^" << k[n].size() - i; 
			else
			{
				if (k[n].size() - i == 0)
				{
					if (f > 0)
						cout << "+";
					cout << f;
				}
				else {
					if (f > 0)
						cout << "+";
					cout << f << "x^" << k[n].size() - i;
				}
			}
		}
	}
	cout << endl;
}
#else
template<class list>
void Output_polinom(vector<list> &k)
{
	int n;
	cout << "Какой полином?" << endl;
	cin >> n;
	n--;
	int i = 0;
	for (auto &f : k[n])
	{
		i++;
		if (f != 0)
		{
			if (f > 0 && i == 1)
				cout << f << "x^" << k[n].size() - i;
			else
			{
				if (k[n].size() - i == 0)
				{
					if (f > 0)
						cout << "+";
					cout << f;
				}
				else {
					if (f > 0)
						cout << "+";
					cout << f << "x^" << k[n].size() - i;
				}
			}
		}
	}
	cout << endl;
}
#endif
#ifdef MY_LIST
template<class List>
void Multiplication(vector<List> &k)
{
	int n, m, i = 0;
	cout << "На какое число надо умножить?" << endl;
	cin >> m;
	cout << "Какой полином?" << endl;
	cin >> n;
	n--;
	for (auto it = k[n].begin(); it != k[n].end(); ++it)
	{
		i++;
		*it *= m;
		if (*it > 0 && i == 1)
			cout << *it << "x^" << k[n].size() - i;
		else {
			if (k[n].size() - i == 0)
			{
				if (*it > 0)
					cout << "+";
				cout << *it;
			}                
			else
			{
				if (*it > 0)
				cout << "+";
				cout << *it << "x^" << k[n].size() - i;
			}
		}
	}
	cout << endl;
}
#else
template<class list>
void Multiplication(vector<list> &k)
{
	int n, m, i = 0;
	cout << "На какое число надо умножить?" << endl;
	cin >> m;
	cout << "Какой полином?" << endl;
	cin >> n;
	n--;
	for (auto it = k[n].begin(); it != k[n].end(); ++it)
	{
		i++;
		*it *= m;
		if (*it > 0 && i == 1)
			cout << *it << "x^" << k[n].size() - i;
		else {
			if (k[n].size() - i == 0)
			{
				if (*it > 0)
					cout << "+";
				cout << *it;
			}
			else
			{
				if (*it > 0)
					cout << "+";
				cout << *it << "x^" << k[n].size() - i;
			}
		}
	}
	cout << endl;
}
#endif
#ifdef MY_LIST
template<class List>
void Korni(vector<List> &k)
{
	double a, b, c, d, x1, x2, n, i = 0, proverka;
	cout << "Какой полином?" << endl;
	cin >> n;
	n--;
	if (k[n].size() == 3)
	{ 
		for (auto it = k[n].begin(); it != k[n].end(); ++it)
		{
			if (i == 0)
				a = *it;
			if (i == 1)
				b = *it;
			if (i == 2)
				c = *it;
			i++;
		}
		d = pow(b, 2) - 4 * a * c;
		if (d == 0)
		{
			x1 = -b / 2 * a;
			cout << "x = " << x1 << endl;
		}
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / 2 * a;
			x2 = (-b - sqrt(d)) / 2 * a;
			cout << "x_1 = " << x1 << endl;
			cout << "x_2 = " << x2 << endl;
		}
		if (d < 0)
		{
			cout << "Дискриминант < 0" << endl;
		}
	}
	else
		cout << "Высшая степень полинома не 2" << endl;
}
#else
template<class list>
void Korni(vector<list> &k)
{
	double a, b, c, d, x1, x2, n, i = 0, proverka;
	cout << "Какой полином?" << endl;
	cin >> n;
	n--;
	if (k[n].size() == 3)
	{
		for (auto it = k[n].begin(); it != k[n].end(); ++it)
		{
			if (i == 0)
				a = *it;
			if (i == 1)
				b = *it;
			if (i == 2)
				c = *it;
			i++;
		}
		d = pow(b, 2) - 4 * a * c;
		if (d == 0)
		{
			x1 = -b / 2 * a;
			cout << "x = " << x1 << endl;
		}
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / 2 * a;
			x2 = (-b - sqrt(d)) / 2 * a;
			cout << "x_1 = " << x1 << endl;
			cout << "x_2 = " << x2 << endl;
		}
		if (d < 0)
		{
			cout << "Дискриминант < 0" << endl;
		}
	}
	else
		cout << "Высшая степень полинома не 2" << endl;
}
#endif
enum Menu
{
	Exit = 0,
	Add_polinom,
	Output,
	Multiply,
	Find_korni,
	Plus,
	Minus,
};

int main()
{
	system("chcp 1251");
#ifdef MY_LIST
	vector<list<int>> k;
	list<int> l;
#else
	vector<List<int>> k;
	List<int> l;
#endif
	while (true) 
	{
		cout << "1. Добавить многочлен" << endl;
		cout << "2. Вывести многочлен" << endl;
		cout << "3. Умножить многочлен на число" << endl;
		cout << "4. Найти корни квадратного уравнения" << endl;
		cout << "5. Добавить два полинома" << endl;
		cout << "6. Отнять два полинома" << endl;
		cout << "0. Выход из программы" << endl;
		int menu;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case Add_polinom:
		{
			Polinom(l, k);
			system("cls");
			break;
		}
		case Output:
		{
			Output_polinom(k);
			system("pause");
			system("cls");
			break;
		}
		case Multiply:
		{
			Multiplication(k);
			system("cls");
			break;
		}
		case Find_korni:
		{
			Korni(k);
			system("pause");
			system("cls");
			break;
		}
		case Plus:
		{
			Arithmetic(k, l);
			system("cls");
			break;
		}
		case Minus:
		{
			Arithmetic(k, l, minus<>());
			system("cls");
			break;
		}
		case Exit:
		{
			return 0;
		}
		default:
		{
			cout << "Введите 1, 2, 3, 4, 5, 6 или 0" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}
