//				29/3/2563
#include<bits/stdc++.h>
using namespace std;
int ans,s,posx,posy;
int zone[30][30];
void move(int i,int j){
	ans=max(ans,zone[i][j]);
	//printf("Entering (%d,%d) with temperature %d now ans is %d\n",i,j,zone[i][j],ans);
	if(i>0){
		if(zone[i-1][j]!=100&&zone[i-1][j]>zone[i][j]) move(i-1,j);
	}
	if(j>0){
		if(zone[i][j-1]!=100&&zone[i][j-1]>zone[i][j]) move(i,j-1);
	}
	if(j<s-1){
		if(zone[i][j+1]!=100&&zone[i][j+1]>zone[i][j]) move(i,j+1);
	}
	if(i<s-1){
		if(zone[i+1][j]!=100&&zone[i+1][j]>zone[i][j]) move(i+1,j);
	}
}
main(){
	scanf("%d",&s);
	scanf("%d %d",&posy,&posx);
	posx--;
	posy--;
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			scanf("%d",&zone[i][j]);
		}
	}
	//printf("Starting pos: i=%d j=%d\n",posx,posy);
	move(posx,posy);
	printf("%d",ans);
}
