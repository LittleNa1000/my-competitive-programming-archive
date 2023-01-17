//				22/6/2563 //COMPARE BTW (start->dest) vs. (start->s_u)+(s_v->dest)
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
bool visited[1005],visited2[1005];
priority_queue<p,vector<p>,greater<p> > pq;
vector<p> edge[1005];
int V,E,start,dest,s_u,s_v,s_w,s_a,temp,temp1,temp2,d,u,x,y=INT_MAX;
main(){
	scanf("%d %d %d %d %d %d %d %d",&V,&E,&start,&dest,&s_u,&s_v,&s_w,&s_a);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp].push_back({temp2,temp1});
	}
	vector<int> dist(V,INT_MAX);
	dist[start]=0;   visited[start]=1;
	for(int i=0;i<edge[start].size();i++){
		dist[edge[start][i].second]=edge[start][i].first;
		pq.push({edge[start][i].first,edge[start][i].second});
	}
	while(!pq.empty()){
		d=pq.top().first;    u=pq.top().second;
		pq.pop();
		if(!visited[u]){
			visited[u]=1;
			for(int i=0;i<edge[u].size();i++){
				if(dist[edge[u][i].second]>d+edge[u][i].first&&!visited[edge[u][i].second]){//maybe >=
					dist[edge[u][i].second]=d+edge[u][i].first;
					pq.push({d+edge[u][i].first,edge[u][i].second});
				}
			}
		}
	}
	//for(int i=0;i<dist.size();++i) printf("st_%d\n",dist[i]);
	if(start!=s_v){
		vector<int> dist2(V,INT_MAX);
		dist2[s_v]=0;    visited2[s_v]=1;
		for(int i=0;i<edge[s_v].size();i++){
			dist2[edge[s_v][i].second]=edge[s_v][i].first;
			pq.push({edge[s_v][i].first,edge[s_v][i].second});
		}
		while(!pq.empty()){
			d=pq.top().first;    u=pq.top().second;
			pq.pop();
			if(!visited2[u]){
				visited2[u]=1;
				for(int i=0;i<edge[u].size();i++){
					if(dist2[edge[u][i].second]>d+edge[u][i].first&&!visited2[edge[u][i].second]){//maybe >=
						dist2[edge[u][i].second]=d+edge[u][i].first;
						pq.push({d+edge[u][i].first,edge[u][i].second});
					}
				}
			}
		}
		//for(int i=0;i<dist.size();++i) printf("s_v%d\n",dist2[i]);	
		if(dist[s_u]<=s_a) y=dist[s_u]+dist2[dest]+s_w;
	}
	else{
		if(dist[s_u]<=s_a) y=dist[s_u]+dist[dest]+s_w;
	}
	x=dist[dest];
	printf("%d",min(x,y));
}
