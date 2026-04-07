#include <iostream>
#include <string.h>

void main() {
    char str1[40] = "Hello, ";
    char str2[40];
    strcpy_s(str2, str1);
    strcat_s(str1, "World!");
    strcat_s(str2, "John Doe!");

    std::cout << "str1=\"" << str1 << "\" len=" << strlen(str1) << std::endl;
    std::cout << "str2=\"" << str2 << "\" len=" << strlen(str2) << std::endl;
    std::cout << "str1 == str2? " << strcmp(str1, str2) << std::endl;
}