#include <iostream>

void main() {
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int imin, imax;
    int n = sizeof(mas) / sizeof(int);
    int  i;
    imin = i = 0;
    imax = i = 0;
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        imin = i;
        for (int j = i + 1; j < n; j++) {
            if (mas[j] < mas[imin]) {
                imin = j;
            }
            int temp = mas[imin];
            mas[imin] = mas[i];
            mas[i] = temp;
        }
    }
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}
