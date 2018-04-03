#ifndef CLIENT_H
#define CLIENT_H
#include <string>
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

#endif

