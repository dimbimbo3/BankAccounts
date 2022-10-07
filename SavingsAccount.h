#include "BankAccount.h"
#include <iostream>
using namespace std;
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

//SavingsAccount START - Derived class from BankAccount
class SavingsAccount:public BankAccount{
private:
	bool status;//Flag for whether the account is currently active(above $25) or not
public:
	//C-tor START
	SavingsAccount():BankAccount(){
		status = true;
	}//C-tor END

	//Destructor
	~SavingsAccount() {
	}//Destructor END

	//withdraw START - Overridden withdraw member function, checks if balance is less than $25 and sets the account to inactive if true, which prevents further withdrawls
	void withdraw(double w){
		if (balance < 25)
			status = false;

		if(!status){
			cout << "\n*Account is currently inactive(Less than $25 in account)," 
			<< "no futher withdrawls can be made until it is reactivated. Current Balance($" << getBalance() << ")*" << endl;
		}
		else
			BankAccount::withdraw(w);
	}//withdraw END

	//deposit START - Overridden deposit member function, checks if the account is inactive and if the deposit will raise the balance back over $25, which will reactive it
	void deposit(double d){
		if(!status && (balance + d) >= 25)
			status = true;

		BankAccount::deposit(d);
	}//deposit END

	//monthlyProc START - Overridden monthly procedure that adds a monthly service charge of $1 for each withdrawl above 4 and checks if the account becomes inactive after the charge
	void monthlyProc(){
		if(withdrawlNum > 4)
			monthlyCharges += (withdrawlNum - 4);

		BankAccount::monthlyProc();

		if(balance < 25){
			status = false;
			cout << "*Account is currently inactive(Less than $25 in account)," 
			<< "no futher withdrawls can be made until it is reactivated*" << endl;
		}
	}//monthlyProc END
};//SavingsAccount END

#endif