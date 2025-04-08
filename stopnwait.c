#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#define TOTALPACKETS 5
#define SUCCESS 70
#define ack_success (rand() % 100 < SUCCESS)

int main(){
	srand(time(0));
	int packet = 1;
	int ack_received;
	while(packet <= TOTALPACKETS){
		printf("Sender: Sending packet %d \n",packet);
		sleep(1);
		
		ack_received = ack_success;
		
		if(ack_received){
			printf("Receiver: Received the packet %d \n" , packet);
			packet++;
		}
		else{
			printf("Peceiver: Packet %d not received. \n",packet);
			sleep(2);
		}
	}
	
	printf("All the packets have been transmitted.\n");
	return 0;
}
