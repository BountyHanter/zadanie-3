#include <iterator>
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
	bool operator == (const mine& other)
	{
		if (this->a == other.a)
			return true;
		else return false;
	}
};
template <typename T1, typename T2> 
auto max2(T1 a, T2 b) 
{
	return (a > b) ? a : b;
}
template <typename T1, typename T2, typename T3>
auto max3(T1 a, T2 b, T3 c)
{
	if (a > b)
		return (a > c) ? a : c;
	else
		return (b > c) ? b : c;
}
template <typename T1, typename T2> // подходит и для чисел и для строки и для вектора, вывод по индексу 
void masINDX(T1 a, T2 b) 
{
	int g = sizeof(b) / sizeof(b[0]); // получаем размер контейнера с индексами для счётчика
	for (int i = 0;i <= g;i++) // выводим элементы из контейнера а по индексам которые хранятся в контейнере б
	{
		cout << a[b[i]]<<"\n";
	}
}
template <typename T1>
void iter(vector <T1> a)
{
	vector<T1> book = a;
	for (auto it = book.begin(); it != book.end(); it++)
	{

		cout << *it << "\n";
	}
}
template <typename T1>
void iter(set <T1> a)
{
	set<T1> book = a;
	for (auto it = book.begin(); it != book.end(); it++)
	{

		cout << *it << "\n";
	}
}
template <typename T1>
void iter(T1 a)
{
	T1 book = a;
	for (auto it = book.begin(); it != book.end(); it++)
	{

		cout << *it << "\n";
	}
}
template <typename T1, typename T2>
void map1(map<T1, T2> argument1) // переписываем внутрь функции контейнер, создаем итератор и проходимся по контейнеру
{
	map<T1, T2> book = argument1;
	typename map<T1, T2>::iterator it = book.begin();
	for (; it != book.end(); it++)
	{
		cout << it->first << " " << it->second << "\n";
	}

	
}
template <typename T1, typename T2, typename T3>
void findMap(map<T1, T2> argument1, T3 a)
{
	map<T1, T2> book = argument1; // переписываем как в предыдущем, используем поиск через итератор и выводим то что нужно
	typename map<T1, T2>::iterator it;
	it = book.find(a);
	if (it != book.end())
		cout << "value with key " <<" \" " << it->first << " \" " << " is - " << it->second;
	else
		cout << "value with key " << a << " not found";
}
template <typename T1, typename T2, typename T3, typename T4> // кстати ввожу с ключами разных типов !!! СПРОСИТЬ ЕСЛИ ЗНАЧЕНИЯ РАЗНЫХ ТИПОВ
void findUniq(map<T1, T2> argument1, map<T3, T4> argument2) // здесь так же переписываем,и все шо я придумал, это сравниваеть первый со вторым, выписывая уникальные из первого, потом наоборот
{
	map<T1, T2>book = argument1;
	map<T3, T4>book2 = argument2;
	int n = 0;
	typename map<T1, T2>::iterator it = book.begin();
	typename map<T3, T4>::iterator it2 = book2.begin();
	for (; it != book.end(); it++)
	{
		n = 0;
		it2 = book2.begin();
		for (; it2 != book2.end(); it2++)
		{
			if (it->second != it2->second)
				n++;
		}
		if(n==book.size()) // тут если счётчик равен размеру массива, значит похожих элементов не нашлось, и значит выводим элемент ( тут вывожу и ключ и значение )
			cout << it->first << " " << it->second << " ";
	}
	it = book.begin();
	it2 = book2.begin();
	for (; it2 != book2.end(); it2++)
	{
		n = 0;
		it = book.begin();
		for (; it != book.end(); it++)
		{
			if (it2->second != it->second)
				n++;
		}
		if (n == book2.size())
			cout << it2->first << " " << it2->second << " ";
	}

}
//template <typename T1>
//void averageINDX(char a) // проблема в том что нужно универсальное определение размера и для строки и для массива
//{
//	int c = 0;
//	int i = 0;
//	while (a[i])
//	{
//		c += a[i];
//		i++;
//	}
//	cout << c / i;
//}
template <typename T1>
void averageIT(vector<T1> a)
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
template <typename T1>
void averageIT(set<T1> a)
{
	set<T1> book = a;
	size_t size = a.size();
	double average = 0;
	for (auto it = book.begin(); it != book.end(); it++)
	{
		average += *it;
	}
	average = average / size;
	cout << average;
}
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
//template <typename T1>
//void averageIT(T1 a) // точно так же и здесь, для строки и вектора итератор vector, а для множества set
//{
//	int c = 0;
//	typename vector<T1>::iterator = it.begin();
//	while (a[i])
//	{
//		c += a[i];
//		i++;
//	}
//	cout << c / i;
//}
void choose()
{
	double n, x, y, z;
	cout << "How many elements you want compare?\n";
	cin >> n;
		if (n == 2)
		{
			cout << "Enter 2 elements:\n";
			cin >> x >> y;
			cout << max2(x, y);
		}
		else if (n == 3)
		{
			cout << "Enter 3 elements:\n";
			cin >> x >> y >> z;
			cout << max3(x, y, z);

		}
		else
		{
			cout << "Error, enter number again\n";
		}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//int b;
	//cin >> b;
	//int m2[5] = { 2,4,6 };
	//double m1[10] = { 1.1,2.2,3.3,4.4,5,6.6,7.7777,8.8,9.9,10 };
	string str = "абв";
	//masINDX(m1, m2);
	//////choose(); // первое задание 
	vector <int> my;
	my.push_back(5);
	my.push_back(3);
	my.push_back(11);
	my.push_back(2);
	my.push_back(1);
	my.push_back(5);
	my.push_back(12);
	my.push_back(13);
	my.push_back(40);
	my.push_back(55);
	my.push_back(10);
	set<int> mySet;
	mySet.insert(1);
	mySet.insert(2);
	mySet.insert(3);
	mySet.insert(4);
	mySet.insert(5);
	vector<int> gb = { 0,1,2,3 };
	//averageIT(str);
	//masINDX(my, m2);
	//struct Node
	//{
	//	int g = 5;
	//	Node* left;
	//};
	//Node* s = new Node;
	//cout << sizeof(s);
	map<string, string> book;
	map<int, int> book2;
	book.emplace("b", "num1");
	book.emplace("d", "num2");
	book.emplace("a", "num3");
	book.emplace("c", "num4");
	book2.emplace(1, 1);
	book2.emplace(2, 2);
	book2.emplace(3, 3);
	book2.emplace(4, 4);
	typename map<string, string>::iterator it = book.begin();
	//findUniq(book,book2);
	string g = "12345";
	int b = 0;
	int gg[5] = { 1,2,3,4,5 };
	//averageINDX(gg);
	/*int sum = 0;
	for (auto& i : gg)
	{ 
		sum += i;                             СПРОСИТЬ КАК РАБОТАЕТ
		b++;
	}
	sum=sum/b;
	std::cout << sum << std::endl;*/
	
}

// вопрос 1) задание 3, нужно понять, итератор универсальный или для кжадого свой, потому что так я могу только для кжадого свой
// вопрос 2) задание 8, итератор для вектора и множества это вектор а для множества set, что делать?