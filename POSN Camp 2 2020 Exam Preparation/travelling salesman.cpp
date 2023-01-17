//				14/8/2563 recursive
#include<bits/stdc++.h>
using namespace std;
int cost[25][25];
int n;
int f(int k,bool visited[],int sz){
	//printf("%d {%d,%d,%d,%d} %d\n",k,visited[0],visited[1],visited[2],visited[3],sz);
	if(sz==1){
		for(int i=0;i<n;++i){
			if(!visited[i]){
				return cost[k][i];
			}
		}
	}
	int mx=INT_MIN;
	for(int i=0;i<n;++i){
		if(!visited[i]){
			visited[i]=1;
			mx=max(mx,cost[k][i]+f(i,visited,sz-1));
			visited[i]=0;
		}
	}
	return mx;
}
main(){
	bool arr[25];
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		arr[i]=0;
		for(int j=0;j<n;++j){
			scanf("%d",&cost[i][j]);
		}
	}
	arr[0]=1;
	printf("%d",f(0,arr,n-1)); // array of visited
}
