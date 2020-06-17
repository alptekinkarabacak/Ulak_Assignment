/** @file This file sends data, which imitates SGNB Addition Request Acknowledge, to Master Node.
 *  All datas send in UDP packages.
 */

#ifndef SNUDPSEND_H
#define SNUDPSEND_H
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080

using namespace std;
#define PORT 8080

/* @brief This function sends given frame from socket, act like Secondary Node
 * @param sendFrame Frame to be sent.
 */
void snCommunication(int* sendFrame);

#endif

