#pragma once
#include "Client.h"

static class ClientManager
{
public:
	ClientManager();
	~ClientManager();

	void AddClient(Client c);
	void UpdateClient(Client c);
	Client GetClient(std::string ClientId);
	Client* GetClients(std::string keyword);


};

