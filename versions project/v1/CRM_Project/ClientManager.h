#pragma once
#include "Client.h"
#include <vector>

class ClientManager
{
public:
	ClientManager();
	~ClientManager();

	void AddClient(Client c);
	void UpdateClient(Client c);
	Client GetClient(string ClientId);
	vector<Client> GetClients(string keyword);


};

