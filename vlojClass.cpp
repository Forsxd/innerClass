#include <iostream>

using namespace std;

class Car {
private:
    string name;
    int bhp;
    int trq;
    string engType;
    int cil;
    static int carNumber;
    class tng {
    private:
        int bhp;
        int trq;
    public:
        tng(int bhp, int trq) {
            this->bhp = bhp;
            this->trq = trq;
        }
        void stage(Car& car) {
            car.bhp += bhp;
            car.trq += trq;
        }
    };
public:
    Car(string name, int bhp, int trq, string engType, int cil) {
        this->name = name;
        this->bhp = bhp;
        this->trq = trq;
        this->engType = engType;
        this->cil = cil;
        carNumber++;
    }
    static void getCarNubmer() {
        cout << Car::carNumber << endl;
    }
    static void stage1(Car& car,int bhp, int trq) {
        tng(bhp, trq).stage(car);
    }
    void getCarInfo() {
        cout << name << endl << "BHP: " << bhp << " TRQ: " << trq << endl << endl;
    }
};

int Car::carNumber = 0;

int main()
{
    Car BMW_M5("BMW M5 Cometition", 625, 750, "V", 8);
    Car P911("Porsche 911(992) Turbo S", 650, 800, "F", 6);
    BMW_M5.getCarInfo();
    P911.getCarInfo();
    Car::stage1(BMW_M5, 75, 150);
    Car::stage1(P911, 75, 150);
    BMW_M5.getCarInfo();
    P911.getCarInfo();
    Car::stage1(BMW_M5, 75, 150);
    Car::stage1(P911, 75, 150);
    BMW_M5.getCarInfo();
    P911.getCarInfo();
}
