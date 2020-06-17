/** @file This file provides attributes of SGNB Addition Request Message.
 *  All definitons get from " 3GPP TS 36.423 version 15.2.0 Release 15 " document.
*/

#ifndef SGNBADDITIONREQUEST_HPP
#define SGNBADDITIONREQUEST_HPP
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "mnUDPSend.h"

class SGNBAdditionRequest {
  public:
    class MessageType{
        public:
        int procedureCode;
        int typeOfMessage;
    };
    class SGNBUEAggregateMaximumBitRate{
        public:
		// initialize as unsigned long long because Bit Rate range is between 0 ... 10,000,000,000
        unsigned long long ueAggregateMaximumBitRateUplink;
        unsigned long long ueAggregateMaximumBitRateDownlink;
    };
    class S1ULGTPtunnelEndpoint{
        public:
        // The document says BIT STRING (1..160, ...)
        int transportLayerAddress[21] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, '\0'};
		// The document says that GTP-TE-ID has to be 4 bytes octet string but, I do not know the octet string data type.
        char gtpTEId[5] = {0x01, 0x02, 0x03, 0x04};
    };
    class NRUESecurityCapabilities{
        public:
        int nrEncryptionAlgorithms[3] = {0x01, 0x01, '\0'};
        int nrIntegrityProtectionAlgorithms[3] = {0x01, 0x01, '\0'};
        
    };
    class ENDCResourceConfiguration{
        public:
		// Enumerated Values
        int pdcpatSgNB;
        int mcgResources;
        int scgResources;
    };
    class ECGI{
        public:
        // 0x0F s are filler digits.
        char plmnIdentity[4] = {0x01, 0x0F, 0x0F, '\0'};
        char eUltranCellidentifier[29] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, '\0'};
    };
    class AllocationandRetentionPriority{
        public:
        int priorityLevel;
        int preEmptionCapability;
        int preEmptionVulnerability;
    };
    MessageType * messageType;
    SGNBUEAggregateMaximumBitRate * sgnbUEAggregateMaximumBitRate;
    S1ULGTPtunnelEndpoint * s1UlGtpTunnelEndpoint;
    NRUESecurityCapabilities * nrueSecurityCapabilities;
    ENDCResourceConfiguration * endcResourceConfiguration;
    ECGI * ecgi;
    AllocationandRetentionPriority * allocationandRetentionPriority;
    // get datas between 0 and 4095
    int meNBUEX2APid;
    int SgNBSecurityKey[32] ={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int eRABid;
    int drbId;
    int qci;
    // I can not get an information about that class element.
    int meNBtoSgNBContainer;
    void sendFromSocket(int* sendFrame);
};
#endif
