/*
 * Customer.cpp
 *
 *  Created on: 12-May-2015
 *      Author: akash
 */

#include "Customer.h"

namespace std {

Customer::Customer(string first, string last, int accountNum, int pin) {
	this->first = first;
	this->last = last;
	this->accountNum = accountNum;
	this->pin = pin;
	balance = 1000;
}

string Customer::getTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%m-%d-%Y", timeinfo);
	std::string str(buffer);

	std::cout << str;
	return string(buffer);
}

void Customer::history() {
	while (transactions.size() > 10) {
		transactions.erase(transactions.begin());
	}

	vector<string>::iterator iter = transactions.begin();
	while (iter != transactions.end()) {
		cout << "<" << *iter << "> ";
	}
}

void Customer::checkBalance() {
	cout << balance << endl;
}

bool Customer::checkAccountNum(int accountNum) {
	if (accountNum == this->accountNum)
		return true;
	return false;
}
void Customer::withdraw() {
	float money;
	cout << "Enter the amount to withdraw:";
	cin >> money;
	if (money <= 0)
		return;
	if (money <= balance) {
		balance -= money;
		string transaction = getTime() ;
		transactions.push_back(transaction);
	}

	if (balance < 50) {
		cout
				<< "Your account will be closing because do not have sufficient amount in your account"
				<< endl;
	}

}

bool Customer::checkPin() {
	int pin;
	cout << "Enter your PIN:";
	cin >> pin;
	if (this->pin == pin)
		return true;
	return false;
}

void Customer::depositMoney() {
	float money;
	cout << "Enter the amount to deposit:";
	cin >> money;
	balance += money;
	string transaction = getTime();
	transactions.push_back(transaction);
}

void Customer::closeAccount() {
	if (balance <= 500) {
		balance = 0;
	} else {
		balance -= 500;
		cout << "Need to see the cashier to complete the task" << endl;
	}
}

Customer::~Customer() {
	cout << "Account Deleted Successfully. Have a nice day!!" << endl;
}

} /* namespace std */
