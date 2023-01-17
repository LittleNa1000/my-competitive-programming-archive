#include<bits/stdc++.h>
using namespace std;
int area,maxarea; //Continents
int m,n;
string region[40];
void main_land(int i,int j){
	if(region[i][j]!='l') return ;
	region[i][j]='m';
	if(i>0) main_land(i-1,j);
	if(i<m-1) main_land(i+1,j);
	if(j>0) main_land(i,j-1);
	if(j<n-1) main_land(i,j+1);
	if(j==0) main_land(i,n-1);
	if(j==n-1) main_land(i,0);
	//
	if(i>0&&j>0) main_land(i-1,j-1);
	if(i>0&&j<n-1) main_land(i-1,j+1);
	if(i<m-1&&j>0) main_land(i+1,j-1);
	if(i<m-1&&j<n-1) main_land(i+1,j+1);
	if(i>0&&j==0) main_land(i-1,n-1);
	if(i>0&&j==n-1) main_land(i-1,0);
	if(i<m-1&&j==0) main_land(i+1,n-1);
	if(i<m-1&&j==n-1) main_land(i+1,0);
}
void expand_continent(int i,int j){
	if(region[i][j]!='l') return ;
	area++;
	region[i][j]='v';
	if(i>0) expand_continent(i-1,j);
	if(i<m-1) expand_continent(i+1,j);
	if(j>0) expand_continent(i,j-1);
	if(j<n-1) expand_continent(i,j+1);
	if(j==0) expand_continent(i,n-1);
	if(j==n-1) expand_continent(i,0);
	if(i>0&&j>0) expand_continent(i-1,j-1);
	if(i>0&&j<n-1) expand_continent(i-1,j+1);
	if(i<m-1&&j>0) expand_continent(i+1,j-1);
	if(i<m-1&&j<n-1) expand_continent(i+1,j+1);
	if(i>0&&j==0) expand_continent(i-1,n-1);
	if(i>0&&j==n-1) expand_continent(i-1,0);
	if(i<m-1&&j==0) expand_continent(i+1,n-1);
	if(i<m-1&&j==n-1) expand_continent(i+1,0);
}
main(){
	while(scanf("%d %d",&m,&n)==2){ // M = Line
		for(int i=0;i<m;i++){
			cin>>region[i];
		}
		int m1,n1;
		scanf("%d %d",&m1,&n1);
	maxarea=0;
	//printf("Begin process\n");
	main_land(m1,n1);
	//printf("Begin finding the largeset continent\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(region[i][j]=='l'){
				area=0;
				expand_continent(i,j);
				if(area>maxarea){
					maxarea=area;
				}
				
			}
		}
	}
	printf("%d\n",maxarea);}
}
