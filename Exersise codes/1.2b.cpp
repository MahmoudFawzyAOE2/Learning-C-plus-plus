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
};

void print_point(point point);
point add(point a, point b); // temp = a + b
point sub(point a, point b); // temp = a - b

int main()
{
    /*set , get & print methods*/
    point point1 ;

    print_point(point1);

    point1.set_px(2);
    point1.set_py(3);

    print_point(point1);


    point point2 (4,5) ;

    point point3 ;

    point1.set_point(2,3);
    point2.set_point(4,5);

    /*add*/
    cout << "\n----------------"  << endl ;
    cout << "\n-set point3 to point2 + point1"  << endl ;
    point3=add(point2, point1);
    print_point(point3);

    /*sub*/
    cout << "\n----------------"  << endl ;
    cout << "\n-set point3 to point2 - point1"  << endl ;
    point3=sub(point2, point1);
    print_point(point3);

    return 0;
}

void print_point(point point)
{
    cout << "\nPoint = ( " << point.get_px() << " , " << point.get_py() << " )" << endl ;

}

point add(point a, point b) // temp = a + b
{
    point temp ;
    temp.set_px(a.get_px() + b.get_px()) ;
    temp.set_py(a.get_py() + b.get_py());
    return temp;
};

point sub(point a, point b) // temp = a - b
{
    point temp ;
    temp.set_px(a.get_px() - b.get_px() );
    temp.set_py(a.get_py() - b.get_py() );
    return temp;
};
