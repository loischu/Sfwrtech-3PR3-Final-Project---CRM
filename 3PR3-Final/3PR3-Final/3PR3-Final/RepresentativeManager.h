#ifndef REPRESENTATIVEMANAGER_H
#define REPRESENTATIVEMANAGER_H
#include "Representative.h"
#include <vector>
#include <string>

class RepresentativeManager
{
public:
	RepresentativeManager(void);
	~RepresentativeManager(void);

	int AddCustomerService(Representative c);
	void UpdateCustomerService(Representative c);
	Representative GetCustomerService(int CustomerServiceId);
	std::vector<Representative> GetRepresentatives(std::string keyword);
};

#endif