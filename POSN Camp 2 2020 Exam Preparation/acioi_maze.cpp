//				8/4/2563 Last Edited<V.3>: 15/4/2563 MAKE A GENIUS PATH DECISION 
#include<bits/stdc++.h>
using namespace std;
char str[75][75],c,x; 
bool visited[75][75],found_y;
short int mn,m,n,v1[8],pos_i,pos_j; // 				F H S V
void clean(){
	for(int i=0;i<74;i++){
		for(int j=0;j<74;j++) visited[i][j]=0;
	}
}
void find_dist(char i,char j,short int dist){
	if(str[i][j]=='Y'){
		if(!v1[c]||v1[c]>dist) v1[c]=dist;
		return ;
	}
	visited[i][j]=1;
	//printf("c=%d (%d,%d) dist=%d\n",c,i,j,dist);
	if(j<pos_j&&i<pos_i){
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
	}
	else if(j==pos_j&&i<pos_i){
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		
	}
	else if(j>pos_j&&i<pos_i){
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
	}
	else if(j<pos_j&&i==pos_i){
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
	}
	else if(j>pos_j&&i==pos_i){
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
	}
	else if(j<pos_j&&i>pos_i){
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
	}
	else if(j==pos_j&&i>pos_i){
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
	}
	else if(j>pos_j&&i>pos_i){
		if(i>0){if(str[i-1][j]!='#'&&!visited[i-1][j]) find_dist(i-1,j,dist+1);} //North
		if(j>0){if(str[i][j-1]!='#'&&!visited[i][j-1]) find_dist(i,j-1,dist+1);} //West
		if(i<n-1){if(str[i+1][j]!='#'&&!visited[i+1][j]) find_dist(i+1,j,dist+1);} //South
		if(j<m-1){if(str[i][j+1]!='#'&&!visited[i][j+1]) find_dist(i,j+1,dist+1);} //East
	}
}
main(){
	scanf("%hd %hd",&n,&m);
	for(int i=0;i<n;i++){
		cin>>str[i];
		if(!found_y){
			for(int j=0;j<m;j++){
				if(str[i][j]=='Y'){
					pos_i=i;
					pos_j=j;
					found_y=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(str[i][j]=='H'){
				c=1;
				find_dist(i,j,0);
				clean();
			}
			else if(str[i][j]=='S'){
				c=2;
				find_dist(i,j,0);
				clean();
			}
			else if(str[i][j]=='F'){
				c=0;
				find_dist(i,j,0);
				clean();
			}
			else if(str[i][j]=='V'){
				c=3;
				find_dist(i,j,0);
				clean();
			}
		}
	}
	for(int i=0;i<4;i++){
		if(!v1[i]) v1[i]=SHRT_MAX-2;
		//printf("%d ",v1[i]);
	}
	for(int i=0;i<4;i++){
		mn=SHRT_MAX-1;
		for(int j=0;j<4;j++){
			if(mn>v1[j]){
				mn=v1[j];
				x=j;
			}
		}
		if(x==0) printf("F ");
		else if(x==1) printf("H ");
		else if(x==2) printf("S ");
		else printf("V ");
		v1[x]=SHRT_MAX;
	}
}
