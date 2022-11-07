// лб 3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <Windows.h>

using namespace std;

class parallelogram {
    double base, side, h;
    unsigned int color;
public:
    parallelogram() : base(2.0), side(1.0), h(0.5), color(0) {}
    parallelogram(double base_i, double side_i, double h_i) : base(base_i), side(side_i), h(h_i), color(0) {}
    parallelogram(int ic) : base(2.0), side(1.0), h(0.5) { if (ic >= 0) color = ic; else color = 0; }
    parallelogram(double base, double side, double h, int c) {
        this->base = base;
        this->side = side;
        this->h = h;
        if (c >= 0) color = c; else color = 0;
    }
    void set_base(double base)
    {
        if (base < 0 || base > 1.e+100)
        {
            cout << " Помилкове значення основи \n";
            return;
        }
        this->base = base;
    }
    void set_side(double side)
    {
        if (side < 0 || side > 1.e+100)
        {
            cout << " Помилкове значення бічної сторони \n";
            return;
        }
        this->side = side;
    }
    void set_h(double h)
    {
        if (h < 0 || h > 1.e+100)
        {
            cout << " Помилкове значення висоти \n";
            return;
        }
        this->h = h;
    }
    void setColor(int c)
    {
        if (c < 0 || c > 10000)
        {
            cout << " Помилкове значення кольору \n";
            return;
        }
        this->color = c;
    }
    double S() {
        return base * h;
    }
    double P() {
        return 2 * base + 2 * side;
    }
    void printInfo()
    {
        cout << "\nОснова = " << base << "\tБічна сторона = " << side << "\tВистота = " << h << "\tколір = " << color << endl;
        cout << " S= " << S() << " Р = " << P() << endl;
    }
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    parallelogram obj;
    obj.printInfo();
    double base, side, h; int color;
    cout << " Введіть основу: "; cin >> base;
    cout << " Введіть бічну сторону: "; cin >> side;
    cout << " Введіть висоту: "; cin >> h;
    cout << " Введіть колір: "; cin >> color;
    parallelogram obj1(base, side, h), obj2(color), obj3(base, side, h, color);
    obj1.printInfo();
    obj2.printInfo();
    obj3.printInfo();
    obj.set_base(-5);
    obj.printInfo();
    obj.set_side(5);
    obj.printInfo();
    obj.set_h(2.e100);
    obj.printInfo();
    obj.setColor(-10);
    obj.printInfo();
    obj.setColor(10);
    obj.printInfo();
    obj.setColor(10001);
    obj.printInfo();
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
