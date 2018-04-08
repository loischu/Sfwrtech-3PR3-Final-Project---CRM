#pragma once

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
	
};