#ifndef WIN32_SERVER_SOCKET_HPP
#define WIN32_SERVER_SOCKET_HPP

#include "ServerSocket.hpp"
#include <stdio.h>

#if _WIN32 && !defined(__arm64__)
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

class WIN32ServerSocket : public ServerSocket
{
private:
	// Networking data
	// PCSTR _port;

	// SocketData
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

public:
	WIN32ServerSocket(int port, int reqbufflen);
	~WIN32ServerSocket();
	int Init();
	int Listen();
	int SendResponse(HttpResponse & response) const;
};
#endif

#endif // !WIN32_SERVER_SOCKET_H
