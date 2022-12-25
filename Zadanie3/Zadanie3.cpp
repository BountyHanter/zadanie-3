﻿#include <iterator>
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>
#include <string>
#include <set>

using namespace std;
class mine
{
public:
	int a;
	bool operator == (mine& other)
	{
		if (this->a == other.a)
			return true;
		else return false;
	}
};
template <typename T1> 
T1 max2(const T1& a,const T1& b) 
{
	return (a > b) ? a : b;
}
template <typename T1>
T1 max3(const T1& a,const T1& b,const T1& c)
{
	return max2(max2(a, b),c);
}
template <typename T1> // подходит и для чисел и для строки и для вектора, вывод по индексу 
void masINDX(const T1& a, int size1) 
{ // получаем размер контейнера с индексами для счётчика
	for (int i = 0;i != size1;++i) // выводим элементы из контейнера а по индексам которые хранятся в контейнере б
	{
		cout << a[i]<<"\n";
	}
}
template <typename T1>
void iter(const T1& list)
{
	for (auto it = list.begin(); it !=list.end(); it++)
	{

		cout << *it << " ";
	}
}
//template <typename T1>
//void iter(set <T1> a)
//{
//	set<T1> book = a;
//	for (auto it = book.begin(); it != book.end(); it++)
//	{
//
//		cout << *it << " ";
//	}
//}
template <typename T1>
void iter(T1 a)
{
	T1 book = a;
	for (auto it = book.begin(); it != book.end(); it++)
	{

		cout << *it << " ";
	}
}
template <typename T1, typename T2>
void map1(map<T1, T2> argument1) // переписываем внутрь функции контейнер, создаем итератор и проходимся по контейнеру
{
	typename map<T1, T2>::iterator it = argument1.begin();
	for (; it != argument1.end(); it++)
	{
		cout << it->first << " " << it->second << "\n";
	}
	/*for (const auto &iter: argument1)
		cout << it.first << " " << it.second << "\n";
	for (auto iter = argument1.begin(); it != argument1.end(); it++)
		cout << it->first << " " << it->second << "\n";*/

	
}
template <typename T1, typename T2, typename T3>
void findMap(map<T1, T2> argument1, T3 a)
{
	//map<T1, T2> book = argument1; // переписываем как в предыдущем, используем поиск через итератор и выводим то что нужно
	typename map<T1, T2>::iterator it;
	it = argument1.find(a);
	if (it != argument1.end())
		cout << "value with key " <<" \" " << it->first << " \" " << " is - " << it->second;
	else
		cout << "value with key " << a << " not found\n";
}
template <typename T1, typename T2> // кстати ввожу с ключами разных типов !!! СПРОСИТЬ ЕСЛИ ЗНАЧЕНИЯ РАЗНЫХ ТИПОВ
void findUniq(map<T1, T2> argument1, map<T1, T2> argument2) // здесь так же переписываем,и все шо я придумал, это сравниваеть первый со вторым, выписывая уникальные из первого, потом наоборот

	//int n = 0;
	//typename map<T1, T2>::iterator it = book.begin();
	//typename map<T1, T2>::iterator it2 = book2.begin();
	//for (; it != book.end(); it++)
	//{
	//	n = 0;
	//	it2 = book2.begin();
	//	for (; it2 != book2.end(); it2++)
	//	{
	//		if (it->second != it2->second)
	//			n++;
	//	}
	//	if(n==book.size()) // тут если счётчик равен размеру массива, значит похожих элементов не нашлось, и значит выводим элемент ( тут вывожу и ключ и значение )
	//		cout << it->first << " " << it->second << " ";
	//}
	//it = book.begin();
	//it2 = book2.begin();
	//for (; it2 != book2.end(); it2++)
	//{
	//	n = 0;
	//	it = book.begin();
	//	for (; it != book.end(); it++)
	//	{
	//		if (it2->second != it->second)
	//			n++;
	//	}
	//	if (n == book2.size())
	//		cout << it2->first << " " << it2->second << " ";
	//}
	{
		map<T1 T2> result;
		for (const auto& iter : argument1)
		{
			auto find_iter = argument2.find(iter.first);
			if (find_iter == argument2.end())
				result[iter.first] = iter.second;
		}
		for (const auto& iter : argument2)
		{
			auto find_iter = argument1.find(iter.first);
			if (find_iter == argument1.end())
				result[iter.first] = iter.second;
		}
		}

template <typename T1>
void averageINDX(T1 a, int size)
{
	double c = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		c = c + a[i];
	}
	c = c / i;
	cout << c;
}
template <typename T1>
void averageIT(vector<T1> a)
{
	size_t size = a.size();
	double average = 0;
	for (auto it = book.begin(); it != book.end(); it++)
	{
		average += *it;
	}
	average = average / size;
	cout << average;
}
//template <typename T1>
//void averageIT(set<T1> a)
//{
//	set<T1> book = a;
//	size_t size = a.size();
//	double average = 0;
//	for (auto it = book.begin(); it != book.end(); it++)
//	{
//		average += *it;
//	}
//	average = average / size;
//	cout << average;
//}
template <typename T1>
void averageIT( T1 a)
{
	T1 book = a;
	size_t size = a.size();
	double average = 0;
	for (auto it = book.begin(); it != book.end(); it++)
	{
		average += *it;
	}
	average = average / size;
	cout << average;
}
int main()
{
	cout << "zadanie1 \n______________________\n";
	double double1 = 5.92, double2 = 9.009, double3 = 20.921228;
	cout << "double1 = " << double1 << " double2 = " << double2 << " double3 = " << double3 << endl;
	auto maxduble = max3(double1, double2, double3);
	cout << "max3 double = " << maxduble << "\n";
	char char1 = 'a', char2 = 'b', char3 = 'c';
	cout << "char1 - " << char1 << " char2 - " << char2 << " char3 - " << char3 << endl;
	auto maxChar = max3(char1, char2, char3);
	cout << "max char = " << maxChar << "\n";
	float float1 = 9.99, float2 = 0.9993;
	cout << "float1 = " << float1 << " float2 = " << float2 << endl;
	auto maxFloat = max2(float1, float2);
	cout << "max float = " << maxFloat << "\n";
	mine my1;
	my1.a = 5;
	mine my2;
	my2.a = 9;
	auto b = max2(my1.a, my2.a);
	cout << "MyClass max2 = " << b << "\n";
	cout << "______________________\n";
	cout << "zadanie2 \n______________________\n";
	int masIndx[7] = {0,1,2,3,4,5,6};
	double masDuble[7] = { 1.1,2.22,3.33,4.44,5.55,6.66,7.77 };
	cout << "array\n";
	masINDX(masIndx,7);
	vector<int> vec = { 1,2,3,4,5,6,7 };
	cout << "vector\n";
	masINDX(vec,vec.size());
	cout << "string \n";
	string str = "abcdefg";
	masINDX(str, str.size());
	cout << "______________________\n";
	cout << "zadanie3 \n______________________\n";
	cout << "vector\n";
	iter(vec);
	cout << endl;
	cout << "string\n";
	iter(str);
	cout << endl;
	cout << "set\n";
	set<int> mySet = { 1,2,3,4,5,6,7 };
	iter(mySet);
	cout << endl;
	cout << "______________________\n";
	cout << "zadanie4 \n______________________\n";
	map<int, string> myMap;
	myMap.emplace(1, "a");
	myMap.emplace(2, "b");
	myMap.emplace(3, "c");
	myMap.emplace(4, "d");
	map1(myMap);
	cout << "______________________\n";
	cout << "zadanie5 \n______________________\n";
	findMap(myMap, 2);
	cout << endl;
	findMap(myMap, 8);
	cout << "______________________\n";
	cout << "zadanie6 \n______________________\n";
	map<string, string> myMap2;
	myMap2.emplace("one", "a");
	myMap2.emplace("two", "e");
	myMap2.emplace("three", "c");
	myMap2.emplace("four", "d");
	cout << "the unique elements are \n";
	findUniq(myMap, myMap2);
	cout << endl;
	cout << "______________________\n";
	cout << "zadanie7 \n______________________\n";
	cout << "average array\n";
	averageINDX(masIndx,7);
	cout << endl;
	cout << "average string\n";
	averageINDX(str,str.size());
	cout << endl;
	cout << "average vector\n";
	averageINDX(vec,vec.size());
	cout << endl;
	cout << "______________________\n";
	cout << "zadanie8 \n______________________\n";
	cout << "vector\n";
	averageIT(vec);
	cout << endl;
	cout << "string\n";
	averageIT(str);
	cout << endl;
	cout << "set\n";
	averageIT(mySet);
	cout << "\n______________________\n";





}
