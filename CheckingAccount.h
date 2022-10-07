#include "BankAccount.h"
#include <iostream>
using namespace std;
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

//CheckingAccount START - Derived class from BankAccount
class CheckingAccount:public BankAccount{
private:
	static const int SERVICE_CHARGE = 15;//Constant used for service charge(if withdrawl makes balance go under $0)
public:
	//C-tor START
	CheckingAccount():BankAccount(){
	}//C-tor END

	//Destructor START
	~CheckingAccount(){
	}//Destructor END

	//withdraw START - Overridden withdraw member function, checks if balance is less than $0 or if withdrawl will make it go below $0
	void withdraw(double w){
		if(balance < 0)
			cout << "*The withdrawl has not been made, the account currently owes a negative amount of $" << getBalance() << "*" << endl;
		else
			if((balance - w) < 0){
				cout << "*A withdrawl of $" << w << " would cause the current balance($" << getBalance() << ") to go below $0*" << endl;
				cout << "*Due to this, the withdrawl has not been made, and a $15 service charge has been taken from the account*" << endl;
				if((balance - SERVICE_CHARGE) < 0){
					balance -= SERVICE_CHARGE;
					cout << "*The balance has now become negative($" << getBalance() << ") and the negative amount is owed*" << endl;
				}
				else
					balance -= SERVICE_CHARGE;
				}
			else
				BankAccount::withdraw(w);
	}//withdraw END

	//monthlyProc START - Overridden monthly procedure that adds a monthly service charge of $5 plus $0.10 per withdrawl
	void monthlyProc(){
		monthlyCharges = 5 + (.10 * withdrawlNum);

		BankAccount::monthlyProc();
	}//monthlyProc END
};//CheckingAccount END

#endif