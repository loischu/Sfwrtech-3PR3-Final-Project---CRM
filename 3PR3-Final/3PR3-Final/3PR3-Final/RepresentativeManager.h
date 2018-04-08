#ifndef REPRESENTATIVEMANAGER_H
#define REPRESENTATIVEMANAGER_H
#include "Representative.h"
#include <vector>
#include <string>

class RepresentativeManager
{
public:
	RepresentativeManager(void);
	~RepresentativeManager(void);

	int AddRepresentative(Representative c);
	void UpdateRepresentative(Representative c);
	Representative GetRepresentative(int RepresentativeId);
	std::vector<Representative> GetRepresentatives(std::string keyword);
};

#endif