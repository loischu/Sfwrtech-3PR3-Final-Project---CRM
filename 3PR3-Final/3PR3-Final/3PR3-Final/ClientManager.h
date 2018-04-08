#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H
#include <vector>
#include <string>
#include "Client.h"

class ClientManager
{
public:
	ClientManager(void);
	~ClientManager(void);

	int AddClient(Client c);
	Client GetClient(int ClientId);
	void UpdateClient(Client c);
	std::vector<Client> GetClients(std::string keyword);

};

#endif