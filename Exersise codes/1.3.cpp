#include <iostream>
using namespace std;

class point
{
    public:
        int px;
        int * py;  // pointer that points to the y value

        point(int x, int y)
        {
            px = x;
            py =(int *) malloc(sizeof(int)); //allocate memory for [py]
            *py = y;  // set the value pointed by [py]
        };

        point (const point & oldpoint) // deep copy
        {
            px = oldpoint.px;
            py =(int *) malloc(sizeof(int)); //allocate memory for [py]
            *py = *(oldpoint.py);  // set the value pointed by [py]
        }

        print()
            {
               cout << "\nPoint = ( " << px << " , " << *py << " ) "  << endl ;
               cout << "Pointer [py] = " << py << endl;
            }

        ~point()
        {
            free(py); // free the allocated memory for [py]
        }
};

void print_point(point point);

int main()
{
    point point1 (2,3);

    point point2 = point1; // shallow copy

    point1.print();
    point2.print();
    /* here we see that both points have the same y value, but not because the value is copied.
    it's because the address is copied, [py] is the same address for the 2 points */

    *(point1.py) = 20; // set the value pointed to by [py] to 20

    point1.print();
    point2.print();
    /*here we notice that y-axis of the 2 points has changed ---> shallow copy */

    /*another problem that emerges: when deallocating the memory, we free point1 with no problem
    but when we free point2 we get error because the memory was freed when deallocating point1.
    as both have the same address */


    /*if we ran the same code after implementing the deep copy constructor {lines 17 -> 22}
    we see that point2 y-axis didn't change to 20 unlike the previous trial ---> deep copy*/

    return 0;
}
