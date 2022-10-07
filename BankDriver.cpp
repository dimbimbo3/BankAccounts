#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void restartProgram(bool&);
void numOfAccounts(int&);
void annualRate(double&);

//Person START - Structure used to represent individual bank account holders
struct Person{
	string name;//Used for storing the account holder's name
	SavingsAccount savings;//SavingsAccount object within structure
	CheckingAccount checking;//CheckingAccount object within structure
};//Person END

//main START - main program
int main(){
	Person *holder = nullptr;//Pointer used for dynamically allocated structure array
	int count = 0;//Counter for number of bank accounts to be made
	int input = 0;//Used for user input in Account Control menus
	double amount = 0.0;//Used for the amount of each withdrawl and deposit
	double aRate = 0.0;//Used for Annual Interest Rate of all accounts
	double bal = 0.0;//Used for the Balance of each Account
	bool restart = true;//Flag for restarting the program or ending it

	while(restart){//while START - Loops entire program based on bool variable restart

		numOfAccounts(count);//function for setting number of bank accounts, count is passed by reference

		annualRate(aRate);//function for setting the annual interest rate, aRate is passed by reference

		holder = new Person [count];//Creates a dynamically allocated array of Person structures, which represent individual bank account holders (uses count to determine the amount) 

		for(int i = 0; i < count; i++){//for START - Loops through each Person of the dynamic array, asking for names and setting up their Savings & Checking Accounts
			cin.ignore();
			cout << "Please enter the name of account holder[#" << i+1 << "]:";
			getline(cin, holder[i].name);//Takes the user input and uses it for the Structure Member name

			//Savings

			do{//do while START - bal becomes the number typed in by the user, which is used  to set the balance for the Savings Account
				cout << "Please enter the balance of Savings Account[#" << i+1 << "](" << holder[i].name << "):";
				cin >> bal;
				if(bal < 0)
					cout << "*INVALID BALANCE*" << endl;
				else
					holder[i].savings.setBalance(bal);
			}while(bal < 0);//do while END - Set Savings Account Balance

			holder[i].savings.setAnnualRate(aRate);//Set Savings Account Annual Rate to aRate

			do{//do while START - Loop containing a menu that controls the Savings Account, allowing them to make withdrawls, deposits and run a Monthly Procedure
				cout << "\n-Admin Account Control: Savings Account[#" << i + 1 << "](" << holder[i].name << ")-" << endl;
				cout << "Choose from the following menu:" << endl;
				cout << "1. Make a withdrawl" << endl;
				cout << "2. Make a deposit" << endl;
				cout << "*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*" << endl;
				cout << "Input:";
				cin >> input;
				switch (input) {//switch START - Uses the value of input to determine which menu option to select
				case 1://Withdrawl - Allows withdrawls to be made to the Savings Account
					do{//do while START - amount becomes the number typed in by the user, which is used as the amount to withdraw
						cout << "Enter the amount to be withdrawn:$";
						cin >> amount;
						if (amount <= 0)
							cout << "INVALID AMOUNT" << endl;
						else
							holder[i].savings.withdraw(amount);
					}while (amount <= 0);//do while END - Savings - Withdrawl Amount
					break;
				case 2://Deposit - Allows deposits to be made to the Savings Account
					do{//do while START - amount becomes the number typed in by the user, which is used as the amount to deposit
						cout << "Enter the amount to be deposited:$";
						cin >> amount;
						if (amount <= 0)
							cout << "INVALID AMOUNT" << endl;
						else
							holder[i].savings.deposit(amount);
					}while (amount <= 0);//do while END - Savings - Deposit Amount
					break;
				case -1://Monthly Procedure - displays all information of the account
					cout << "\n-Savings Account[#" << i + 1 << "]-" << endl;
					cout << "Name:" << holder[i].name << endl;
					cout << "Beginning Balance:$" << holder[i].savings.getStartBalance() << endl;
					cout << "Total amount of deposits:" << holder[i].savings.getDepositNum() << endl;
					cout << "Total amount of withdrawls:" << holder[i].savings.getWithdrawlNum() << endl;
					holder[i].savings.monthlyProc();
					cout << "Ending Balance(+ Added Interest):$" << holder[i].savings.getBalance() << endl;
					break;
				default://Invalid
					cout << "*INVALID INPUT*" << endl;
				}//switch END - Savings
			}while (input != -1);//do while END - Savings Account Control

			cout << endl;

			//Checking

			do{//do while START - bal becomes the number typed in by the user, which is used  to set the balance for the Checking Account
				cout << "Please enter the balance of Checking Account[#" << i + 1 << "](" << holder[i].name << "):";
				cin >> bal;
				if (bal < 0)
					cout << "*INVALID BALANCE*" << endl;
				else
					holder[i].checking.setBalance(bal);
			}while (bal < 0);//do while END - Set Checking Account Balance

			holder[i].checking.setAnnualRate(aRate);//Set Checking Account Annual Rate to aRate

			do{//do while START - Loop containing a menu that controls the Checking Account, allowing them to make withdrawls and run a Monthly Procedure
				cout << "\n-Admin Account Control: Checking Account[#" << i + 1 << "](" << holder[i].name << ")-" << endl;
				cout << "Choose from the following menu:" << endl;
				cout << "1. Make a withdrawl" << endl;
				cout << "2. Make a deposit" << endl;
				cout << "*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*" << endl;
				cout << "Input:";
				cin >> input;
				switch(input){//switch START - Uses the value of input to determine which menu option to select
				case 1://Withdrawl - Allows withdrawls to be made to the Checking Account
					do{//do while START - amount becomes the number typed in by the user, which is used as the amount to withdraw
						cout << "Enter the amount to be withdrawn:$";
						cin >> amount;
						if (amount <= 0)
						cout << "INVALID AMOUNT" << endl;
						else
						holder[i].checking.withdraw(amount);
					}while (amount <= 0);//do while END - Checking - Withdrawl Amount
					break;
				case 2://Deposit - Allows deposits to be made to the Checking Account
					do {//do while START - amount becomes the number typed in by the user, which is used as the amount to deposit
						cout << "Enter the amount to be deposited:$";
						cin >> amount;
						if (amount <= 0)
							cout << "INVALID AMOUNT" << endl;
						else
							holder[i].checking.deposit(amount);
					} while (amount <= 0);//do while END - Checking - Deposit Amount
					break;
				case -1://Monthly Procedure - displays all information of the account
					cout << "\n-Checking Account[#" << i + 1 << "]-" << endl;
					cout << "Name:" << holder[i].name << endl;
					cout << "Beginning Balance:$" << holder[i].checking.getStartBalance() << endl;
					cout << "Total amount of deposits:" << holder[i].checking.getDepositNum() << endl;
					cout << "Total amount of withdrawls:" << holder[i].checking.getWithdrawlNum() << endl;
					holder[i].checking.monthlyProc();
					cout << "Ending Balance(+ Added Interest):$" << holder[i].checking.getBalance() << endl;
					break;
				default://Invalid
					cout << "*INVALID INPUT*" << endl;
				}//switch END - Checking
			}while(input != -1);//do while END - Checking Account Control
			cout << endl;
		}//for END - Account Control
		restartProgram(restart);//function for setting restart to true or false, restart is passed by reference
		delete [] holder;//frees dynamically allocated memory
		holder = nullptr;//frees dynamically allocated memory
		cout << endl;
	}//while END - Restart
}//main END

//restartProgram START - used to determine whether to restart or end program
void restartProgram(bool &restart){
	char restInput = '.';//Used for user input
	do{//do while START - uses restInput to determine whether to restart or end the program
		cout << "Would you like to continue making accounts(Y), or end the program(N)?" << endl;
		cout << "Please enter (Y) or (N):";
		cin >> restInput;
		if(toupper(restInput) == 'Y')
			restart = true;
		else if(toupper(restInput) == 'N')
			restart = false;
		else
			cout << "*INVALID INPUT*" << endl;
	}while(toupper(restInput) != 'Y' && toupper(restInput) != 'N');//do while END - Restart Program
}//restartProgram END

//numOfAccounts START - used to determine the number of bank accounts to create
void numOfAccounts(int &count) {
	do{//do while START - count becomes the number typed in by the user, which is used for the number of people creating bank accounts
		cout << "Please enter the number of bank accounts being made:";
		cin >> count;
		if (count <= 0)
			cout << "*INVALID AMOUNT*" << endl;
	}while (count <= 0);//do while END - Number of Bank Accounts
}//numOfAccounts END

//AnnualRate START - used to determine the annual interest rate of all accounts
void annualRate(double &aRate){
	do{//do while START - aRate becomes the number typed in by the user, which is used for the Annual Interest Rate
		cout << "Please enter the annual interest rate (as a percentage) for all accounts:";
		cin >> aRate;
		if (aRate < 0)
			cout << "*INVALID ANNUAL INTEREST RATE*" << endl;
	}while (aRate < 0);//do while END - Annual Interest Rate
	aRate *= 0.01;//converts percentage to decimal
}//AnnualRate END

/*
Please enter the number of bank accounts being made:-1
*INVALID AMOUNT*
Please enter the number of bank accounts being made:0
*INVALID AMOUNT*
Please enter the number of bank accounts being made:2
Please enter the annual interest rate (as a percentage) for all accounts:-1
*INVALID ANNUAL INTEREST RATE*
Please enter the annual interest rate (as a percentage) for all accounts:12
Please enter the name of account holder[#1]:Dan
Please enter the balance of Savings Account[#1](Dan):-1
*INVALID BALANCE*
Please enter the balance of Savings Account[#1](Dan):0

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$-1
INVALID AMOUNT
Enter the amount to be withdrawn:$0
INVALID AMOUNT
Enter the amount to be withdrawn:$1

*Account is currently inactive(Less than $25 in account),no futher withdrawls can be made until it is reactivated. Current Balance($0.00)*

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:2
Enter the amount to be deposited:$-1
INVALID AMOUNT
Enter the amount to be deposited:$0
INVALID AMOUNT
Enter the amount to be deposited:$30

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:3
*INVALID INPUT*

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$1

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$1

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$1

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$1

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$1

-Admin Account Control: Savings Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:-1

-Savings Account[#1]-
Name:Dan
Beginning Balance:$0.00
Total amount of deposits:1.00
Total amount of withdrawls:5.00
Monthly Service Charges:$1.00
*Account is currently inactive(Less than $25 in account),no futher withdrawls can be made until it is reactivated*
Ending Balance(+ Added Interest):$24.24

Please enter the balance of Checking Account[#1](Dan):10

-Admin Account Control: Checking Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$11
*A withdrawl of $11.00 would cause the current balance($10.00) to go below $0*
*Due to this, the withdrawl has not been made, and a $15 service charge has been taken from the account*
*The balance has now become negative($-5.00) and the negative amount is owed*

-Admin Account Control: Checking Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:2
Enter the amount to be deposited:$20

-Admin Account Control: Checking Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$5

-Admin Account Control: Checking Account[#1](Dan)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:-1

-Checking Account[#1]-
Name:Dan
Beginning Balance:$10.00
Total amount of deposits:1.00
Total amount of withdrawls:1.00
Monthly Service Charges:$5.10
Ending Balance(+ Added Interest):$4.95

Please enter the name of account holder[#2]:Bob
Please enter the balance of Savings Account[#2](Bob):100

-Admin Account Control: Savings Account[#2](Bob)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:2
Enter the amount to be deposited:$100

-Admin Account Control: Savings Account[#2](Bob)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$200

-Admin Account Control: Savings Account[#2](Bob)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:-1

-Savings Account[#2]-
Name:Bob
Beginning Balance:$100.00
Total amount of deposits:1.00
Total amount of withdrawls:1.00
Monthly Service Charges:$0.00
*Account is currently inactive(Less than $25 in account),no futher withdrawls can be made until it is reactivated*
Ending Balance(+ Added Interest):$0.00

Please enter the balance of Checking Account[#2](Bob):25

-Admin Account Control: Checking Account[#2](Bob)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$30
*A withdrawl of $30.00 would cause the current balance($25.00) to go below $0*
*Due to this, the withdrawl has not been made, and a $15 service charge has been taken from the account*

-Admin Account Control: Checking Account[#2](Bob)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$11
*A withdrawl of $11.00 would cause the current balance($10.00) to go below $0*
*Due to this, the withdrawl has not been made, and a $15 service charge has been taken from the account*
*The balance has now become negative($-5.00) and the negative amount is owed*

-Admin Account Control: Checking Account[#2](Bob)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:1
Enter the amount to be withdrawn:$1
*The withdrawl has not been made, the account currently owes a negative amount of $-5.00*

-Admin Account Control: Checking Account[#2](Bob)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:-1

-Checking Account[#2]-
Name:Bob
Beginning Balance:$25.00
Total amount of deposits:0.00
Total amount of withdrawls:0.00
Monthly Service Charges:$5.00
Ending Balance(+ Added Interest):$-10.00

Would you like to continue making accounts(Y), or end the program(N)?
Please enter (Y) or (N):z
*INVALID INPUT*
Would you like to continue making accounts(Y), or end the program(N)?
Please enter (Y) or (N):y

Please enter the number of bank accounts being made:1
Please enter the annual interest rate (as a percentage) for all accounts:0
Please enter the name of account holder[#1]:Test
Please enter the balance of Savings Account[#1](Test):0

-Admin Account Control: Savings Account[#1](Test)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Savings Account Control, display account info and run Monthly Procedure*
Input:-1

-Savings Account[#1]-
Name:Test
Beginning Balance:$0.00
Total amount of deposits:0.00
Total amount of withdrawls:0.00
Monthly Service Charges:$0.00
*Account is currently inactive(Less than $25 in account),no futher withdrawls can be made until it is reactivated*
Ending Balance(+ Added Interest):$0.00

Please enter the balance of Checking Account[#1](Test):0

-Admin Account Control: Checking Account[#1](Test)-
Choose from the following menu:
1. Make a withdrawl
2. Make a deposit
*Type '-1' to end Admin Checking Account Control, display account info and run Monthly Procedure*
Input:-1

-Checking Account[#1]-
Name:Test
Beginning Balance:$0.00
Total amount of deposits:0.00
Total amount of withdrawls:0.00
Monthly Service Charges:$5.00
Ending Balance(+ Added Interest):$-5.00

Would you like to continue making accounts(Y), or end the program(N)?
Please enter (Y) or (N):n

Press any key to continue . . .
*/