all : sgnbAdditionRequest sgnbAdditionRequestAck

sgnbAdditionRequest : sgnbAdditionRequestTest.cpp mnUDPSend.c
	g++ -o sgnbAdditionRequest sgnbAdditionRequestTest.cpp mnUDPSend.c

sgnbAdditionRequestAck : sgnbAdditionRequestAckTest.cpp snUDPSend.c
	g++ -o sgnbAdditionRequestAck sgnbAdditionRequestAckTest.cpp snUDPSend.c
