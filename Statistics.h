#ifndef STATISTICS_H_
#define STATISTICS_H_
#include<vector>
#include "Customer.h"
using namespace std;
namespace std {

class Statistics {
	int totalCustomers;
	float totalDeposits;
	float avgCurrBalance;
public:
	Statistics();
	void getStats();
	void fillData(vector<Customer>);
	virtual ~Statistics();
};

} /* namespace std */

#endif /* STATISTICS_H_ */
