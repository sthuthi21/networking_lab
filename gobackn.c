#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#define TOTALPACKET 10
#define WINDOW 4
#define FAILRATE 30

int main(){
	srand(time(0));
	int base = 1;
	while(base<=TOTALPACKET){
		for(int i=base; i<base+WINDOW && i<=TOTALPACKET; i++){
			printf("Sender: Sending packet %d \n",i);
			sleep(1);
		}
		int failed_packet = 0;
		for(int i=base; i<base+WINDOW && i<=TOTALPACKET; i++){
			if(rand()%100 >= FAILRATE){
				printf("Receiver: Acknowlegement received for packet %d \n",i);
			}
			else{
				printf("Receiver: Acknowledgemnt lost for packet %d . GOBACKN TRIGGERED.\n",i);
				failed_packet = i;
				break;
			}
		}
		if(failed_packet){
			base = failed_packet;
			printf("Retransimitting from packet %d.\n", base);
			sleep(2);
		}
		else{
			base += WINDOW;
			if (base<TOTALPACKET)
				printf("sliding window to packet %d \n\n",base);
		}
		
	}
	printf("All the packets have been transmitted\n");
	return 0;
}
