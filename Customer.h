#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include<string>
#include<vector>
#include<iostream>
#include<ctime>

using namespace std;
namespace std {

class Customer {
	string first;
	string last;
	int accountNum;
	int pin;
	float balance;
	vector<string> transactions;
	string getTime();
public:
	Customer(string, string, int, int);
	bool checkAccountNum(int);
	bool checkPin();
	void depositMoney();
	void checkBalance();
	void withdraw();
	void history();
	void closeAccount();
	virtual ~Customer();

	float getBalance() const {
		return balance;
	}
};

} /* namespace std */

#endif /* CUSTOMER_H_ */
