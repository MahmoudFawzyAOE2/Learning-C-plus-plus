#include <iostream>
using namespace std;

class shape
{
protected:
    int width;
    int height;

public :
    shape(int w, int h) { width = w; height = h; }
};

class rectangle : public shape
{
public:
    using shape::shape;
    int area ()
    {
        return width * height;
    }
};

class triangle : public shape
{
public:
    using shape::shape;
    int area ()
    {
        return 0.5 * width * height;
    }
};

int main()
{
    rectangle abcd (5,4);

    int rect_area = abcd.area();

    cout << "rect area: " << rect_area << endl;

    triangle xyz (5,4);

    int tri_area = xyz.area();

    cout << "tri area: " << tri_area << endl;

    return 0;
}
