#define PR(x) printf("x=%u, *x=%.2f, &x=%u\n", x, *x, &x)
#include <stdio.h>

void main() {
    double mas[] = { 1.1, 2.2, 3.1 };
    double* ptr1, * ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
    return 0;
}