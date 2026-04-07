#include <iostream>

template<class T>
class LinkedList {
    struct Node {
        T d;
        Node* next;
    };

protected:
    Node* pbeg;
    Node* pend;

public:
    LinkedList(T data) {
        Node* pv = new Node;
        pv->d = data;
        pv->next = nullptr;
        pbeg = pv;
        pend = pv;
    }

    ~LinkedList() {
        while (pbeg) {
            Node* temp = pbeg;
            pbeg = pbeg->next;
            delete temp;
        }
        pend = nullptr;
    }

    void add(T data) {
        Node* pv = new Node;
        pv->d = data;
        pv->next = nullptr;
        pend->next = pv;
        pend = pv;
    };

    Node* find(T data) {
        Node* pv = pbeg;
        while (pv) {
            if (pv->d == data) break;
            pv = pv->next;
        }
        return pv;
    }

    int remove(T data) {
        Node* prev = nullptr;
        Node* target = pbeg;
        while (target) {
            if (target->d == data) break;
            prev = target;
            target = target->next;
        }

        if (target) {
            if (target == pend && target == pbeg) {
                pbeg = nullptr;
                pend = nullptr;
            }
            else {
                if (target == pbeg) {
                    pbeg = pbeg->next;
                }
                else {
                    if (target == pend) {
                        pend = prev;
                        pend->next = nullptr;
                    }
                }
            }
            delete target;
            return 1;
        }
        return 0;
    }

    Node* insert(int pos, T data) {
        Node* pv = new Node;
        pv->d = data;
        pv->next = nullptr;
        if (!pos || !pbeg) {
            pv->next = pbeg;
            pbeg = pv;
        }
        else {
            Node* prev = pbeg;
            for (int i = 0; i < pos - 1 && prev->next; i++) {
                prev = prev->next;
            }
            pv->next = prev->next;
            prev->next = pv;
        }
        return pv;
    }

    void add_sort(T data) {
        Node* pv = new Node;
        pv->d = data;
        pv->next = nullptr;
        if (pbeg == nullptr) {
            pbeg = pv;
            pend = pv;
            return;
        }
        Node* prev = nullptr;
        Node* pt = pbeg;
        while (pt) {
            if (pt->d > data) {
                pv->next = pt;
                if (prev == nullptr) {
                    pbeg = pv;
                }
                else {
                    prev->next = pv;
                }
                return;
            }
            prev = pt;
            pt = pt->next;
        }
        pv->next = nullptr;
        pend->next = pv;
        pend = pv;
    }

    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
        Node* pv = list.pbeg;
        while (pv) {
            out << pv->d << ' ';
            pv = pv->next;
        }
        return out;
    }
};
