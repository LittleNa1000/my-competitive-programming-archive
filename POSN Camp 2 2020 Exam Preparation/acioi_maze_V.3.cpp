//				22/5/2563
#include<bits/stdc++.h>
using namespace std;//								F H S V
vector<short int> v(4,SHRT_MAX-2);
bool visited[75][75],fy;
struct info{
	short int pi,pj,d;
};
queue<struct info> q;
short int n,m,yi,yj,i,j,dist,mn,x;
char str[75][75];
main(){
	scanf("%hd %hd",&n,&m);
	for(short int a=0;a<n;a++){
		scanf("%s",&str[a]);
		if(!fy){
			for(short int b=0;b<m;b++){
				if(str[a][b]=='Y'){
					yi=a;	yj=b;
					fy=1;
				}
			}
		}
	}
	q.push({yi,yj,0});
	while(!q.empty()){
		i=q.front().pi;	j=q.front().pj;
		dist=q.front().d;
		q.pop();
		if(str[i][j]=='F'){
			v[0]=min(v[0],dist);
		}
		else if(str[i][j]=='H'){
			v[1]=min(v[1],dist);
		}
		else if(str[i][j]=='S'){
			v[2]=min(v[2],dist);
		}
		else if(str[i][j]=='V'){
			v[3]=min(v[3],dist);
		}
		if(!visited[i][j]){
			visited[i][j]=1;
			if(i>0&&str[i-1][j]!='#'&&!visited[i-1][j]) q.push({i-1,j,dist+1});
			if(j>0&&str[i][j-1]!='#'&&!visited[i][j-1]) q.push({i,j-1,dist+1});
			if(i<n-1&&str[i+1][j]!='#'&&!visited[i+1][j]) q.push({i+1,j,dist+1});
			if(j<m-1&&str[i][j+1]!='#'&&!visited[i][j+1]) q.push({i,j+1,dist+1});
		}
	}
	//printf("\n%hd %hd %hd %hd",v[0],v[1],v[2],v[3]);
	for(short int a=0;a<4;a++){
		mn=SHRT_MAX-1;
		for(short int b=0;b<4;b++){
			if(mn>v[b]){
				x=b;
				mn=v[b];
			}
		}
		if(x==0) printf("F ");
		else if(x==1) printf("H ");
		else if(x==2) printf("S ");
		else printf("V ");
		v[x]=SHRT_MAX;
	}
}
