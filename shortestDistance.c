#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 14

void dijkstra(int G[MAX][MAX],int n,int startnode);

char city[][20]={"Pune","Kolkata","Bangalore","Delhi","Mumbai","Vizag","Ahmedabad","Puri","Indore","Goa","Lucknow","Hyderabad","Chennai","Guwahati"};
int main()
{
	int i,j,n,u;
	printf("Select the starting city from:\n 0-> Pune \n 1->Kolkata \n 2->Bangalore \n 3->Delhi \n 4->Mumbai\n 5->Vizag\n 6->Ahmedabad\n 7->Puri\n 8->Indore\n 9->Goa\n 10->Lucknow\n 11->Hyderabad\n 12->Chennai\n 13->Guwahati\n");
	n=14;
	int G[MAX][MAX]={ {0,1140,0,0,1110,0,1150,0,0,0,0,0,0,0},
		      {0,0,0,0,0,0,0,0,1190,0,0,0,0,0},
		      {0,0,0,0,0,0,0,0,0,0,1120,0,0,1165},
		      {0,1110,0,0,0,0,0,0,0,0,0,130,0,0},
		      {0,0,0,1160,0,1120,0,0,0,1140,0,0,0,0},
		      {0,0,0,0,0,0,0,1130,0,0,0,0,0,0},
		      {0,0,1210,0,0,0,0,0,1160,0,0,0,0,0},
		      {0,0,1250,0,0,0,0,0,0,0,0,0,0,0},
		      {0,0,0,0,0,0,1160,0,0,0,0,0,0,0},
		      {0,0,1170,0,0,0,0,0,0,0,0,0,0,0},
   		      {1188,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,1120,0},
 		      {0,0,1200,0,0,0,0,0,0,0,0,0,0,0},
  		      {0,0,0,0,0,0,0,0,1177,0,0,0,0,0} };
	
	printf("\nEnter the starting city:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nCost of travelling to the city %s=Rs %d",city[i],distance[i]);
			printf("\nPath=%s",city[i]);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%s",city[j]);
			}while(j!=startnode);
			printf("\n");
	}
}