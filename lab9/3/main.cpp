#include <iostream>

template<class T>
class TStack {
protected:
    int numItem;
    T* item;

public:
    TStack(std::size_t size = 10) {
        numItem = 0;
        item = new T[size];
    }

    ~TStack() {
        delete[] item;
    }

    void push(T t) {
        item[numItem++] = t;
    }

    T pop() {
        return item[--numItem];
    }

    T top() {
        return item[numItem - 1];
    }

    bool isEmpty() {
        return numItem == 0;
    }
};


int main() {
    TStack<int> stack;
    int in[] = { 1, 5, 3 };
    int out[sizeof(in) / sizeof(in[0])];

    int j = 0;

    for (int current : in) {
        while (!stack.isEmpty() && stack.top() > current) {
            out[j++] = stack.pop();
        }
        stack.push(current);
    }

    while (!stack.isEmpty()) {
        out[j++] = stack.pop();
    }

    for (int i : out) {
        std::cout << i << " ";
    }

    return 0;
}
