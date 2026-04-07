#include <iostream>

void main() {
	char name[50];
	printf("Введите имя файла для просмотра: ");
	scanf_s("%s", name, 50);
	FILE* in;
	fopen_s(&in, name, "r");
	FILE* out;
	fopen_s(&out, "output.txt", "w");

	void writeBuffer(FILE * outfile, char* buffer, int& size);

	char buffer[100];
	int bufferSize = 0;
	bool readPageNumber = true;
	bool readPageDelimiter = false;

	if (!in) {
		printf("Файл %s не открыт", name);
		return;
	}

	char ch;
	while (true) {
		ch = getc(in);

		// если конец файла - пишем номер страницы
		if (ch == EOF) {
			writeBuffer(out, buffer, bufferSize);
			break;
		}

		// если строка с номером страницы - читаем номер в буфер. если конец строки - то считаем что номер прочитан
		if (readPageNumber == true) {
			if (ch != '\n') {
				// игнорируем знаки переноса?
				if (ch != '-') buffer[bufferSize++] = ch;
			}
			else {
				fputc(ch, out);
				readPageNumber = false;
			}
			continue;
		}

		// потенциально разделитель страницы
		if (ch == '\\') {
			readPageDelimiter = true;
			continue;
		}

		// если встретился символ новой страницы, то записываем перед ним номер страницы
		if (ch == 'f' && readPageDelimiter == true) {
			writeBuffer(out, buffer, bufferSize);
			fputs("\\f", out);
			readPageDelimiter = false;
			readPageNumber = true;
			continue;
		}
		// иначе убираем флаг, записываем пропущенный символ в файл
		if (readPageDelimiter == true) {
			readPageDelimiter = false;
			fputc('\\', out);
		}
		fputc(ch, out);
	}

	fclose(in);
	fclose(out);
	fopen_s(&in, "output.txt", "r");
	fopen_s(&out, name, "w");
	while ((ch = getc(in)) != EOF) {
		putc(ch, out);
	}
	fclose(in);
	fclose(out);
	remove("output.txt");
}

void clearbuf(char* buffer, int& size) {
	buffer[0] = '\0';
	size = 0;
}

void writeBuffer(FILE* out, char* buffer, int& size) {
	fputs(buffer, out);
	clearbuf(buffer, size);
}
