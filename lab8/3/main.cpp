#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    char* input = argv[1];
    char* output = argv[2];
    char* key = argv[3];
    int keyLength = strlen(key);
    std::ifstream in;
    std::ofstream out;

    in.open(input);
    if (!in) {
        std::cout << "Файл " << input << " не открыт";
        in.close();
        return 0;
    }
    out.open(output);
    if (!out) {
        std::cout << "Файл " << output << " не открыт";
        out.close();
        in.close();
        return 0;
    }

    char ch;
    int keyIndex = 0;
    while (!in.eof()) {
        in >> ch;
        int encoded = ch ^ key[(keyIndex++) % keyLength];
        out << (char)encoded;
    }
    in.close();
    out.close();
    return 0;
}
