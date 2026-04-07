#include <iostream>

void bubble(int mas[], int l, int r) {
    for (int i = l; i < r - 1; i++) {
        for (int j = l; j < r + l - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

void reverseBubble(int mas[], int l, int r) {
    for (int i = l; i < r - 1; i++) {
        for (int j = l; j < r + l - i - 1; j++) {
            if (mas[j] < mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

int oddEvenModifier(int x) {
    return x % 2 == 0 ? x : -x;
}

void oddEvenBubble(int mas[], int l, int r) {
    for (int i = l; i < r - 1; i++) {
        for (int j = l; j < r + l - i - 1; j++) {
            if (oddEvenModifier(mas[j]) > oddEvenModifier(mas[j + 1])) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

void main() {
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int);
    int  i;
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Bubble sort " << std::endl;
    bubble(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse bubble sort " << std::endl;
    reverseBubble(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd even bubble sort " << std::endl;
    oddEvenBubble(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "bubble sort from 0 to 12" << std::endl;
    bubble(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "reverse bubble sort from 2 to 10 " << std::endl;
    reverseBubble(mas, 2, 10);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "bubble sort from 4 to 8 " << std::endl;
    bubble(mas, 4, 8);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}
