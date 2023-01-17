//				9/8/2563 maybe DP , visited array
#include<bits/stdc++.h>
using namespace std;
int mincost[305][305],x,i,j,n,m,arr[305][305];
typedef pair<int,pair<int,int> > iii;
priority_queue<iii,vector<iii>,greater<iii> > pq;
int main(){
	scanf("%d %d",&n,&m);
	for(int a=0;a<n;++a){
		for(int b=0;b<m;++b){
			scanf("%d",&arr[a][b]);
			mincost[a][b]=INT_MAX;
		}
	}
	mincost[0][0]=0;
	pq.push({0,{0,0}});
	while(!pq.empty()){
		x=pq.top().first;   i=pq.top().second.first;    j=pq.top().second.second;
		pq.pop();
		if(i==n-1&&j==m-1) break;
		if(i>0&&mincost[i-1][j]>max(x,abs(arr[i][j]-arr[i-1][j]))){
			mincost[i-1][j]=max(x,abs(arr[i][j]-arr[i-1][j]));
			pq.push({mincost[i-1][j],{i-1,j}});
		}
		if(j<m-1&&mincost[i][j+1]>max(x,abs(arr[i][j]-arr[i][j+1]))){
			mincost[i][j+1]=max(x,abs(arr[i][j]-arr[i][j+1]));
			pq.push({mincost[i][j+1],{i,j+1}});
		}
		if(i<n-1&&mincost[i+1][j]>max(x,abs(arr[i][j]-arr[i+1][j]))){
			mincost[i+1][j]=max(x,abs(arr[i][j]-arr[i+1][j]));
			pq.push({mincost[i+1][j],{i+1,j}});
		}
		if(j>0&&mincost[i][j-1]>max(x,abs(arr[i][j]-arr[i][j-1]))){
			mincost[i][j-1]=max(x,abs(arr[i][j]-arr[i][j-1]));
			pq.push({mincost[i][j-1],{i,j-1}});
		}
	}
	printf("%d",x);
}
