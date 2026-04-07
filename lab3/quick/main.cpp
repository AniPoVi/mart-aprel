#include <iostream>

int partitioning(int mas[], int l, int r) {
    int pivot = mas[l];
    int i = l;
    int j = r - 1;
    while (i <= j) {
        while (mas[i] < pivot) i++;
        while (mas[j] > pivot) j--;
        if (i >= j) break;
        int temp = mas[i];
        mas[i] = mas[j];
        mas[j] = temp;
    }
    return j;
}

void quickSort(int mas[], int l, int r) {
    if (l >= r) return;
    int m = partitioning(mas, l, r);
    quickSort(mas, l, m);
    quickSort(mas, m + 1, r);
}

int reversePartitioning(int mas[], int l, int r) {
    int pivot = mas[l];
    int i = l;
    int j = r - 1;
    while (i <= j) {
        while (mas[i] > pivot) i++;
        while (mas[j] < pivot) j--;
        if (i >= j) break;
        int temp = mas[i];
        mas[i] = mas[j];
        mas[j] = temp;
    }
    return j;
}

void reverseQuickSort(int mas[], int l, int r) {
    if (l >= r) return;
    int m = reversePartitioning(mas, l, r);
    reverseQuickSort(mas, l, m);
    reverseQuickSort(mas, m + 1, r);
}

int oddEvenModifier(int x) {
    return x % 2 == 0 ? x : -x;
}

int oddEvenPartitioning(int mas[], int l, int r) {
    int pivot = mas[l];
    int i = l;
    int j = r - 1;
    while (i <= j) {
        while (oddEvenModifier(mas[i]) < oddEvenModifier(pivot)) i++;
        while (oddEvenModifier(mas[j]) > oddEvenModifier(pivot)) j--;
        if (i >= j) break;
        int temp = mas[i];
        mas[i] = mas[j];
        mas[j] = temp;
    }
    return j;
}

void oddEvenQuickSort(int mas[], int l, int r) {
    if (l >= r) return;
    int m = oddEvenPartitioning(mas, l, r);
    oddEvenQuickSort(mas, l, m);
    oddEvenQuickSort(mas, m + 1, r);
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
    quickSort(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse bubble sort " << std::endl;
    reverseQuickSort(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd even bubble sort " << std::endl;
    oddEvenQuickSort(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "bubble sort from 0 to 12" << std::endl;
    quickSort(mas, 0, n);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "reverse bubble sort from 2 to 10 " << std::endl;
    reverseQuickSort(mas, 2, 10);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "bubble sort from 4 to 8 " << std::endl;
    quickSort(mas, 4, 8);
    for (i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}
