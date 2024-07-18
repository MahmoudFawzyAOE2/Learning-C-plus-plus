#include <iostream>
using namespace std;


class Stack
{
    static const int MAX = 10;

    private:
        int data[MAX];
        int top;

    public:
        Stack() {top=-1;};


        void trace()
            {
                for (int i = 0; i <= top; i++)
                {
                    cout << data[i] << "\t";
                }
                cout << endl;
            };

        void push(int value)
            {
                if (top == MAX-1)
                        cout <<  "\nStack Overflow\n";
                else
                {
                    top++;
                    data[top] = value;

                }
            };

        int pop()
            {
                if (top == -1)
                    cout <<  "\nStack Underflow\n";
                else
                {
                    return data[top--];
                }
            };

        int peek()
            {
                if (top == -1)
                    cout <<  "\nStack is empty\n";
                else
                {
                    return data[top];
                }
            };
        bool isempty()
            {
                 return(top == -1);
            };
        bool isfull()
            {
                return(top == MAX-1);
            };
};


int main()
{
    Stack s;

    s.trace();

    s.push(5);
    s.push(8);
    s.push(4);

    s.trace();

    int x = s.pop();
    cout << "popped value: " << x << endl;

    cout << "current top value: " << s.peek() << endl;

    return 0;
}

