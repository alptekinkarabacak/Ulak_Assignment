/** @file This file sends data, which imitates SGNB Addition Request, to Secondary Node.
 *  All datas send in UDP packages.
*/


#include "mnUDPSend.h"
void mnCommunication(int* sendFrame)
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
       perror("socket failed");
       exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt)))
    {
       perror("setsockopt");
       exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                sizeof(address))<0)
    {
       perror("bind failed");
       exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
       perror("listen");
       exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                      (socklen_t*)&addrlen))<0)
    {
       perror("accept");
       exit(EXIT_FAILURE);
    }
    send(new_socket , sendFrame , (int)sizeof(sendFrame), 0 );
    printf("SGNB Addition Request Message has been sent\n");
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
}
