#include "Stroka.h"

#include <cstring>
#include <iostream>


void kopir(char* str1, const char* str2) {
    while (*str2 != '\0') {
        *str1++ = *str2++;
    }
    *str1 = '\0';
}

void kopir(char* str1, const char& str2) {
    kopir(str1, &str2);
}

Stroka::Stroka(char* string) {
    str = (char*)calloc(80, sizeof(char));
    kopir(str, string);
}

Stroka::Stroka(const Stroka& stroka) {
    str = (char*)calloc(80, sizeof(char));
    kopir(str, stroka.str);
}

Stroka::Stroka(int i) {
    str = (char*)calloc(i, sizeof(char));
}

Stroka& Stroka::operator=(const Stroka& s) {
    kopir(str, s.str);
    return *this;
}

Stroka& Stroka::operator+(const Stroka& s) {
    char* str1 = str;
    char const* str2 = s.str;
    while (*str1 != '\0') {
        ++str1;
    }
    while (*str2 != '\0') {
        *str1++ = *str2++;
    }
    *str1 = '\0';
    return *this;
}

int Stroka::operator==(const Stroka& s) {
    char* str1 = str;
    const char* str2 = s.str;
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 1;
        }
        ++str1;
        ++str2;
    }
    return 0;
}

int Stroka::dlina() {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

std::istream& operator>>(std::istream& in, Stroka& s) {
    in >> *s.str;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Stroka& s) {
    out << s.str;
    return out;
}

void Stroka::vvod() {
    std::cin >> *str;
}

void Stroka::vyvod() {
    std::cout << str;
}
