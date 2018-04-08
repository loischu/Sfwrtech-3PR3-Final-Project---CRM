#ifndef CASE_H
#define CASE_H
#include <string>
class Case
{

	int caseID;
	int clientID;
	int repID;
	std::string details;
	std::string type;

public:
	Case(void){}
	~Case(void){}

	const int& get_caseID() const { return caseID; }
	const int& get_clientID() const {return clientID;}
	const int& get_repID() const {return repID;}
	const std::string& get_details() const { return details; }
	const std::string& get_type() const { return type; }

	void set_caseID(int i) { caseID = i; }
	void set_clientID(int i) {clientID = i;}
	void set_repID(int i) {repID = i;}
	void set_details(std::string s) { details = s; }
	void set_type(std::string s) { type = s; }


};
#endif
