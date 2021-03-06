#pragma once
#include "Client.h"
#include <vector>
#include <string>

class ClientManager
{
public:
	ClientManager();
	~ClientManager();

	void AddClient(Client c);
	void UpdateClient(Client c);
	Client GetClient(std::string ClientId);
	std::vector<Client> GetClients(std::string keyword);


};

