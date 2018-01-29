#ifndef CLIENTSOCKET_H_INCLUDED
#define CLIENTSOCKET_H_INCLUDED
#include <vector>
//#define _WIN32_WINNT  0x0503
//#define _WIN32
#if defined(_WIN32)
#include <WinSock2.h>
#include <Ws2tcpip.h>
#pragma command(lib, ws2_32.lib)
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#else
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

using namespace std;
class ClientSocket{
    public:
        int createSocket(string port, string address);
        bool sendFile(char const* filename, int socket);
        static char *readAllBytes(char const* filename);
};

#endif // CLIENTSOCKET_H_INCLUDED
