#include <iostream>
using namespace std;

class BankAccount
{
protected:
    int acc_num;
    int balance;

public :
    BankAccount() { acc_num = 0; balance = 0;}
    BankAccount(int an, int b) { acc_num = an; balance = b;}
    
    void deposit (int money)
    {
    	balance+=money;
	}
	
	bool withdraw (int money)
    {
    	if (balance >= money)
		{
			balance-=money;
			cout << "Withdraw completed, Amount: " << money <<endl;
			
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	void display ()
	{
		cout << "Account Number: " << acc_num <<" || Current Balance: " << balance << " EGP" <<endl;
	}

};

int main()
{
	BankAccount acc1(12345, 5000);
	acc1.display();
	
	acc1.deposit(4000);
	acc1.withdraw(3000);
	acc1.display();
	
	return 0;
}
