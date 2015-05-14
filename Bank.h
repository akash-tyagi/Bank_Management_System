#ifndef BANK_H_
#define BANK_H_
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<fstream>
#include"Customer.h"
#include"Statistics.h"
#include"Transaction.h"
using namespace std;

class Bank {
public:
	int freeAccountNum;
	int totalCustomers;
	float totalAmtDeposits;
	float avgCurrBalance;
	vector<Customer> customers;
	Statistics stats;
	Bank();
	void startOperating();
	void openAccount();
	vector<Customer>::iterator findCustomer();
	virtual ~Bank();
};

istream& operator >>(istream &, Transaction &);
istream& operator >>(istream &, Customer &);
#endif /* BANK_H_ */
