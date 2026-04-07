#include <cstring>
#include <iostream>

int main(int argc, char** argv) {
    char* input = argv[1];
    char* output = argv[2];
    char* key = argv[3];
    int keyLength = strlen(key);
    FILE* in;
    fopen_s(&in, input, "r");
    FILE* out;
    fopen_s(&out, output, "w");

    if (!in) {
        printf("Файл %s не открыт", input);
        return 0;
    }
    if (!out) {
        printf("Файл %s не открыт", output);
        return 0;
    }

    char ch;
    int keyIndex = 0;
    while ((ch = getc(in)) != EOF) {
        int encoded = ch ^ key[(keyIndex++) % keyLength];
        putc(encoded, out);
    }
    return 0;
}
