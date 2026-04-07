#include <cstdlib>
#include <iostream>

class Stroka {
    char* str;

public:
    Stroka(char*);

    Stroka(int);

    ~Stroka() {
        std::free(str);
    }

    Stroka() {
        str = (char*)calloc(80, sizeof(char));
    }

    Stroka(const Stroka&);

    Stroka& operator=(const Stroka&);

    Stroka& operator+(const Stroka&);

    int operator==(const Stroka&);

    friend std::istream& operator>>(std::istream&, Stroka&);

    friend std::ostream& operator<<(std::ostream&, const Stroka&);

    int dlina();

    void vvod();

    void vyvod();
};
