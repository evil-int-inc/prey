//
// Created by Ruslan on 28.07.2024.
//
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
// TODO: isn't used ?
#include <arpa/inet.h>

class Server__ {
private:
    int listenSocket;
    int clientSocket;
    bool serverIsRunning;
    sockaddr_in serverAddress;
    sockaddr_in clientAddress;
    socklen_t clientAddressLength;
    char buffer[1024];
public:
    int port;
    void run(const std::string response) {
        while (serverIsRunning) {
            this->clientSocket = accept(listenSocket, (struct sockaddr *) &clientAddress, &clientAddressLength);
            if (clientSocket == -1) {
                continue;
            }

            // * Simple HTTP response
            std::string httpResponse = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: " +
                                       std::to_string(response.length()) + "\r\n\r\n" + response;

            send(clientSocket, httpResponse.c_str(), httpResponse.length(), 0);
            close(clientSocket);
        }
    };
    void destroy() {
        this->serverIsRunning = false;
        close(clientSocket);
        close(listenSocket);
    };

    Server__(const int port = 8080) {
        this->port = port;
        this->serverIsRunning = true;

        // * Create a socket
        this->listenSocket = socket(AF_INET, SOCK_STREAM, 0);

        if (listenSocket == -1) {
            throw MessageError__("Server socket() failed.");
        }

        // * Bind the socket to an address
        this->serverAddress = sockaddr_in();
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        // * Listen on any IP address
        serverAddress.sin_port = htons(this->port);

        // * Bind socket to an address
        if (::bind(listenSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
            close(listenSocket);
            throw MessageError__("Server bind() failed.");
        }

        // * Start listening for connections
        if (listen(listenSocket, SOMAXCONN) == -1) {
            close(listenSocket);
            throw MessageError__("Server listen() failed.");
        }

        // Accept a client connection (replace with your handling logic)
        this->clientAddress = sockaddr_in();
        this->clientAddressLength = sizeof(clientAddress);
    }
    ~Server__() {
        this->destroy();
    }
};
