#include <iostream>
#include <fstream>

const char fname[] = "NewFile";

int main() {
    std::ofstream ofs(fname, std::ios::out | std::ios::_Noreplace);
    if (!ofs) {
        std::cout << "Ошибочная ситуация! Файл "
                << fname
                << " уже существует."
                << std::endl;
        return 0;
    } else {
        ofs << "Эта строка записывается "
                << "в новый файл";
        ofs.close();
        std::fstream fs;
        fs.open(fname, std::ios::out | std::ios::ate);
        fs << "Сейчас к ней сделано добавление";
        fs.close();
        std::fstream ifs(fname);
        if (ifs) {
            std::cout << "В старом файле содержится "
                    << "..." << std::endl;
            char Line[80];
            ifs.getline(Line, sizeof(Line));
            std::cout << Line;
        } else {
            std::cout << "Ошибочная ситуация "
                    << "при повторном открытии "
                    << fname
                    << std::endl;
        }
    }
    return 0;
}
