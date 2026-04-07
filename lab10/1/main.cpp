#include <iostream>

struct Node {
    int d;
    Node* next;
};

Node* first(int d);

void add(Node** pend, int d);

Node* find(Node* pbeg, int d);

int remove(Node** pbeg, Node** pend, int key);

Node* insert(Node* pbeg, Node** pend, int key, int d);

void add_sort(Node** pbeg, Node** pend, int d);

int main() {
    Node* pbeg = first(1);
    Node* pend = pbeg;
    for (int i = 2; i < 6; i++) add(&pend, i);
    insert(pbeg, &pend, 2, 200);
    if (!remove(&pbeg, &pend, 5)) std::cout << "не найден";
    Node* pv = pbeg;
    while (pv) {
        std::cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}

Node* first(int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = 0;
    return pv;
}

void add(Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = 0;
    (*pend)->next = pv;
    *pend = pv;
}

Node* find(Node* const pbeg, int key) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == key) break;
        pv = pv->next;
    }
    return pv;
}

int remove(Node** pbeg, Node** pend, int key) {
    Node* prev = 0;
    Node* target = *pbeg;
    while (target) {
        if (target->d == key) break;
        prev = target;
        target = target->next;
    }

    if (target) {
        if (target == *pend && target == *pbeg) {
            *pbeg = 0;
            *pend = 0;
        } if (target == *pbeg) {
            *pbeg = (*pbeg)->next;
        }
        else {
            if (target == *pend) {
                *pend = prev;
                (*pend)->next = 0;
            }
            else {
                if (prev) {
                    prev->next = target->next;
                }
            }
        }
        delete target;
        return 1;
    }
    return 0;
}

Node* insert(Node* const pbeg, Node** pend, int key, int d) {
    Node* pkey = find(pbeg, key);
    if (pkey) {
        Node* pv = new Node;
        pv->d = d;
        pv->next = pkey->next;
        pkey->next = pv;
        if (pkey == *pend)
            *pend = pv;
        return pv;
    }
    return 0;
}

void add_sort(Node** pbeg, Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = 0;

    if (*pbeg == 0) {
        *pbeg = pv;
        *pend = pv;
        return;
    }

    Node* prev = 0;
    Node* pt = *pbeg;
    while (pt) {
        if (d < pt->d) {
            pv->next = pt;
            if (prev == 0) {
                *pbeg = pv;
            }
            else {
                prev->next = pv;
            }
            return;
        }
        prev = pt;
        pt = pt->next;
    }
    (*pend)->next = pv;
    *pend = pv;
}
