/** @file This file provides attributes of SGNB Addition Request Acknowledge Message.
 *  All definitons get from " 3GPP TS 36.423 version 15.2.0 Release 15 " document.
*/

#ifndef SGNBADDITIONREQUESTACK_HPP
#define SGNBADDITIONREQUESTACK_HPP
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "snUDPSend.h"

class SGNBAdditionRequestAck {
  public:
    class MessageType{
        public:
        int procedureCode;
        int typeOfMessage;
    };
	class ENDCResourceConfiguration{
        public:
        // Enumerated Values
        int pdcpatSgNB;
        int mcgResources;
        int scgResources;
    };
    class S1ULGTPtunnelEndpoint{
        public:
        // The document says BIT STRING (1..160, ...)
        int transportLayerAddress[21] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, '\0'};
        // The document says that GTP-TE-ID has to be 4 bytes octet string but, I do not know the octet string data type.
        char gtpTEId[5] = {0x01, 0x02, 0x03, 0x04};
    };
    MessageType * messageType;
	ENDCResourceConfiguration * endcResourceConfiguration;
	S1ULGTPtunnelEndpoint * gtpTunnelEndPoint;
	int meNBUEX2APid;
	int engnbUeX2apId;
	int eRABid;	
};
#endif
