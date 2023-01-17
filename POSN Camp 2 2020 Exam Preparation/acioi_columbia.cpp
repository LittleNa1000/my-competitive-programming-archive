//				24/3/2563
#include<bits/stdc++.h>
using namespace std;
int city[1000][1000],dist[1000][1000],R,C;
void set_and_update(int i,int j){
	//if(i==0&&j==0) 	return ;
	if(i>0){//up check if it isn't 0,0
		if(dist[i-1][j]==0) {
			//printf("Updating dist[%d][%d] from %d to %d\n",i-1,j,dist[i-1][j],dist[i][j]+city[i-1][j]);
			dist[i-1][j]=dist[i][j]+city[i-1][j];
			
		}
		else if(dist[i-1][j]>dist[i][j]+city[i-1][j]){
			dist[i-1][j]=dist[i][j]+city[i-1][j];
			set_and_update(i-1,j);
		}
	}
	if(i<R-1){//down
		if(dist[i+1][j]==0) {
			//printf("Updating dist[%d][%d] from %d to %d\n",i+1,j,dist[i+1][j],dist[i][j]+city[i-1][j]);
			dist[i+1][j]=dist[i][j]+city[i+1][j];
			
		}
		else if(dist[i+1][j]>dist[i][j]+city[i+1][j]){
			dist[i+1][j]=dist[i][j]+city[i+1][j];
			set_and_update(i+1,j);
		}
	}
	if(j>0){//left check if it isn't 0,0
		if(dist[i][j-1]==0) {
			//printf("Updating dist[%d][%d] from %d to %d\n",i+1,j,dist[i+1][j],dist[i][j]+city[i-1][j]);
			dist[i][j-1]=dist[i][j]+city[i][j-1];
			
		}
		else if(dist[i][j-1]>dist[i][j]+city[i][j-1]){
			dist[i][j-1]=dist[i][j]+city[i][j-1];
			set_and_update(i,j-1);
		}
	}
	if(j<C-1){//right
		if(dist[i][j+1]==0) {
			//printf("Updating dist[%d][%d] from %d to %d\n",i+1,j,dist[i+1][j],dist[i][j]+city[i-1][j]);
			dist[i][j+1]=dist[i][j]+city[i][j+1];
			
		}
		else if(dist[i][j+1]>dist[i][j]+city[i][j+1]){
			dist[i][j+1]=dist[i][j]+city[i][j+1];
			set_and_update(i,j+1);
		}
	}
	
}
main(){
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			scanf("%d",&city[i][j]);
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			//printf("Now into func with i=%d j=%d\n",i,j);
			set_and_update(i,j);
			//printf("%d ",dist[i][j]);
		}
		//printf("\n");
	}
	dist[0][0]=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			//set_and_update(i,j);
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
}
