#include <iostream>
using namespace std;



class point
{
    private:
        int px;
        int py;

    public:
        point() {px=0; py=0;};
        point(int r, int i) {px=r; py=i;};

        void set_px(int px_input)
            {
                px = px_input;
            };
        void set_py(int py_input)
            {
                py = py_input;
            };
        void set_point(int px_input, int py_input)
            {
                px = px_input;
                py = py_input;
            };
        int get_px()
            {
                return(px);
            };
        int get_py()
            {
                return(py);
            };
        print()
            {
               cout << "\nPoint = ( " << px << " , " << py << " )" << endl ;
            }
        point add(point a, point b= point(0,0))
            {
                this->px = a.px + b.px;
                this->py = a.py + b.py;
            };

        /*2 subtract method using the same name with different input attributes (overloading)*/
        point sub(point a) // this = this - a
            {
                this->px -= a.px ;
                this->py -= a.py ;
            };
        point sub(point a, point b) // this = a - b
            {
                this->px = a.px - b.px;
                this->py = a.py - b.py;
            };
};

void print_point(point point);

int main()
{
    /*set , get & print methods*/
    point point1 ;

    point1.print();

    point1.set_px(2);
    point1.set_py(3);

    point1.print();

    /*add*/
    cout << "\n----------------"  << endl ;
    point point2 (4,5) ;

    point point3 ;
    point3.add(point1);
    point3.print();

    /*sub*/
    cout << "\n----------------"  << endl ;
    point1.set_point(2,3);
    point2.set_point(4,5);
    point3.set_point(6,7);

    cout << "-subtract point1 from point3"  << endl ;
    point3.sub(point1);
    point3.print();

    cout << "\n-set point3 to point2 - point1"  << endl ;
    point3.sub(point2, point1);
    print_point(point3);

    return 0;
}

void print_point(point point)
{
    cout << "\nPoint = ( " << point.get_px() << " , " << point.get_py() << " )" << endl ;

}
