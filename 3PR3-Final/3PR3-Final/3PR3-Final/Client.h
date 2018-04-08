#pragma once

#include <string>
class Client
{
	int clientID;
	int companyID;	
	std::string title;
	std::string clientName;
	std::string emailAddress;
	std::string phoneNumber;
	std::string Notes;
public:
	Client(void){}
	~Client(void){}

	const int& get_companyId() const { return companyID; }
	const int& get_clientID() const {return clientID;}
	const std::string& get_title() const { return title; }
	const std::string& get_clientName() const { return clientName; }
	const std::string& get_emailAddress() const { return emailAddress; }
	const std::string& get_Notes() const { return Notes; }

	void set_clientId(int i) {clientID = i; }
	void set_companyId(int i) {companyID = i; }
	void set_title(std::string s) { title = s; }
	void set_clientName(std::string s) { clientName= s; }
	void set_emailAddress(std::string s) { emailAddress= s; }
	void set_Notes(std::string s) { Notes= s; }


};

