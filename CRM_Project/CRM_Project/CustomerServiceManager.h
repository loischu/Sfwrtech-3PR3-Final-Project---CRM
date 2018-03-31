#pragma once
#include "CustomerService.h"

static class CustomerServiceManager
{
public:
	CustomerServiceManager();
	~CustomerServiceManager();

	void AddCustomerService(CustomerService c);
	void UpdateCustomerService(CustomerService c);
	CustomerService GetCustomerService(std::string CustomerServiceId);
	CustomerService* GetCompanies(std::string keyword);


};

