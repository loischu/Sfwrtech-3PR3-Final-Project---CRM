#pragma once
#include "Case.h"
#include <vector>

class CaseManager
{
public:
	CaseManager();
	~CaseManager();

	void AddCase(Case c);
	void UpdateCase(Case c);
	Case GetCase(std::string CaseId);
	std::vector<Case> GetCases(std::string keyword);


};

