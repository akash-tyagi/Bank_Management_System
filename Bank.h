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
	unsigned int freeAccountNum;
	int totalCustomers;
	float totalAmtDeposits;
	float avgCurrBalance;
	vector<Customer> customers;
	Statistics stats;
public:
	Bank();
	void startOperating();
	void openAccount();
	vector<Customer>::iterator findCustomer();
	void readCustomersFromFile();
	void writeCustomerDataToFile();
	unsigned getNextFreeAccountNumber();
};

istream& operator >>(istream &, Transaction &);
istream& operator >>(istream &, Customer &);
#endif /* BANK_H_ */
