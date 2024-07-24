#include <iostream>
using namespace std;

class animal
{
protected:
    string name;
    int age;

public :
    animal() { name=""; age = 0;}

    void set_value(string n, int w)
    {
        name=n; 
		age = w;
    }
};

class zebra : public animal // inheriting from parent class
{
private:
	string origin ;
public:
    using animal::animal; // inheriting constructor
    zebra() { origin="somewhere";}
    
    void set_value(string n, int w, string o)
    {
    	animal::set_value(n,w); // here we call the overridden function from animal base class 
        origin=o; 
    }

    void display()
    {
        cout << name << " is a zebra. it is " << age << " years old and from " << origin << endl;
    }
};

class dolphin : public animal // inheriting from parent class
{
private:
	string origin ;
public:
    using animal::animal; // inheriting constructor
    dolphin() { origin="somewhere";}
    
    void set_value(string n, int w, string o)
    {
    	animal::set_value(n,w); // here we call the overridden function from animal base class 
        origin=o; 
    }

    void display()
    {
        cout << name << " is a dolphin. it is " << age << " years old and from " << origin << endl;
    }
};

int main()
{
    zebra z1;
    z1.set_value("gabi", 10, "kenya");
    z1.display();
    
    dolphin d1;
    d1.set_value("splash", 10, "cyprus");
    d1.display();
}
