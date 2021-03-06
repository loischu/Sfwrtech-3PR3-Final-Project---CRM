#pragma once
#include "CustomerService.h"
#include <vector>
#include <string>

class CustomerServiceManager
{
public:
	CustomerServiceManager();
	~CustomerServiceManager();

	void AddCustomerService(CustomerService c);
	void UpdateCustomerService(CustomerService c);
	CustomerService GetCustomerService(std::string CustomerServiceId);
	std::vector<CustomerService> GetRepresentatives(std::string keyword);
};

