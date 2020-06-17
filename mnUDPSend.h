/** @file This file sends data, which imitates SGNB Addition Request, to Secondary Node.
 *  All datas send in UDP packages.
*/

#ifndef MNUDPSEND_H
#define MNUDPSEND_H
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<iostream>

using namespace std;
#define PORT 8080

/* @brief This function sends given frame from socket, act like Master Node
 * @param sendFrame Frame to be sent.
 */
void mnCommunication(int* sendFrame);

#endif
