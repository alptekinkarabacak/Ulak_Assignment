/** @file This file provides attributes of SGNB Addition Request Acknowledge Message and combine all
 *  attributes to one SGNB Addition Request Acknowledge Message frame.
 *  All definitons get from " 3GPP TS 36.423 version 15.2.0 Release 15 " document.
*/

#include "sgnbAdditionRequestAck.hpp"
int main(int argc, char const *argv[])
{
    // SGNB Addition Request Acknowledge frame
    int sendingFrame[100];
    SGNBAdditionRequestAck * sGNBAdditionRequestAck = new SGNBAdditionRequestAck();
    SGNBAdditionRequestAck :: MessageType * messageType = new SGNBAdditionRequestAck :: MessageType();
	SGNBAdditionRequestAck :: ENDCResourceConfiguration * endcResourceConfiguration = new SGNBAdditionRequestAck :: ENDCResourceConfiguration();
	SGNBAdditionRequestAck :: S1ULGTPtunnelEndpoint * s1ULGTPtunnelEndpoint = new SGNBAdditionRequestAck :: S1ULGTPtunnelEndpoint();
    /*
     *    Initiation Part
     *  start to collect datas.
    */

    // Element of Message Type, possible types are 0 to 255
    messageType -> procedureCode = 5;
    // Enum type 1 -> Initiating Message, 2 Successful Outcome, Unsuccessful Outcome
    messageType -> typeOfMessage = 8;
    // 0 -> not present, 1 -> present
    endcResourceConfiguration -> pdcpatSgNB = 0;
    endcResourceConfiguration -> mcgResources = 0;
    endcResourceConfiguration -> scgResources = 0;
    // 15 -> MN 16 -> SN
    sGNBAdditionRequestAck -> meNBUEX2APid = 16;
    sGNBAdditionRequestAck -> eRABid = 14;
    // Size of an integer 0 to 2^32.
    sGNBAdditionRequestAck -> engnbUeX2apId = 13;
    
    sendingFrame[0] = messageType -> procedureCode;
    sendingFrame[1] = messageType -> typeOfMessage;
    sendingFrame[2] = endcResourceConfiguration -> pdcpatSgNB;
    sendingFrame[3] = endcResourceConfiguration -> mcgResources;
    sendingFrame[4] = endcResourceConfiguration -> scgResources;
    for(int i = 0; i < 21; i++)
    {
        sendingFrame[i + 5] = s1ULGTPtunnelEndpoint -> transportLayerAddress[i];
    }
    for(int i = 0; i < 4; i++)
    {
        sendingFrame[i + 26] = s1ULGTPtunnelEndpoint -> gtpTEId[i];
    }
    sendingFrame[30] = sGNBAdditionRequestAck -> meNBUEX2APid;
    sendingFrame[31] = sGNBAdditionRequestAck -> eRABid;
    sendingFrame[32] = sGNBAdditionRequestAck -> engnbUeX2apId;
    // Ok, all datas are collected, ready to send.
    snCommunication(sendingFrame);
    
    
    
    
    
    
    
	

   
    
    
    
    
    

    
    
}
