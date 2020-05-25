#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <cmath>
#include "My_List.h"
using namespace std;

template<class Binary = plus<>>
void Arithmetic(vector<list<int>>&k, list<int> &l, Binary bin = plus<>()) {
	int n, m;
	cout << "������ ������� - ";
	cin >> n;
	n--;
	cout << "������ ������� - ";
	cin >> m;
	m--;
	auto first =  k[n].rbegin();
	auto second = k[m].rbegin();
	auto third =  k[n].rend();
	auto fourth = k[m].rend();

	if (k[m].size() > k [n].size())
	{
		swap(first, second);
		swap(third, fourth);
	}

	for (; first != third; ++first)
	{
		if (second != fourth) {
			l.push_front(bin(*first, *second));
			++second;
		}
		else {
			l.push_front(*first);
		}
	}
	k.push_back(l);
	l.clear();
}

void Polinom(list<int> &l, vector<std::list<int>> &k)
{
	int m, n;
	cout << "����� �������?" << endl;
	cin >> m;
	m++;
	cout << "������� ������������" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		l.push_back(n);
	}
	k.push_back(l);
	l.clear();
}

void Viviod(vector<list<int>> &k)
{
	int n;
	cout << "����� �������?" << endl;
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

void Umnozhit(list<int>::iterator &it, vector<list<int>> &k)
{
	int n, m, i = 0;
	cout << "�� ����� ����� ���� ��������?" << endl;
	cin >> m;
	cout << "����� �������?" << endl;
	cin >> n;
	n--;
	for (it = k[n].begin(); it != k[n].end(); ++it)
	{
		i++;
		*it *= m;
		if (*it > 0 && i == 1)
			cout << *it << "x^" << k[n].size() - i; //��� ����� ������� �������
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

void Korni(vector<list<int>> &k)
{
	double a, b, c, d, x1, x2, n, i = 0, proverka;
	cout << "����� �������?" << endl;
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
			cout << "������������ < 0" << endl;
		}
	}
	else
		cout << "������ ������� �������� �� 2" << endl;
}

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


int main() {
	My_List<int> l;
	l.push_back(2);
	l.push_back(2);
	l.clear();
	l.push_front(90);
	//l.push_back(3);
	//l.pop_back();
	l.push_front(12);
	l.pop_front();
	cout << l.size() << endl;
	//cout << l[1] << endl;
	//list <int> ::iterator it;
	/*for (auto &f : l)
	{
		cout << f << " ";
	}*/
	system("pause");
	return 0;
}

//
//int main()
//{
//	system("chcp 1251");
//	vector<list<int>> k;
//	list<int> l;
//	list <int> ::iterator it;
//	list <int> ::reverse_iterator itt;
//	while (true) 
//	{
//		cout << "1. �������� ���������" << endl;
//		cout << "2. ������� ���������" << endl;
//		cout << "3. �������� ��������� �� �����" << endl;
//		cout << "4. ����� ����� ����������� ���������" << endl;
//		cout << "5. �������� ��� ��������" << endl;
//		cout << "6. ������ ��� ��������" << endl;
//		cout << "0. ����� �� ���������" << endl;
//		int menu;
//		cin >> menu;
//		system("cls");
//		switch (menu)
//		{
//		case Add_polinom:
//		{
//			Polinom(l, k);
//			system("cls");
//			break;
//		}
//		case Output:
//		{
//			Viviod(k);
//			system("pause");
//			system("cls");
//			break;
//		}
//		case Multiply:
//		{
//			Umnozhit(it, k);
//			system("cls");
//			break;
//		}
//		case Find_korni:
//		{
//			Korni(k);
//			system("pause");
//			system("cls");
//			break;
//		}
//		case Plus:
//		{
//			Arithmetic(k, l);
//			system("cls");
//			break;
//		}
//		case Minus:
//		{
//			Arithmetic(k, l, minus<>());
//			system("cls");
//			break;
//		}
//		case Exit:
//		{
//			return 0;
//		}
//		default:
//		{
//			cout << "������� 1, 2, 3, 4, 5, 6 ��� 0" << endl;
//			system("pause");
//			system("cls");
//			break;
//		}
//		}
//	}
//}
