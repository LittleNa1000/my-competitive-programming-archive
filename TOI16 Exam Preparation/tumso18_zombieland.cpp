//				12/9/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int V,E,s,e,u,v,w,Q,di;
bool visited1[200005],visited2[200005],infect[200005],visited[200005];
vector<pii> g[200005];
int dist1[200005],dist2[200005],dist[200005];
priority_queue<pii,vector<pii>,greater<pii> > pq;
stack<int> st;
main(){
	scanf("%d %d %d %d",&V,&E,&s,&e);
	--s;   --e;
	for(int i=0;i<V;++i){
		dist1[i]=INT_MAX;
		dist2[i]=INT_MAX;
		dist[i]=INT_MAX;
	}
	dist1[s]=0;
	dist2[e]=0;
	for(int i=0;i<E;++i){
		scanf("%d %d %d",&u,&v,&w);
		g[u-1].push_back({w,v-1});
		g[v-1].push_back({w,u-1});
	}
	scanf("%d",&Q);
	pq.push({0,s});
	while(!pq.empty()){
		di=pq.top().first;   u=pq.top().second;
		pq.pop();
		if(visited1[u]) continue;
		visited1[u]=1;
		for(int i=0;i<g[u].size();++i){
			v=g[u][i].second;   w=g[u][i].first;
			if(di+w<dist1[v]&&!visited1[v]){
				dist1[v]=di+w;
				pq.push({di+w,v});
			}
		}
	}
	pq.push({0,e});
	while(!pq.empty()){
		di=pq.top().first;   u=pq.top().second;
		pq.pop();
		if(visited2[u]) continue;
		visited2[u]=1;
		for(int i=0;i<g[u].size();++i){
			v=g[u][i].second;   w=g[u][i].first;
			if(di+w<dist2[v]&&!visited2[v]){
				dist2[v]=di+w;
				pq.push({di+w,v});
			}
		}
	}
	for(int i=0;i<V;++i){
		//printf("%d %d %d ",dist1[i],dist2[i],dist1[e]);
		if(dist1[i]+dist2[i]==dist1[e]) infect[i]=1;
		//printf(" (%d,%d)\n",i+1,infect[i]);
	}
	while(Q--){
		priority_queue<pii,vector<pii>,greater<pii> > q;
		scanf("%d",&s);
		--s;
		dist[s]=0;
		q.push({0,s});
		while(!q.empty()){
			u=q.top().second;    di=q.top().first;
			q.pop();
			st.push(u);
			if(infect[u]) break;
			if(visited[u]) continue;
			visited[u]=1;
			for(int i=0;i<g[u].size();++i){
				v=g[u][i].second;   w=g[u][i].first;
				if(di+w<dist[v]&&!visited[v]){
					dist[v]=di+w;
					q.push({di+w,v});
				}
			}
		}
		printf("%d\n",di);
		while(!st.empty()){
			dist[st.top()]=INT_MAX;
			visited[st.top()]=0;
			st.pop();
		}
	}
}
