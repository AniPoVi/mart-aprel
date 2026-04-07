#include <iostream>

void main() {
    // 17 чтобы хватило места при копировании, иначе строка 0 перетрет строку 1
    char str[2][17] = { "querty", "1234567890" };

    int dlina1(char*);
    int dlina2(char*);
    int dlina3(char*);
    void kopir(char*, char*);
    bool sravn(char*, char*);
    void konkat(char*, char*);

    std::cout << "длина str1=" << dlina1(str[0]) << ", str2=";
    std::cout << dlina1(str[1]) << std::endl;
    std::cout << "длина str1=" << dlina2(str[0]) << ", str2=";
    std::cout << dlina2(str[1]) << std::endl;
    std::cout << "длина str1=" << dlina3(str[0]) << ", str2=";
    std::cout << dlina3(str[1]) << std::endl;
    kopir(str[0], str[1]);
    std::cout << "результат копирования: str1=" << str[0];
    std::cout << " , str2=" << str[1] << std::endl;
    std::cout << "результат сравнения: str1=" << str[0];
    std::cout << " , str2=" << str[1] << " " << sravn(str[0], str[1]) << std::endl;
    konkat(str[0], str[1]);
    std::cout << "результат сцепления: str1=" << str[0];
    std::cout << ", str2=" << str[1] << std::endl;
}

int dlina1(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

int dlina2(char* str) {
    const char* p = str;
    while (*p != '\0') {
        ++p;
    }
    return p - str;
}

int dlina3(char* str) {
    return (*str == '\0') ? 0 : (1 + dlina3(str + 1));
}

void kopir(char* str1, char* str2) {
    while (*str1 != '\0') {
        *str2++ = *str1++;
    }
    *str2 = '\0';
}

bool sravn(char* str1, char* str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return true;
        }
        ++str1;
        ++str2;
    }
    return false;
}

void konkat(char* str1, char* str2) {
    while (*str1 != '\0') {
        ++str1;
    }
    while (*str2 != '\0') {
        *str1++ = *str2++;
    }
    *str1 = '\0';
}

