#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int cost[MAX][MAX];
int dist[MAX][MAX];
int next[MAX][MAX];
int nodes;

void initialise(){
	for(int i=0;i<nodes;i++){
		for(int j=0;j<nodes;j++){
			dist[i][j] = cost[i][j];
			next[i][j] = j;
		}
	}
}

void dvr(){
	int updated;
	do{
		updated = 0;
		for(int i=0;i<nodes;i++){
			for(int j=0;j<nodes;j++){
				for(int k=0;k<nodes;k++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j] = dist[i][k]+dist[k][j];
						next[i][j] = next[i][k];
						updated = 1;
					}
				}
			}
		}
	}while(updated);
}

void print(){
	printf("ROUTING TABLES:\n");
	for(int i=0;i<nodes;i++){
		printf("Routing Table for Node %d\n",i+1);
		printf("Node\t Distance\t NextHop\n");
		for(int j=0;j<nodes;j++){
			printf("%d\t%10d\t%10d\n",j+1,dist[i][j],next[i][j]+1);
		}
	}
}

int main(){
	printf("Enter the number of nodes:");
	scanf("%d",&nodes);
	printf("Enter the cost matrix of the Nodes(0 for same node, 9999 for infinity)\n");
	for(int i=0;i<nodes;i++){
		printf("Node %d:",i+1);
		for(int j=0;j<nodes;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	initialise();
	dvr();
	print();
	return 0;
}
