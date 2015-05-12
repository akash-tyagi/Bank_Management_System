#ifndef BANK_H_
#define BANK_H_
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include <iomanip>
#include "Customer.h"
#include"Statistics.h"
using namespace std;

class Bank {
	int freeAccountNum;
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
	virtual ~Bank();
};

#endif /* BANK_H_ */
