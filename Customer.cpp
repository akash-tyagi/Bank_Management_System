#include "Customer.h"

namespace std {
Customer::Customer() {
	first = last = "";
	accountNum = 0;
	balance = -1;
	pin = -1;
}
Customer::Customer(string first, string last, unsigned accountNum, int pin) {
	this->first = first;
	this->last = last;
	this->accountNum = accountNum;
	this->pin = pin;
	balance = 1000;
}

/*Get the current date in format: mm-hh-yyyy */
string Customer::getTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%m-%d-%Y", timeinfo);
	std::string str(buffer);

	return string(buffer);
}

void Customer::history() {
	while (transactions.size() > 10) {
		transactions.erase(transactions.begin());
	}
	cout << "Last 10 Transactions:";
	vector<Transaction>::iterator iter = transactions.begin();
	while (iter != transactions.end()) {
		(*iter).print_transaction();
		iter++;
	}
}

void Customer::checkBalance() {
	cout << balance << endl;
}

bool Customer::checkAccountNum(unsigned accountNum) {
	if (accountNum == this->accountNum)
		return true;
	return false;
}

void Customer::withdraw() {
	float money;
	cout << "Enter the amount to withdraw:";
	cin >> money;
	if (money <= 0) {
		cout << "Withdraw failed. Amount can not be zero or negative." << endl;
		return;
	} else if (money > 500) {
		cout << "Withdraw failed. Amount can not be greater than $500" << endl;
		return;
	} else if (balance - money < 50) {
		cout << "Withdraw Failed. Balance below $50 not allowed." << endl;
	} else {
		if (balance < 1000) {
			string response;
			cout << "$10 Maintenance fee will be charged for withdrawal,"
					<< "since balance is below $1000. Please enter 'yes' if still want to continue"
					<< endl;
			cin >> response;
			if (response != "yes")
				return;
			balance -= 10;
		}
		balance -= money;
		cout << "Withdraw successful. Please collect $" << money << endl;
		Transaction transaction;
		transaction.amount = money;
		transaction.date = getTime();
		transactions.push_back(transaction);
	}
}

bool Customer::checkPin() {
	int pin;
	cout << "Enter your PIN:";
	cin >> pin;
	if (this->pin == pin)
		return true;
	cout << "Wrong pin number entered." << endl;
	return false;
}

void Customer::depositMoney() {
	float money;
	cout << "Enter the amount to deposit:";
	cin >> money;
	balance += money;
	Transaction transaction;
	transaction.amount = money;
	transaction.date = getTime();
	transactions.push_back(transaction);
}

void Customer::closeAccount() {
	if (balance <= 500) {
		cout << "Please collect $" << balance << endl;
		balance = 0;
	} else {
		balance -= 500;
		cout << "Please collect $500. See the cashier to complete the task"
				<< endl;
	}
}

float Customer::getBalance() const {
	return balance;
}

unsigned int Customer::getAccountNum() const {
	return accountNum;
}

void Customer::setAccountNum(unsigned int accountNum) {
	this->accountNum = accountNum;
}

void Customer::setBalance(float balance) {
	this->balance = balance;
}

const string& Customer::getFirst() const {
	return first;
}

void Customer::setFirst(const string& first) {
	this->first = first;
}

const string& Customer::getLast() const {
	return last;
}

void Customer::setLast(const string& last) {
	this->last = last;
}

int Customer::getPin() const {
	return pin;
}

void Customer::setPin(int pin) {
	this->pin = pin;
}

vector<Transaction>& Customer::getTransactions() {
	return transactions;
}

void Customer::setTransactions(const vector<Transaction>& transactions) {
	this->transactions = transactions;
}
} /* namespace std */
