#pragma once
#include "stdafx.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Comms.h"

using namespace std;

class Server : public Comms {
public:
	Server() {};
	~Server() {};
	int Run();
	int CreateServiceBinding(SOCKET serverSocket);
	void ListenForClient(SOCKET serverSocket);
	int AcceptConnection(SOCKET serverSocket);
private:
	static DWORD WINAPI ServerThreadSender(void* param);
	struct SERVICEPARAMS {
		LPVOID socket;
		Server * instance;
		int size;
		string name;
	};
};