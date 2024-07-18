#include <iostream>
using namespace std;

/*member functions*/

class complex_num
{
    private:
        int real;
        int imag;

    public:
        complex_num() {real=0; imag=0;};
        complex_num(int r, int i) {real=r; imag=i;};

        void set_real(int real_input)
            {
                real = real_input;
            };
        void set_imag(int imag_input)
            {
                imag = imag_input;
            };
        void set_comp(int real_input, int imag_input)
            {
                real = real_input;
                imag = imag_input;
            };
        int get_real()
            {
                return(real);
            };
        int get_imag()
            {
                return(imag);
            };
        print()
            {
               cout << "\nComplex Number = " << real << "+i" << imag << endl ;
            }

        complex_num operator+(complex_num p)
            {
                complex_num temp;
                temp.real=real+p.real;
                temp.imag=imag+p.imag;
                return temp;
            };
        complex_num operator-(complex_num p)
            {
                complex_num temp;
                temp.real=real-p.real;
                temp.imag=imag-p.imag;
                return temp;
            };
        complex_num operator*(complex_num b)
            {
                complex_num temp;
                temp.real=real * b.real - imag * b.imag;
                temp.imag=real * b.imag + b.real * imag;
                return temp;
            };
        complex_num operator/(complex_num b)
            {
                complex_num temp;
                int div = (b.real * b.real + b.imag * b.imag);
                temp.real=(real * b.real + imag * b.imag) / div;
                temp.imag=(b.real * imag - real * b.imag) / div;
                return temp;
            };

        complex_num divide(complex_num a, complex_num b) // this = a * b
            {
                int div = (b.real * b.real + b.imag * b.imag);
                this->real = (a.real * b.real + a.imag * b.imag) / div;
                this->imag = (b.real * a.imag - a.real * b.imag) / div;
            };
};

void print_complex(complex_num num);

int main()
{
    /*set , get & print methods*/
    complex_num num1 (2,3);
    complex_num num2 (4,5);
    complex_num num3 ;

    /*add*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 + num1"  << endl ;
    num3 = num2 + num1;
    num3.print();

    /*sub*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 - num1"  << endl ;
    num3 = num2 - num1;
    num3.print();

    /*multiply*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 * num1"  << endl ;
    num3 = num2 * num1;
    num3.print();

    /*divide*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 / num1"  << endl ;
    num3 = num2 / num1;
    num3.print();

    return 0;
}

