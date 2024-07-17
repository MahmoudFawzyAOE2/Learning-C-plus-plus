#include <iostream>
using namespace std;



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
        complex_num add(complex_num a, complex_num b= complex_num(0,0))
            {
                this->real = a.real + b.real;
                this->imag = a.imag + b.imag;
            };

        /*2 subtract method using the same name with different input attributes (overloading)*/
        complex_num sub(complex_num a) // this = this - a
            {
                this->real -= a.real ;
                this->imag -= a.imag ;
            };
        complex_num sub(complex_num a, complex_num b) // this = a - b
            {
                this->real = a.real - b.real;
                this->imag = a.imag - b.imag;
            };

        complex_num multiply(complex_num a, complex_num b) // this = a * b
            {
                this->real = a.real * b.real - a.imag * b.imag;
                this->imag = a.real * b.imag + b.real * a.imag;
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
    complex_num num1 ;

    num1.print();

    num1.set_real(2);
    num1.set_imag(3);

    num1.print();

    /*add*/
    cout << "\n----------------"  << endl ;
    complex_num num2 (4,5) ;

    complex_num num3 ;
    num3.add(num1);
    num3.print();

    /*sub*/
    cout << "\n----------------"  << endl ;
    num1.set_comp(2,3);
    num2.set_comp(4,5);
    num3.set_comp(6,7);

    cout << "-subtract num1 from num3"  << endl ;
    num3.sub(num1);
    num3.print();

    cout << "\n-set num3 to num2 - num1"  << endl ;
    num3.sub(num2, num1);
    num3.print();

    /*multiply*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 * num1"  << endl ;
    num3.multiply(num2, num1);
    num3.print();

    /*divide*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 / num1"  << endl ;
    num3.divide(num2, num1);
    print_complex(num3);

    return 0;
}

void print_complex(complex_num num)
{
    cout << "\nComplex Number = " << num.get_real() << "+i" << num.get_imag() << endl ;
}
