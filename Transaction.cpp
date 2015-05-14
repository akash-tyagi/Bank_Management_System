/*
 * Transaction.cpp
 *
 *  Created on: 12-May-2015
 *      Author: akash
 */

#include "Transaction.h"

namespace std {

void Transaction::print_transaction() {
	cout << "(" << date << " " << amount << ")";
}
} /* namespace std */
