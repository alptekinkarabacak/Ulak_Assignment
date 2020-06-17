/** @file This file sends data, which imitates SGNB Addition Request Acknowledge, to Master Node.
 *  All datas send in UDP packages.
*/


#include "snUDPSend.h"

void snCommunication(int* sendFrame)
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[73] = { };
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }
    send(sock , sendFrame , (int)sizeof(sendFrame), 0 );
    printf("SGNB Addition Request Acknowledge Message has been sent\n");
    valread = read( sock , buffer, 73);
    for (int i=0;i<sizeof(buffer);i++)
    {
        printf("%d  i: %d\n",*(buffer+i),i );
    }
}
