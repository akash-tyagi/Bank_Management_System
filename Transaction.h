/*
 * Transaction.h
 *
 *  Created on: 12-May-2015
 *      Author: akash
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include<string>
#include<iostream>
using namespace std;
namespace std {

struct Transaction {
	string date;
	float amount;
	void print_transaction();
};

} /* namespace std */

#endif /* TRANSACTION_H_ */
