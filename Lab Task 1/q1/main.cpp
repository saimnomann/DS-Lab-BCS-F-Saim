// Suppose you are developing a bank account management system, and you have defined the
// BankAccount class with the required constructors. You need to demonstrate the use of these
// constructors in various scenarios.
// 1. Default Constructor Usage: Create a default-initialized BankAccount object named
// account1. Print out the balance of account1.
// 2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
// an initial balance of $1000. Print out the balance of account2.
// 3. Copy Constructor Usage: Using the account2 you created earlier, create a new
// BankAccount object named account3 using the copy constructor. Deduct $200 from
// account3 and print out its balance. Also, print out the balance of account2 to ensure it
// hasn't been affected by the transaction involving account3.
#include<iostream>
using namespace std;
class BankAccount{
    double balance;
    public:
    BankAccount(){
       balance=0;
    }
    BankAccount(double bal){
       balance=bal;
    }
    BankAccount(const BankAccount &acc){
    	balance=acc.balance;
    }
    void showBalance(){
    cout<<"Balance is $"<<balance<<endl;
	}
	void withdraw(double amount){
		balance-=amount;
	}
};
int main(){
	
BankAccount account1;
account1.showBalance();
BankAccount account2(1000);
account2.showBalance();
BankAccount account3(account2);
account3.withdraw(200);
account3.showBalance();
account2.showBalance();
}