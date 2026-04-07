#include <iostream>

void main() {
	char name[50];
	printf("Введите имя файла для просмотра: ");
	scanf_s("%s", name, 50);
	FILE* in;
	fopen_s(&in, name, "r");
	if (!in) {
		printf("Файл %s не открыт", name);
		return;
	}

	char ch;
	while ((ch = getc(in)) != EOF) {

		putchar(ch);
	}

	std::cout << std::endl;

	void count(char* filename, int& empty, int& nonempty);
	int empty = 0;
	int nonempty = 0;
	count(name, empty, nonempty);
	std::cout << "Количество пустых символов: " << empty << std::endl;
	std::cout << "Количество непустых символов: " << nonempty << std::endl;

	void find(char* filename, char* output, char* str);
	char str[] = "Halo!";
	find(name, (char*)"output.txt", str);
}

void count(char* filename, int& empty, int& nonempty) {
	FILE* in;
	fopen_s(&in, filename, "r");
	char ch;
	while (in != nullptr && (ch = getc(in)) != EOF) {
		char empty_symbols[] = { ' ', '\n', '\t', '\r', '\b', '\a' };
		bool is_empty = false;
		for (int i = 0; i < sizeof(empty_symbols) / sizeof(char); i++) {
			if (ch == empty_symbols[i]) {
				is_empty = true;
				break;
			}
		}
		is_empty ? empty++ : nonempty++;
	}
}

void find(char* filename, char* output, char* str) {
	FILE* in;
	fopen_s(&in, filename, "r");
	FILE* out;
	fopen_s(&out, output, "w");
	char ch;
	char* p = str;
	int begin = -1;
	int i = 0;
	while (in != nullptr && out != nullptr) {
		if (*p == '\0' && begin != -1) {
			fprintf(out, "%d ", begin);
			p = str;
			begin = -1;
		}
		ch = getc(in);
		if (ch == EOF) {
			break;
		}
		if (*p == ch) {
			if (begin == -1) {
				begin = i;
			}
			p++;
		}
		else if (begin != -1) {
			p = str;
			begin = -1;
		}
		i++;
	}
}
