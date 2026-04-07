#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("input.txt");

    if (!in.is_open()) {
        std::cout << "Файл не открыт" << std::endl;
        return 1;
    }

    std::cout << "Файл открыт" << std::endl;

    char buffer[100];
    std::cout << "Содержимое файла:" << std::endl;
    while (in >> buffer) {
        std::cout << buffer << " ";
    }

    in.clear();

    int len = in.seekg(0, std::ios::end).tellg();
    int mid = len / 2;
    in.seekg(mid);

    if (in.fail()) {
        std::cout << "Ошибка при возврате в середину файла" << std::endl;
        return 1;
    }

    std::cout << std::endl << "Чтение из середины:" << std::endl;
    while (in >> buffer) {
        std::cout << buffer << " ";
    }

    in.close();
    std::cout << std::endl << "Файл закрыт" << std::endl;
    return 0;
}
