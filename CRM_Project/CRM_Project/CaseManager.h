#pragma once
#include "Case.h"

static class CaseManager
{
public:
	CaseManager();
	~CaseManager();

	void AddCase(Case c);
	void UpdateCase(Case c);
	Case GetCase(std::string CaseId);
	Case* GetCases(std::string keyword);


};

