#include <iostream>
#include <fstream>

int main() {
    char name[12];
    std::fstream fin;
    std::cout << "Введите имя файла: ";
    std::cin >> name;

    fin.open(name);
    if (fin) {
        std::cout << "Файл открыт " << name << std::endl;
        fin.close();
    }
    else {
        std::cout << "Не открыт выходной файл " << name << std::endl;
    }
    return 0;
}
