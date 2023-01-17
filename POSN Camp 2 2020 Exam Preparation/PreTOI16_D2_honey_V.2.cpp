//				17/5/2563	//ADDED VISITED SYSTEM
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,bool> > p;
vector<int> dist(100005,INT_MAX);
vector< pair<int,int> > edge[100005];
priority_queue<p,vector<p>,greater<p> > pq;
int V,E,k,t,u,temp,temp1,temp2;
bool use_copter;
main(){
	dist[0]=0;
	scanf("%d %d %d %d",&V,&E,&k,&t);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp-1].push_back({temp2,temp1-1});
		edge[temp1-1].push_back({temp2,temp-1});
	}
	for(int i=0;i<edge[0].size();i++){
		if(edge[0][i].first>k){
			pq.push({k,{edge[0][i].second,1}});
		}
		pq.push({edge[0][i].first,{edge[0][i].second,0}});
	}
	while(!pq.empty()){
		u=pq.top().second.first;
		use_copter=pq.top().second.second;
		//printf("Now visiting %d: with edge %d and use_copter=%d pqsize=%d\n",u+1,pq.top().first,use_copter,pq.size()-1);
		dist[u]=min(dist[u],pq.top().first);
		pq.pop();
		for(int i=0;i<edge[u].size();i++){
			if(!use_copter&&edge[u][i].first>k){
				if(dist[u]+k<dist[edge[u][i].second]){
					//printf("push {%d,{%d,%d}} to pq  ",dist[u]+k,edge[u][i].second,1);
					pq.push({dist[u]+k,{edge[u][i].second,1}});
				}
			}
			if(dist[u]+edge[u][i].first<dist[edge[u][i].second]){
				//printf("push {%d,{%d,%d}} to pq  ",dist[u]+edge[u][i].first,edge[u][i].second,0);
				pq.push({dist[u]+edge[u][i].first,{edge[u][i].second,0}});
			}
		}
	}
	if(dist[V-1]<=t) printf("Happy Winnie the Pooh :3\n%d",dist[V-1]);
	else printf("No Honey TT");
}
