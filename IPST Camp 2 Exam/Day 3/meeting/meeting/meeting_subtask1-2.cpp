#include<bits/stdc++.h>
#include "meeting.h"

using namespace std;
struct E{
	int u,d;
};
priority_queue<E> pq;
vector<E> edge[1005];
bool operator<(const E &a,const E &b){
	return a.d>b.d;
}
int mn,dist[1005][1005],u,d,v,w;
bool vst[1005][1005];
void dijkstra(int src,int idx){
	priority_queue<E> pq;
	dist[src][idx]=0;
	pq.push({src,0});
	while(!pq.empty()){
		u=pq.top().u;
		d=pq.top().d;
		pq.pop();
		if(vst[u][idx]) continue;
		vst[u][idx]=1;
		for(int i=0;i<edge[u].size();++i){
			v=edge[u][i].u;
			w=edge[u][i].d;
			if(!vst[v][idx]&&d+w<dist[v][idx]){
				dist[v][idx]=d+w;
				pq.push({v,d+w});
			}
		}
	}
}
vector<int> best_meeting(int N, int Q,
			 vector<vector<int>>& roads,
			 vector<int>& lengths,
			 vector<int>& a,
			 vector<int>& b,
			 vector<int>& c){
	vector<int> ans;
	for(int i=0;i<N-1;++i){
		edge[roads[i][0]].push_back({roads[i][1],lengths[i]});
		edge[roads[i][1]].push_back({roads[i][0],lengths[i]});
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			dist[i][j]=INT_MAX;
		}
		
	}
	for(int i=0;i<N;++i){
		dijkstra(i,i);
	}
	for(int q=0;q<Q;++q){
		mn=INT_MAX;
		for(int i=0;i<N;++i){
			mn=min(mn,max(dist[i][a[q]],max(dist[i][b[q]],dist[i][c[q]])));
		}
		ans.push_back(mn);
	}
  	
  	return ans;
}
