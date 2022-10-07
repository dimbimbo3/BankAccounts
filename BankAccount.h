#include <iostream>
#include <iomanip>
using namespace std;
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

//BankAccount START - Base class for SavingsAccount & CheckingAccount
class BankAccount{
private:
	double monthlyRate;//Used for the monthly interest rate
	double monthlyInterest;//Used for the total monthly interest to be added to the balance

	//calcInt START - Member function for calculating the monthly interest rate(based on the annual rate) and the monthly interest to be added to the balance(no interest if balance is less than or equal to 0)
	void calcInt(){
		if(balance > 0){
			monthlyRate = (annualRate / 12);
			monthlyInterest = balance * monthlyRate;
			balance += monthlyInterest;
		}
	}//calcInt END

	//getMonthlyCharges START - Member function for returning the monthly charge amount
	double getMonthlyCharges(){
		return monthlyCharges;
	}//getMonthlyCharges END
protected:
	double startBalance;//Used to store the starting balance amount
	double balance;//Used to store the current balance
	double annualRate;//Used to store the annual interest rate
	int depositNum;//Used to store the number of deposits made
	int withdrawlNum;//Used to store the number of withdrawls made
	double monthlyCharges;//Used to store the total of monthly charges
public:
	//C-tor START
	BankAccount(){
		startBalance = 0.0;
		balance = 0.0;
		annualRate = 0.0;
		depositNum = 0;
		withdrawlNum = 0;
		monthlyCharges = 0.0;
		monthlyRate = 0.0;
		monthlyInterest = 0.0;
		cout << setprecision(2) << fixed;
	}//C-tor END

	//Destructor START
	~BankAccount(){
	}//Destructor END

	//setBalance START - Member function for setting the starting and current balances
	void setBalance(double bal){
		startBalance = bal;
		balance = bal;
	}//setBalance END

	//setAnnualRate START - Member function for setting the annual interest rate
	void setAnnualRate(double aRate){
		annualRate = aRate;
	}//setAnnualRate END

	//deposit START - Virtual member function for adding the deposit to the current balance and incrementing the deposit number
	virtual void deposit(double d){
		balance += d;
		depositNum++;
	}//deposit

	//withdraw START - Virtual member function for subtracting the withdrawl from the current balance and incrementing the withdrawl number
	virtual void withdraw(double w){
		balance -= w;
		withdrawlNum++;
	}//withdraw END

	//getStartBalance START - Member function for returning the starting balance
	double getStartBalance(){
		return startBalance;
	}//getStartBalance END

	//getDepositNum START - Member function for returning the deposit number
	double getDepositNum(){
		return depositNum;
	}//getDepositNum END

	//getWithdrawlNum START - Member function for returning the withdrawl number
	double getWithdrawlNum(){
		return withdrawlNum;
	}//getWithdrawlNum END

	//monthlyProc START - Virtual member function for calling getMonthlyCharges, subtracting the monthly charge amount from the current balance and calling calcInt
	virtual void monthlyProc(){
		cout << "Monthly Service Charges:$" << getMonthlyCharges() << endl;
		balance -= monthlyCharges;
		calcInt();
		withdrawlNum = 0;
		depositNum = 0;
		monthlyCharges = 0;
	}//monthlyProc END

	//getBalance START - Member function for returning the current balance
	double getBalance(){
		return balance;
	}//getBalance END
};//BankAccount END

#endif