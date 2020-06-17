/** @file This file provides attributes of SGNB Addition Request Message and combine all attributes to one
 *  SGNB Addition Request Message frame.
 *  All definitons get from " 3GPP TS 36.423 version 15.2.0 Release 15 " document.
*/

#include "sgnbAdditionRequest.hpp"
int main(int argc, char const *argv[])
{
    // SGNB Addition Request Frame
    int sendingFrame[73];
    SGNBAdditionRequest * sGNBAdditionRequest = new SGNBAdditionRequest();
    SGNBAdditionRequest :: MessageType * messageType = new SGNBAdditionRequest :: MessageType();
    messageType -> procedureCode = 5;
    messageType -> typeOfMessage = 8;
    SGNBAdditionRequest :: SGNBUEAggregateMaximumBitRate * sgnbUEAggregateMaximumBitRate = new SGNBAdditionRequest :: SGNBUEAggregateMaximumBitRate();
    SGNBAdditionRequest :: S1ULGTPtunnelEndpoint * s1UlGtpTunnelEndpoint = new SGNBAdditionRequest :: S1ULGTPtunnelEndpoint();
    SGNBAdditionRequest :: NRUESecurityCapabilities * nrueSecurityCapabilities = new SGNBAdditionRequest :: NRUESecurityCapabilities();
    SGNBAdditionRequest :: ENDCResourceConfiguration * endcResourceConfiguration = new SGNBAdditionRequest :: ENDCResourceConfiguration();
    SGNBAdditionRequest :: ECGI * ecgi =new SGNBAdditionRequest :: ECGI();
    SGNBAdditionRequest :: AllocationandRetentionPriority * allocationandRetentionPriority = new SGNBAdditionRequest :: AllocationandRetentionPriority();
	/*
	 *	Initiation Part
     *  start to collect datas.
	*/

	// Element of Message Type, possible types are 0 to 255
	messageType -> procedureCode = 5;
	// Enum type 1 -> Initiating Message, 2 Successful Outcome, Unsuccessful Outcome
	messageType -> typeOfMessage = 2;
	// bits/s
	sgnbUEAggregateMaximumBitRate -> ueAggregateMaximumBitRateUplink = 1000;
	sgnbUEAggregateMaximumBitRate -> ueAggregateMaximumBitRateDownlink = 900;
    
	// 0 -> not present, 1 -> present
	endcResourceConfiguration -> pdcpatSgNB = 0;
	endcResourceConfiguration -> mcgResources = 0;
	endcResourceConfiguration -> scgResources = 0;
    
    // No priority
    allocationandRetentionPriority -> priorityLevel = 15;
    // Enumerated, 0 -> shall not trigger preemption, 0x01 -> trigger pre-emption
    allocationandRetentionPriority -> preEmptionCapability = 1;
    // Enumerated, 0 -> notpre-emptable 1 -> preemptable
    allocationandRetentionPriority -> preEmptionVulnerability = 1;
    // 15 -> MN 16 -> SN
    sGNBAdditionRequest -> meNBUEX2APid = 15;
    sGNBAdditionRequest -> eRABid = 14;
    sGNBAdditionRequest -> drbId = 1;
    // 0...255
    sGNBAdditionRequest -> qci = 1;
    
    sendingFrame[0] = messageType -> procedureCode;
    sendingFrame[1] = messageType -> typeOfMessage;
    sendingFrame[2] = sGNBAdditionRequest -> meNBUEX2APid;
    sendingFrame[3] = nrueSecurityCapabilities -> nrEncryptionAlgorithms[0];
    sendingFrame[4] = nrueSecurityCapabilities -> nrEncryptionAlgorithms[1];
    sendingFrame[5] = nrueSecurityCapabilities -> nrIntegrityProtectionAlgorithms[0];
    sendingFrame[6] = nrueSecurityCapabilities -> nrIntegrityProtectionAlgorithms[1];
    for(int i = 0; i < 32; i++)
    {
        sendingFrame[i + 7] = sGNBAdditionRequest -> SgNBSecurityKey[i];
    }
    // unsigned long long is 8 bytes sized data type, that' s why I will split into 4 bytes(size of int).
    int splittedLongSize[4];
    splittedLongSize[0] = sgnbUEAggregateMaximumBitRate -> ueAggregateMaximumBitRateUplink & 0x0000FFFF;
    // I get MSB 4 bytes. Shifting 32 bits for placing into integer size.
    splittedLongSize[1] = (sgnbUEAggregateMaximumBitRate -> ueAggregateMaximumBitRateUplink & 0xFFFF0000) >> 32;
    sendingFrame[38] = splittedLongSize[0];
    sendingFrame[39] = splittedLongSize[1];
    sendingFrame[40] = sGNBAdditionRequest -> eRABid;
    sendingFrame[41] = sGNBAdditionRequest -> drbId;
    sendingFrame[42] = endcResourceConfiguration -> pdcpatSgNB;
    sendingFrame[43] = endcResourceConfiguration -> mcgResources;
    sendingFrame[44] = endcResourceConfiguration -> scgResources;
    sendingFrame[44] = sGNBAdditionRequest -> qci;
    sendingFrame[45] = allocationandRetentionPriority -> priorityLevel;
    sendingFrame[46] = allocationandRetentionPriority -> preEmptionCapability;
    sendingFrame[47] = allocationandRetentionPriority -> preEmptionVulnerability;
    for(int i = 0; i < 21; i++)
    {
        sendingFrame[i + 48] = s1UlGtpTunnelEndpoint -> transportLayerAddress[i];
    }
    for(int i = 0; i < 4; i++)
    {
        sendingFrame[i + 68] = s1UlGtpTunnelEndpoint -> gtpTEId[i];
    }
    // Ok, all datas are collected, ready to send.
    mnCommunication(sendingFrame);
}
