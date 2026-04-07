#include <iostream>

#include "Stroka.h"

void main() {
    Stroka s1((char*)"quert"), s3, s4(s1), s5;
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();
    s5 = s1 + s3 + s4;
    std::cout << "длина s5 = " << s5.dlina();
    s5.vyvod();
    if (s1 == s5)
        std::cout << "строки s1 и s5 равны";
    else if (s1 == s4)
        std::cout << "строки s1 и s4 равны";
}
