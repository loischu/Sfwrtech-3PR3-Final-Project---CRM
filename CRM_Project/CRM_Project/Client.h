#ifndef CLIENT_H
#define CLIENT_H

class Client
{
protected:
	std::string clientId;
	std::string companyId;
	std::string name;
	std::string title;
	std::string emailAddress;
	std::string phoneNumber;
	std::string physicalAddress;
	std::string notes;
public:
	Client();
	~Client();
	void set_clientId(std::string s);
	void set_companyId(std::string s);
	void set_name(std::string s);
	void set_title(std::string s);
	void set_emailAddress(std::string s);
	void set_phoneNumber(std::string s);
	void set_physicalAddress(std::string s);
	void set_notes(std::string s);

	std::string get_clientId();
	std::string get_companyId();
	std::string get_name();
	std::string get_title();
	std::string get_emailAddress();
	std::string get_phoneNumber();
	std::string get_physicalAddress();
	std::string get_notes();
};

Client::Client()
{

}

Client::~Client()
{

}

//Setters

void Client::set_clientId(std::string s)
{
	clientId = s;
}

void Client::set_name(std::string s)
{
	name = s;
}

void Client::set_title(std::string s)
{
	title = s;
}
void Client::set_emailAddress(std::string s)
{
	emailAddress = s;
}

void Client::set_phoneNumber(std::string s)
{
	phoneNumber = s;
}

void Client::set_physicalAddress(std::string s)
{
	physicalAddress = s;
}

void Client::set_notes(std::string s)
{
	notes = s;
}


//Getters

std::string Client::get_clientId()
{
	return clientId;
}

std::string Client::get_name()
{
	return name;
}

std::string Client::get_title()
{
	return title;
}

std::string Client::get_emailAddress()
{
	return emailAddress;
}

std::string Client::get_phoneNumber()
{
	return phoneNumber;
}

std::string Client::get_physicalAddress()
{
	return physicalAddress;
}

std::string Client::get_notes()
{
	return notes;
}

#endif

