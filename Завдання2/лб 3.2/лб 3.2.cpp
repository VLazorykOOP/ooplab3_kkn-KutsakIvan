// лб 3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <complex>
#include <Windows.h>

using namespace std;

class Vector
{
	short* v;
	int num;
	int state;
public:
	Vector() : v(NULL), num(0), state(0) {}
	Vector(int n);
	Vector(int n, short&);
	Vector(int n, short*);
	Vector(const Vector& s);
	Vector& operator=(const Vector& s);
	~Vector() {
		cout << " del vec";
		if (v) delete[] v;
	}
	short getV(int i)
	{
		return v[i];
	}
	void default_(int i);
	void foo(short x);
	void Output();
	void Input();	
	Vector Add(Vector& b);
	Vector minus_(Vector& b);
	Vector multiplication(Vector& b);
	boolean more(short x, short x1);
	boolean equal(short x, short x1);
};
Vector::Vector(int n) {
	if (n <= 0)
	{
		v = NULL; num = 0; state = -1; cout << " Vec --> 0 ";
	}
	num = n;
	v = new short[n];
	for (int i = 0; i < n; i++) 
	{
		v[i] = 0;
	}
}
Vector::Vector(int n, short& b) {
	if (n <= 0) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
	num = n;
	v = new short[n];
	for (int i = 0; i < n; i++) {
		v[i] = b; 
	}
}
Vector::Vector(int n, short* p) {
	if (n <= 0 || p == NULL) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
	num = n;
	v = new short[n];
	for (int i = 0; i < n; i++) {
		v[i] = p[i];
	}
}
Vector::Vector(const Vector& s) {
	num = s.num;
	v = new short[num];
	state = 0;
	for (int i = 0; i < num; i++) v[i] = s.v[i];
}
Vector& Vector::operator=(const Vector& s) {
	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new short[num];
		state = 0;
	}
	for (int i = 0; i < num; i++) v[i] = s.v[i];
	return *this;
}
void Vector:: default_(int i)
{
	v[i] = 5;
}
void Vector::foo(short x)
{
	cout << x;
}
void Vector::Input()
{

	if (num == 0) 
	{
		if (v) delete[] v;
		do {
			cout << "Введіть довжину масива\n";
			cin >> num;
		} while (num <= 0);
		v = new short[num];
	}
	for (int i = 0; i < num; i++) {
		cout << " v [ " << i << " ]: "; cin >> v[i];
	}
}
void Vector::Output() {
	if (num != 0) 
	{
		for (int i = 0; i < num; i++) 
		{
			cout << " v [ " << i << " ] " << v[i] << '\t';
			cout << endl;
		}
	}
}
Vector Vector::Add(Vector& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
		return tmp;
	}
	return Vector(0);
}
Vector Vector::minus_(Vector& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] - b.v[i];
		return tmp;
	}
	return Vector(0);
}
Vector Vector::multiplication(Vector& b) 
{
	int tnum;
	unsigned char x = 4;
	tnum = num < b.num ? num : b.num;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = x * v[i];
		return tmp;
	}
	return Vector(0);
}
boolean Vector ::more(short x, short x1)
{
	if (x > x1)return true;
	else return false;	
}

boolean Vector::equal(short x, short x1)
{
	if (x == x1)return true;
	else return false;
}

void main(int argc, TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short a, b, c;
	a = 1;
	b = 22;
	Vector VecObj, VecObj1(10), VecObj2(5);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	VecObj2.default_(0);
	cout << "VecObj2 \n";
	VecObj2.Output();
	VecObj2.foo(VecObj2.getV(1));
	cout << "\n//" << VecObj2.getV(0)<<"//\n";
	cout << " Input a " << endl;
	cin >> a;
	Vector VecObj3(10, a );
	cout << "\n*****\n";
	cout << endl;
	
	VecObj3.Output();
	VecObj.Input();
	cout << endl;
	VecObj.Output();
	VecObj1 = VecObj.Add(VecObj3);
	cout << endl;
	VecObj1.Output();

	VecObj1 = VecObj.multiplication(VecObj3);
	cout << endl;
	VecObj1.Output();

	VecObj1 = VecObj.minus_(VecObj3);
	cout << endl;
	VecObj1.Output();
	cout << endl << VecObj.getV(0) << " > " << VecObj3.getV(0) << " - ";
	if (VecObj.more(VecObj.getV(0), VecObj3.getV(0)))cout << "true" << endl;
	else cout << "false" << endl;
	cout << endl << VecObj.getV(0) << " = " << VecObj3.getV(0) << " - ";
	if (VecObj.equal(VecObj.getV(0), VecObj3.getV(0)))cout << "true" << endl;
	else cout << "false" << endl;
	
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
