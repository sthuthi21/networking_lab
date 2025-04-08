#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define TOTAL 10
#define WIN 4
#define acksuccess (rand()%100 < 70)

int main(){
	int base = 0;
	int ack[TOTAL] = {0};
	srand(time(0));
	while(base<TOTAL){
		printf("\nSENDING WINDOW : %d to %d\n",base,(base+WIN < TOTAL)? base+WIN : TOTAL);
		for(int i=0;i<WIN && i+WIN <TOTAL ; i++){
			int pkt = base+i;
			if(!ack[pkt]){
				printf("Sender: Sending pkt %d\n",pkt);
				sleep(1);
				if(acksuccess){
					printf("Receiver: Acknowlegement received for pkt %d\n",pkt);
					ack[pkt]=1;
				}
				else{
					printf("Receiver: Acknowlegement NOT received for pkt %d\n" , pkt);
				}
			}
		}
		while(ack[base] && base<TOTAL){
			base++;
		}
		sleep(1);
		printf("\n");
	}
	printf("All packets have been sent successfully\n");
	return 0;
}
