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
};

void print_complex(complex_num num);
complex_num add(complex_num a, complex_num b); // temp = a + b
complex_num sub(complex_num a, complex_num b); // temp = a - b
complex_num multiply(complex_num a, complex_num b); // temp = a * b
complex_num divide(complex_num a, complex_num b); // temp = a * b

int main()
{
    /*set , get & print methods*/
    complex_num num1 ;

    print_complex(num1);

    num1.set_real(2);
    num1.set_imag(3);

    print_complex(num1);


    complex_num num2 (4,5) ;

    complex_num num3 ;

    num1.set_comp(2,3);
    num2.set_comp(4,5);

    /*add*/
    cout << "\n----------------"  << endl ;
    cout << "\n-set num3 to num2 + num1"  << endl ;
    num3=add(num2, num1);
    print_complex(num3);

    /*sub*/
    cout << "\n----------------"  << endl ;
    cout << "\n-set num3 to num2 - num1"  << endl ;
    num3=sub(num2, num1);
    print_complex(num3);

    /*multiply*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 * num1"  << endl ;
    num3=multiply(num2, num1);
    print_complex(num3);

    /*divide*/
    cout << "\n----------------"  << endl ;
    cout << "-set num3 to num2 / num1"  << endl ;
    num3=divide(num2, num1);
    print_complex(num3);

    return 0;
}

void print_complex(complex_num num)
{
    cout << "\nComplex Number = " << num.get_real() << "+i" << num.get_imag() << endl ;
}

complex_num add(complex_num a, complex_num b) // temp = a + b
{
    complex_num temp ;
    temp.set_real(a.get_real() + b.get_real()) ;
    temp.set_imag(a.get_imag() + b.get_imag());
    return temp;
};

complex_num sub(complex_num a, complex_num b) // temp = a - b
{
    complex_num temp ;
    temp.set_real(a.get_real() - b.get_real() );
    temp.set_imag(a.get_imag() - b.get_imag() );
    return temp;
};

complex_num multiply(complex_num a, complex_num b) // temp = a * b
{
    complex_num temp ;
    temp.set_real(a.get_real() * b.get_real() - a.get_imag() * b.get_imag())  ;
    temp.set_imag(a.get_real() * b.get_imag() + b.get_real() * a.get_imag())  ;
    return temp;
};

complex_num divide(complex_num a, complex_num b) // temp = a * b
{
    complex_num temp ;
    int div = (b.get_real() * b.get_real() + b.get_imag() * b.get_imag());
    temp.set_real((a.get_real() * b.get_real() + a.get_imag() * b.get_imag()) / div)  ;
    temp.set_imag((b.get_real() * a.get_imag() - a.get_real() * b.get_imag()) / div)  ;
    return temp;
};
