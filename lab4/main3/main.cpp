#include <iostream>

void main() {
    char* str1, * str2;
    str1 = (char*)calloc(100, sizeof(char));
    str2 = (char*)calloc(100, sizeof(char));

    int dlina1(char*);
    int dlina2(char*);
    int dlina3(char*);
    void kopir(char*, char*);
    bool sravn(char*, char*);
    void konkat(char*, char*);
    kopir((char*)"qwerty", str1);
    kopir((char*)"1234567890", str2);

    std::cout << "длина str1=" << dlina1(str1) << ", str2=";
    std::cout << dlina1(str2) << std::endl;
    std::cout << "длина str1=" << dlina2(str1) << ", str2=";
    std::cout << dlina2(str2) << std::endl;
    std::cout << "длина str1=" << dlina3(str1) << ", str2=";
    std::cout << dlina3(str2) << std::endl;
    kopir(str1, str2);
    std::cout << "результат копирования: str1=" << str1;
    std::cout << " , str2=" << str2 << std::endl;
    std::cout << "результат сравнения: str1=" << str1;
    std::cout << " , str2=" << str2 << " " << sravn(str1, str2) << std::endl;
    konkat(str1, str2);
    std::cout << "результат сцепления: str1=" << str1;
    std::cout << ", str2=" << str2 << std::endl;
    free(str1);
    free(str2);
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

