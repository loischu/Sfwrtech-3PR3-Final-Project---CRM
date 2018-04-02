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
	Case GetCase(string CaseId);
	vector<Case> GetCases(string keyword);


};

