#include <iostream>
#include <fstream>
#include <vector>
#include <fcntl.h>
#include <string.h>

#include "ClientSocket.h"
#include "stdio.h"
#include "stdlib.h"

#define MTU 1500
//#define __LINUX

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
int ClientSocket::createSocket(string port, string address)
{
    #if defined(_WIN32)
    SOCKET sock;
    struct WSAData* wd = (struct WSAData*)malloc(sizeof(struct WSAData));
    WSAStartup(MAKEWORD(2, 0), wd);
    free(wd);
#else
    int sock;
#endif


    struct addrinfo* ai;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    getaddrinfo(address.c_str(), port.c_str(), &hints, &ai);
    sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    if(connect(sock, ai->ai_addr, ai->ai_addrlen)!=0){
        printf("\nSocket Connection FAILED!\n");
        if (sock) {

            #if defined(_WIN32)
            closesocket(sock);
            WSACleanup();
            #else
            close(sock);
            #endif
        }
        return 0;
    }

    printf("\nConnected!");


    return sock;
}

bool ClientSocket::sendFile(char const* filename, int socket)
{

    char *rts;
    int pos = 0;
    rts = readAllBytes(filename);
    ifstream file(filename, ios::binary | ios::ate);


    int div = file.tellg()/MTU;
    int resto = file.tellg()%MTU;
    /*while(pos < div)
    {*/


        if(send(socket, rts, file.tellg(), 0)  == -1)
        {

            std::cerr << "Send failed" << std::endl;
            #if defined(_WIN32)
            closesocket(sockCLient);
            WSACleanup();
            #else
            close(socket);
            #endif
            return false;
        }
        pos++;
        cout<<pos<<endl;



  /*  }*/
    //send(socket, rts + (pos*32), resto, 0);
    //char buf[4096];
    char c = 0;
    send(socket, &c, 1, 0);
    cout<<"Send sucess"<<endl;

    int i = 0;
    /*while(buf[i] != '\0'){
        printf("%c",buf[i]);
        i++;
    }*/

    free(rts);
    #if defined(_WIN32)
    closesocket(sockClient);
    WSACleanup();
    #else
    //close(socket);
    #endif
    return true;

}

char *ClientSocket::readAllBytes(char const* filename)
{
    ifstream ifs(filename, ios::binary|ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    char *result = (char*) malloc(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);
    ifs.close();

    return result;
}
