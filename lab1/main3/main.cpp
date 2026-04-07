#include <iostream>

void main() {
    int a = 2, b = 5;
    void obmen1(int, int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);
    std::cout << "до обмена: a=" << a << ", b=" << b << std::endl;
    obmen1(a, b);
    std::cout << "после обмена 1: a=" << a << ", b=" << b << std::endl;
    obmen2(&a, &b);
    std::cout << "после обмена 2: a=" << a << ", b=" << b << std::endl;
    obmen3(a, b);
    std::cout << "после обмена 3: a=" << a << ", b=" << b << std::endl;
}

void obmen1(int a, int b) {
    int t = a;
    a = b;
    b = t;
    // т.к. в функцию передаем значения на перемернные a и b из main мы повлиять не можем
}

void obmen2(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void obmen3(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}
