#ifndef CLIENT_H
#define CLIENT_H

class Client
{
protected:
	string clientId;
	string companyId;
	string name;
	string title;
	string emailAddress;
	string phoneNumber;
	string physicalAddress;
	string notes;
public:
	Client();
	~Client();
	void set_clientId(string s);
	void set_companyId(string s);
	void set_name(string s);
	void set_title(string s);
	void set_emailAddress(string s);
	void set_phoneNumber(string s);
	void set_physicalAddress(string s);
	void set_notes(string s);

	string get_clientId();
	string get_companyId();
	string get_name();
	string get_title();
	string get_emailAddress();
	string get_phoneNumber();
	string get_physicalAddress();
	string get_notes();
};

Client::Client()
{

}

Client::~Client()
{

}

//Setters

void Client::set_clientId(string s)
{
	clientId = s;
}

void Client::set_companyId(string s) 
{
	companyId = s;
}

void Client::set_name(string s)
{
	name = s;
}

void Client::set_title(string s)
{
	title = s;
}
void Client::set_emailAddress(string s)
{
	emailAddress = s;
}

void Client::set_phoneNumber(string s)
{
	phoneNumber = s;
}

void Client::set_physicalAddress(string s)
{
	physicalAddress = s;
}

void Client::set_notes(string s)
{
	notes = s;
}


//Getters

string Client::get_clientId()
{
	return clientId;
}

string Client::get_companyId()
{
	return companyId;
}

string Client::get_name()
{
	return name;
}

string Client::get_title()
{
	return title;
}

string Client::get_emailAddress()
{
	return emailAddress;
}

string Client::get_phoneNumber()
{
	return phoneNumber;
}

string Client::get_physicalAddress()
{
	return physicalAddress;
}

string Client::get_notes()
{
	return notes;
}

#endif

