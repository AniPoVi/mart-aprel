#include <cstring>
#include <ostream>

#include "LinkedList.h"

struct Bus {
private:
    int number;
    char name[100]{};
    int route;
public:

    Bus(int number, const char* name, int route) {
        this->number = number;
        this->route = route;
        this->name[0] = '\0';
        strcpy_s(this->name, name);
    }

    friend bool operator==(const Bus& lhs, const Bus& rhs) {
        return lhs.number == rhs.number;
    }

    friend bool operator!=(const Bus& lhs, const Bus& rhs) {
        return !(lhs.number == rhs.number);
    }

    friend std::ostream& operator<<(std::ostream& out, const Bus& bus) {
        out << "[" << bus.number << ' ' << bus.name << ' ' << bus.route << "]";
        return out;
    }
};

class Park {
    LinkedList<Bus> onpark;
    LinkedList<Bus> onroute;
    Bus bus_ = Bus(0, "", 0);

public:
    Park() = default;

    ~Park() = default;

    void enterPark(int number) {
        Bus* bus = onroute.find(Bus(number, "", 0));
        if (bus != nullptr) {
            onroute.remove(*bus);
            onpark.add(*bus);
        }
    }

    void leavePark(int number) {
        Bus* bus = onpark.find(Bus(number, "", 0));
        if (bus != nullptr) {
            onpark.remove(*bus);
            onroute.add(*bus);
        }
    }

    void add(Bus const& bus) {
        onpark.add(bus);
    }

    void printPark() {
        std::cout << "В парке :" << onpark << std::endl;
    }

    void printRoute() {
        std::cout << "На маршруте :" << onroute << std::endl;
    }
};

int main() {
    Park park;

    park.add(Bus(1, "Филонов Г.В.", 10));
    park.add(Bus(2, "Миронов И.И.", 2));
    park.add(Bus(3, "Витальева Г.Г.", 4));
    park.add(Bus(4, "Артемов Д.А.", 25));
    park.add(Bus(5, "Крисп А.А.", 33));
    park.add(Bus(6, "Смирнова Е.И.", 11));
    park.add(Bus(7, "Кочетков А.Г.", 122));

    park.printPark();

    std::cout << "=======================" << std::endl;
    park.leavePark(1);
    park.leavePark(2);
    park.leavePark(7);

    park.printPark();
    park.printRoute();

    std::cout << "=======================" << std::endl;
    park.enterPark(1);
    park.enterPark(2);

    park.printPark();
    park.printRoute();

    std::cout << "=======================" << std::endl;
    park.leavePark(3);
    park.leavePark(4);

    park.printPark();
    park.printRoute();
}
