#include "Statistics.h"

namespace std {

Statistics::Statistics() {
	totalCustomers = 0;
	totalDeposits = 0;
	avgCurrBalance = 0;

}

void Statistics::fillData(vector<Customer> customers) {
	totalCustomers = 0;
	totalDeposits = 0;
	avgCurrBalance = 0;

	vector<Customer>::iterator iter = customers.begin();
	while (iter != customers.end()) {
		totalCustomers++;
		totalDeposits += (*iter).getBalance();
		iter++;
	}

	avgCurrBalance = totalDeposits / totalCustomers;
}

void Statistics::getStats() {
	int option;
	cout << "Please enter one of these options:" << endl;
	cout << "1. Total number of customers" << endl;
	cout << "2. Total amount of deposits" << endl;
	cout << "3. Average current balance" << endl;
	cin >> option;
	switch (option) {
	case 1:
		cout << "Total Customers:" << totalCustomers;
		break;
	case 2:
		cout << "Total Deposit Amount:" << totalDeposits;
		break;
	case 3:
		cout << "Average Current balance:" << avgCurrBalance;
		break;
	default:
		cout << "Wrong Input" << endl;
		break;
	}
}
} /* namespace std */
