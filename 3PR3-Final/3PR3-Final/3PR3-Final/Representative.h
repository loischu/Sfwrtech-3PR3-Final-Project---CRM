#ifndef REPRESENTATIVE_H
#define REPRESENTATIVE_H
#include <string>

class Representative
{

	int repID;
	std::string name;

public:
	Representative(){}
	~Representative(){}

	const int& get_repId() const {return repID;}
	const std::string& get_Name() const { return name; }

	void set_repId(int i) { repID = i; }
	void set_name(std::string i) {name = i;}
	
};
#endif