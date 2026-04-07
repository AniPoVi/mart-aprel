#include "LinkedList.h"

int main() {
    LinkedList<int> list(1);
    for (int i = 2; i < 6; i++) list.add(i);

    list.insert(2, 200);
    if (!list.remove(5)) std::cout << "не найден";
    
    std::cout << list;
    return 0;
}