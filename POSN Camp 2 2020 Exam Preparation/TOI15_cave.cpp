//				4/6/2563 // ARR OF PQ // WoT: vector v pq // al q
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
int V,start,dest,E,h,temp,temp1,temp2,dist,u,t;
vector<p> edge[2005];

int visited[2005];
main(){
	scanf("%d %d %d %d",&V,&start,&dest,&E);
	
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp].push_back({temp2,temp1});
	}
	scanf("%d",&t);
	for(int r=1;r<=t;r++){
		scanf("%d",&h);
		vector<int> v;
		for(int i=0;i<V;i++) v.push_back(INT_MAX);
		v[start]=0;
		priority_queue<p,vector<p>,greater<p> > pq;
		pq.push({0,start});
		while(!pq.empty()){
			u=pq.top().second;   dist=v[u];
			pq.pop();
			//printf("VISITING #%d with dist=%d\n",u,dist);
			if(u==dest) break;
			visited[u]=r;
			for(int i=0;i<edge[u].size();i++){
				if(visited[edge[u][i].second]!=r){
					if((u==start||edge[u][i].second==start)&&dist+edge[u][i].first<v[edge[u][i].second]){
						v[edge[u][i].second]=dist+edge[u][i].first;
						pq.push({v[edge[u][i].second],edge[u][i].second});
					}
					else if(dist+edge[u][i].first+h<v[edge[u][i].second]){
						v[edge[u][i].second]=dist+edge[u][i].first+h;
						pq.push({v[edge[u][i].second],edge[u][i].second});
					}
				}
			}
		}
		//for(int i=0;i<V;i++) v[i]=INT_MAX;
		printf("%d ",dist);
	}
}
