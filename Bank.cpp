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

unsigned Bank::getNextFreeAccountNumber() {
	vector<Customer>::iterator custIter = customers.begin();
	while (custIter != customers.end()) {
		if ((*custIter).checkAccountNum(freeAccountNum) == true) {
			freeAccountNum++;
			custIter = customers.begin();
			continue;
		}
		custIter++;
	}
	return freeAccountNum;
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

	unsigned int accountNumber = getNextFreeAccountNumber();

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
	readCustomersFromFile();
	cout << "Starting2";
	writeCustomerDataToFile();
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

int fData = 0;
void Bank::readCustomersFromFile() {
	string fileName = "CustomerData.db";
	ifstream ifs(fileName.c_str());
	fData = 0;
	while (true) {
		Customer cust;
		ifs >> cust;
		if (cust.getAccountNum() == 0)
			break;
		customers.push_back(cust);
	}
	cout << customers.size() << endl;
	cout << "Reading done" << endl;
}

istream& operator >>(istream& is, Transaction& t) {
	char ch1;
	if (is >> ch1 && ch1 != '(') {
		is.unget();
		fData = 1;
		return is;
	}

	char ch2;
	string date;
	float money;
	is >> date >> money >> ch2;
	cout << date << money << endl;
	if (!is || ch2 != ')')
		cout << "FILE READ ERROR!";
	t.amount = money;
	t.date = date;
	return is;
}

istream& operator >>(istream& is, Customer& cust) {
	char ch1;
	is >> ch1;
	if (ch1 != '[' || !is) {
		fData = 0;
		return is;
	}

	string temp;
	string first, last;
	unsigned accountNum;
	int pin;
	float balance;
	is >> temp >> first >> last >> temp >> accountNum >> temp >> pin >> temp
			>> balance >> temp >> ch1;
	cust.setAccountNum(accountNum);
	cust.setFirst(first);
	cust.setLast(last);
	cust.setPin(pin);
	cust.setBalance(balance);

	cout << first << last << accountNum << pin << balance << endl;

	vector<Transaction> transactions;
	Transaction t;
	fData = 2;
	while (is >> t && fData == 2) {
		Transaction temp;
		temp.amount = t.amount;
		temp.date = t.date;
		transactions.push_back(temp);
	}
	cust.setTransactions(transactions);
	cout << "\nTotal Transactions read:" + transactions.size();
	is >> ch1 >> ch1;
	return is;
}

void Bank::writeCustomerDataToFile() {
	string fileName = "CustomerData2.db";
	ofstream ost(fileName.c_str());
	vector<Customer>::iterator custIter = customers.begin();
	while (custIter != customers.end()) {
		ost << "[\n\tcustomer " << (*custIter).getFirst() << " "
				<< (*custIter).getLast() << "\n";
		ost << "\taccount " << (*custIter).getAccountNum() << "\n";
		ost << "\tPIN " << (*custIter).getPin() << "\n";
		ost << "\tbalance " << (*custIter).getBalance() << "\n";
		ost << "\ttransactions {";

		vector<Transaction>::iterator iter =
				(*custIter).getTransactions().begin();
		while (iter != (*custIter).getTransactions().end()) {
			ost << "(" << (*iter).date << " " << (*iter).amount << ") ";
			iter++;
		}
		ost << "}\n]\n";
		cout << "WRITING DONE1";
		custIter++;
	}
	ost.close();
}

