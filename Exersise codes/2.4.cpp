#include <iostream>
using namespace std;

class mother
{
protected:
    string name;
    int age;

public :
    mother(string n, int w) { name=n; age = w;}

    void display()
    {
        cout << name << " is a mother and she is " << age << " years old" << endl;
    }
};

class daughter : public mother // inheriting from parent class
{
public:
    using mother::mother; // inheriting constructor

    void display()
    {
        cout << name << " is a daughter and she is " << age << " years old" << endl;
    }
};

int main()
{
    daughter mona ("mona", 15);

    mona.display();
}
