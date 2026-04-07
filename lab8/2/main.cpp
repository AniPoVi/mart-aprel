#include <iostream>
#include <fstream>

int main() {
    char fname[15], c;
    std::cout << "Введите имя входного файла";
    std::cin >> fname;

    std::ifstream ifs(fname);
    if (!ifs) {
        std::cout << "Не открыт входной файл " << fname;
    }
    std::cout << "Введите имя выходного файла";
    std::cin >> fname;

    std::ofstream ofs(fname);
    if (!ofs) {
        std::cout << "Не открыт выходной файл " << fname;
    }

    while (ifs && ofs) {
        ifs.get(c);
        c = toupper(c);
        ofs.put(c);
        std::cout << ".";
        std::cout << std::endl
            << "Выходной файл является копией "
            << "входного файла"
            << " в верхнем регистре";
    }
    return 0;
}