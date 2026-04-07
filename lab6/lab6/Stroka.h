#include <cstdlib>

class Stroka {
    char* str;

public:
    Stroka(const char*);

    explicit Stroka(int);

    ~Stroka();

    Stroka();

    Stroka(const Stroka&);

    Stroka& operator=(const Stroka&);

    Stroka& operator+(const Stroka&);

    int operator==(const Stroka&) const;

    int dlina();

    void vvod();

    void vyvod();
};
