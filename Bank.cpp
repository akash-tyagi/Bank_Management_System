/*
 * Bank.cpp
 *
 *  Created on: 12-May-2015
 *      Author: akash
 */

#include "Bank.h"

Bank::Bank() {
	freeAccountNum = 1;
	// TODO Auto-generated constructor stub

}

vector<Customer>::iterator Bank::findCustomer() {
	int accountNum;
	cout << "Enter your account number:";
	cin >> accountNum;
	vector<Customer>::iterator custIter = customers.begin();
	while (custIter != customers.end()) {
		if ((*custIter).checkAccountNum(accountNum) == true)
			break;
		custIter++;
	}
	return custIter;
}

void Bank::openAccount() {
	string first, last;
	cout << "Enter your first and last name: " << endl;
	cin >> first;
	cin >> last;

	int accountNumber = freeAccountNum;
	freeAccountNum++;

	srand(time(NULL));
	int pin = rand() % 10000;

	Customer customer(first, last, accountNumber, pin);
	customers.push_back(customer);

	cout << "Account Num:" << accountNumber << endl;
	cout << "Pin:" << setw(4) << setfill('0') << pin << endl;

}

void Bank::startOperating() {

	int option = 0;
	cout << "\nThis is your Piggy Bank. Welcome valued customer.";
	while (true) {
		cout << "\n\nPlease select one of these operations (enter a number):"
				<< endl;
		cout << "1. Open a new account" << endl;
		cout << "2. Close the existing account" << endl;
		cout << "3. Withdraw money (up to $500)" << endl;
		cout << "4. Deposit money" << endl;
		cout << "5. Account balance" << endl;
		cout << "6. List the last 10 transactions" << endl;
		cout << "7. Statistical information" << endl;
		cin >> option;

		switch (option) {
		case 1:
			openAccount();
			break;
		case 2: {
			string response;
			cout << "Are you sure you want to close your account?";
			cin >> response;
			if (response != "yes")
				break;

			vector<Customer>::iterator cust = findCustomer();
			if (cust == customers.end() || (*cust).checkPin() == false)
				continue;
			(*cust).closeAccount();
			customers.erase(cust);
			break;
		}
		case 3: {
			vector<Customer>::iterator cust = findCustomer();
			if (cust == customers.end() || (*cust).checkPin() == false)
				continue;
			(*cust).withdraw();
			break;
		}
		case 4: {
			vector<Customer>::iterator cust = findCustomer();
			if (cust == customers.end())
				continue;
			(*cust).depositMoney();
			break;
		}
		case 5: {
			vector<Customer>::iterator cust = findCustomer();
			if (cust == customers.end() || (*cust).checkPin() == false)
				continue;
			(*cust).checkBalance();
			break;
		}
		case 6: {
			vector<Customer>::iterator cust = findCustomer();
			if (cust == customers.end() || (*cust).checkPin() == false)
				continue;
			(*cust).history();
			break;
		}
		case 7:
			stats.fillData(customers);
			stats.getStats();
			break;
		}
	}
}

Bank::~Bank() {
// TODO Auto-generated destructor stub
}

