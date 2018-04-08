#ifndef CASEMANAGER_H
#define CASEMANAGER_H

#include "Case.h"
#include <vector>
#include <string>

class CaseManager
{
public:
	CaseManager(void);
	~CaseManager(void);

	int AddCase(Case c);
	void UpdateCase(Case c);
	Case GetCase(int CaseId);
	std::vector<Case> GetCases(std::string keyword);
};

#endif