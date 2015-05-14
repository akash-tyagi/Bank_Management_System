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
//	cout << "\nThis is your Piggy Bank. Welcome valued customer.";
	string fileName = "src/CustomerData.db";
	ifstream ifs(fileName.c_str());
	vector<Customer> customers;
	while (true) {
		Customer cust;
		if (!(ifs >> cust))
			break;
		customers.push_back(cust);
	}

	while (false) {
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

istream& operator >>(istream& is, Transaction& t) {
	char ch1;
	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	string date;
	float money;
	is >> date >> money >> ch2;
	if (!is || ch2 != ')')
		cout << "OOPSSSSSSSSS!!!!!!";
	t.amount = money;
	t.date = date;
	return is;
}

istream& operator >>(istream& is, Customer& cust) {
	char ch1;
	if (is >> ch1 && ch1 != '[') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	cout << ch1;
	while (is >> ch1) {
		cout << ch1;
	}

	string temp;
	is >> temp >> cust.first >> cust.last >> temp >> cust.accountNum >> temp
			>> cust.pin >> temp >> cust.balance >> temp >> ch1;
	cout << 23 << cust.first << cust.last << temp << endl;

	vector<Transaction> transactions;
	Transaction t;
	while (is >> t) {
		Transaction temp;
		temp.amount = t.amount;
		temp.date = t.date;
		transactions.push_back(temp);
	}

	cust.transactions = transactions;
	return is;
}

