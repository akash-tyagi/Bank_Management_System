#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include<string>
#include<vector>
#include<iostream>
#include<ctime>
#include"Transaction.h"
using namespace std;
namespace std {

class Customer {
	string first;
	string last;
	unsigned int accountNum;
	int pin;
	float balance;
	vector<Transaction> transactions;
	string getTime();
public:
	Customer();
	Customer(string, string, unsigned, int);

	bool checkAccountNum(unsigned);
	bool checkPin();
	void depositMoney();
	void checkBalance();
	void withdraw();
	void history();
	void closeAccount();

	float getBalance() const;
	unsigned int getAccountNum() const;
	void setAccountNum(unsigned int);
	void setBalance(float);
	const string& getFirst() const;
	void setFirst(const string&);
	const string& getLast() const;
	void setLast(const string&);
	int getPin() const;
	void setPin(int);
	vector<Transaction>& getTransactions();
	void setTransactions(const vector<Transaction>& transactions);
};
}
/* namespace std */

#endif /* CUSTOMER_H_ */
