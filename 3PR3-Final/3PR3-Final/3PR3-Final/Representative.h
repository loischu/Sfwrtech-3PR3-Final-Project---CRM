#ifndef REPRESENTATIVE_H
#define REPRESENTATIVE_H
#include <string>

class Representative
{

	int repID;
	int companyID;
	std::string name;

public:
	Representative(){}
	~Representative(){}

	const int& get_repId() const {return repID;}
	const int& get_companyId() const { return companyID; }
	const std::string& get_Name() const { return name; }

	void set_repId(int i) { repID = i; }
	void set_companyId(int id) { companyID = id;}
	void set_name(std::string i) {name = i;}
	
};
#endif