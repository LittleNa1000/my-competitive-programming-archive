//				15/5/2563		OR INITIAL 2D ARRAY WITH INT_MAX / ADD VISITED BOOLEAN
#include<bits/stdc++.h>
using namespace std;
short int n,m,cost[1005][1005],i,j;
int dist[1005][1005],c;
typedef pair<int,pair<short int,short int> > p;
priority_queue<p,vector<p>,greater<p> > pq;
p x;
main(){
	scanf("%hd %hd",&n,&m);
	for(short int a=0;a<n;a++){
		for(short int b=0;b<m;b++){
			scanf("%hd",&cost[a][b]);
			dist[a][b]=INT_MAX;
		}
	}
	dist[0][0]=0;
	pq.push({0,{0,0}});
	while(c!=m*n){
		x=pq.top();
		pq.pop();
		i=x.second.first;		j=x.second.second;
		if(i>0&&dist[i][j]+cost[i-1][j]<dist[i-1][j]){
			dist[i-1][j]=dist[i][j]+cost[i-1][j];
			pq.push({dist[i-1][j],{i-1,j}});
		}
		if(i<n-1&&dist[i][j]+cost[i+1][j]<dist[i+1][j]){
			dist[i+1][j]=dist[i][j]+cost[i+1][j];
			pq.push({dist[i+1][j],{i+1,j}});
		}
		if(j>0&&dist[i][j]+cost[i][j-1]<dist[i][j-1]){
			dist[i][j-1]=dist[i][j]+cost[i][j-1];
			pq.push({dist[i][j-1],{i,j-1}});
		}
		if(j<m-1&&dist[i][j]+cost[i][j+1]<dist[i][j+1]){
			dist[i][j+1]=dist[i][j]+cost[i][j+1];
			pq.push({dist[i][j+1],{i,j+1}});
		}
		c++;
	}
	for(short int a=0;a<n;a++){
		for(short int b=0;b<m;b++) printf("%d ",dist[a][b]);
		printf("\n");
	}
}
