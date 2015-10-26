#ifndef _TCPServer_HPP
#define _TCPServer_HPP

#include <iostream>
#include <vector>

#include <unistd.h> // close
#include <netdb.h> // getprotobyname
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <arpa/inet.h> // inet_ntoa

enum STATE {RUNNING, EXIT};

class TCPServer {
private:
    /* private data */
    const int PORT = 3000;
    const int BACKLOG = 10; // how many pending connections queue will hold

    STATE m_state = STATE::EXIT;
    int sockfd  = 0; // for listen
    int new_fd  = 0; // for new connections
    int sin_size = 0;
    struct sockaddr_in my_addr;
    struct sockaddr_in out_addr;

    struct timeval tv;  // time wait for socket to be changed
    fd_set readfds, writefds, exceptfds;
    std::vector<int> connected;
protected:
    /* protected data */
    bool init(void);
public:
    /* public data */
    TCPServer(void);
    virtual ~TCPServer (void);
    void run(void);
    void destroy(void);
};

#endif
