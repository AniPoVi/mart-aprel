#include <iostream>

struct Node {
    int d;
    Node* next;
    Node* prev;
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
    pv->prev = 0;
    return pv;
}

void add(Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}

Node* find(Node* const pbeg, int d) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == d) break;
        pv = pv->next;
    }
    return pv;
}

int remove(Node** pbeg, Node** pend, int key) {
    Node* pkey = find(*pbeg, key);
    if (pkey) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = 0;
        }
        else {
            if (pkey == *pend) {
                *pend = (*pend)->prev;
                (*pend)->next = 0;
            }
            else {
                (pkey->prev)->next = pkey->next;
                (pkey->next)->prev = pkey->prev;
            }
        }
        delete pkey;
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
        pv->prev = pkey;
        pkey->next = pv;
        if (pkey != *pend)
            (pv->next)->prev = pv;
        else
            *pend = pv;
        return pv;
    }
    return 0;
}

void add_sort(Node** pbeg, Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    Node* pt = *pbeg;
    while (pt) {
        if (d < pt->d) {
            pv->next = pt;
            if (pt == *pbeg) {
                pv->prev = 0;
                *pbeg = pv;
            }
            else {
                (pt->prev)->next = pv;
                pv->prev = pt->prev;
            }
            pt->prev = pv;
            return;
        }
        pt = pt->next;
    }
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}
