#ifndef CASE_H
#define CASE_H


#include <string>
class Case
{
protected:
	std::string caseId;
	std::string clientId;
	std::string repId;
	std::string details;
	std::string type;
public:
	Case();
	~Case();
	void set_caseId(std::string id);
	void set_clientId(std::string s);
	void set_repId(std::string id);
	void set_details(std::string s);
	void set_type(std::string s);

	std::string get_caseId();
	std::string get_clientId();
	std::string get_repId();
	std::string get_details();
	std::string get_type();
};

#endif