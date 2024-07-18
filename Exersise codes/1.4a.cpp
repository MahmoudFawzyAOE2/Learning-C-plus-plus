#include <iostream>
using namespace std;
class truck;
class car
{
    friend int sp_greater(car c, truck t);

    private:
        int speed;

    public:
        car() {speed=0;};
        car(int s) {speed=s;};

        print() { cout << "\nCar Speed = " << speed << endl ; }

};

class truck
{
    friend int sp_greater(car c, truck t);

    private:
        int speed;

    public:
        truck() {speed=0;};
        truck(int s) {speed=s;};

        print() { cout << "\nTruck Speed = " << speed << endl ; }

};

int main()
{
    int t;
    car c1(3);
    truck t1(5);

    c1.print();
    t1.print();

    t = sp_greater(c1,t1);
    if (t< 0) cout << "Truck faster \n";
    else if (t==0) cout<<" Equal speed\n";
    else cout<<" Car faster\n";

    return 0;
}

/*general function*/
int sp_greater(car c, truck t)
{
    return c.speed-t.speed;
}
