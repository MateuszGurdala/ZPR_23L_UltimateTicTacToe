#ifndef WIN32_SERVER_SOCKET_HPP
#define WIN32_SERVER_SOCKET_HPP

#include "ServerSocket.hpp"
#include <stdio.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>

#ifdef _MSC_VER
#pragma comment(lib, "ws2_32.lib")
#endif

class WIN32ServerSocket : public ServerSocket {
private:
  // Networking data
  // PCSTR _port;

  // SocketData
  SOCKET ListenSocket = INVALID_SOCKET;
  SOCKET ClientSocket = INVALID_SOCKET;

public:
  WIN32ServerSocket(int port, int reqbufflen);
  ~WIN32ServerSocket();
  virtual int Init();
  virtual int Listen();
  virtual int SendResponse(std::shared_ptr<HttpResponse> response) const;
};
#endif

#endif // !WIN32_SERVER_SOCKET_H
