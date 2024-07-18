#include <iostream>
using namespace std;
class car ;

class truck
{
    friend class car;

    private:
        int speed;

    public:
        truck() {speed=0;};
        truck(int s) {speed=s;};

        print() { cout << "\nTruck Speed = " << speed << endl ; }

};
class car
{
    private:
        int speed;

    public:
        car() {speed=0;};
        car(int s) {speed=s;};

       int sp_greater(truck t)
        {
            return speed-t.speed;
        }

        print() { cout << "\nCar Speed = " << speed << endl ; }
};

int main()
{
    int t;
    car car1 (3);
    car1.print();

    truck truck1 (5) ;
    truck1.print();

    t = car1.sp_greater(truck1);
    if (t< 0) cout << "Truck faster \n";
    else if (t==0) cout<<" Equal speed\n";
    else cout<<" Car faster\n";


    return 0;
}
