//				16/5/2563 PQ //VISITED SYSTEM , VALUE IN NODE
#include<bits/stdc++.h>//MAX PQ
using namespace std;
bool visited[2505];
int arr[2505];
typedef pair<int,int> p;
vector<p> edge[2505];
priority_queue<p> pq;//   Weight, Destination
int V,E,temp,temp1,temp2,start,destination,ppl,minedge,u,x;
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp-1].push_back({temp1-1,temp2});
		edge[temp1-1].push_back({temp-1,temp2});//		Destination, Weight
	}
	scanf("%d %d %d",&start,&destination,&ppl);
	start--;	destination--;	visited[start]=1;
	for(int i=0;i<edge[start].size();i++){
		arr[edge[start][i].first]=edge[start][i].second;
		pq.push({edge[start][i].second,edge[start][i].first});
	}
	while(!pq.empty()){
		u=pq.top().second;     minedge=pq.top().first;
		pq.pop();
		if(u==destination){
			break;
		}
		if(!visited[u]){
			visited[u]=1;
			for(int i=0;i<edge[u].size();i++){
				x=min(edge[u][i].second,minedge);
				if(!visited[edge[u][i].first]&&arr[edge[u][i].first]<x){ //maybe <=
					arr[edge[u][i].first]=x;
					pq.push({x,edge[u][i].first});
				}
			}
		}
		
	}
	//printf("%d\n",minedge);
	minedge--;
	printf("%.0f",ceil((float)ppl/(float)minedge));
}
