//				6/9/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<long,long> ii;
long long V,E,u,v,w,a,b,c,d,shortest;
priority_queue<ii,vector<ii>,greater<ii> > pq,pq2; // maybe reuse pq but empty them 1st
long long dist[100005],dist2[100005];
vector<ii> edge[100005];
bool visited[100005],parade[100005];
bool dfs(long long w,long long s){
	if(s==b) return 1;
	bool returnvalue=0;
	for(long long i=0;i<edge[s].size();++i){
		if(w+edge[s][i].first<=shortest&&!visited[edge[s][i].second]){
			visited[edge[s][i].second]=1;
			returnvalue=max(returnvalue,dfs(w+edge[s][i].first,edge[s][i].second));
			visited[edge[s][i].second]=0;
		}
	}
	return parade[s]=returnvalue;
}
main(){
	scanf("%lld %lld",&V,&E);
	for(long long i=0;i<V;++i){
		dist[i]=LONG_LONG_MAX;
		dist2[i]=LONG_LONG_MAX;	
	}
	dist[a]=0;
	dist[c]=0;
	for(long long i=0;i<E;++i){
		scanf("%lld %lld %lld",&u,&v,&w);
		edge[u-1].push_back({w,v-1});
		edge[v-1].push_back({w,u-1});
	}
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	--a;   --b;    --c;   --d;
	parade[b]=1;
	parade[a]=1;
	pq.push({0,a});
	while(!pq.empty()){
		u=pq.top().second;     w=pq.top().first;
		pq.pop();
		//printf("(%d,%d)\n",w,u);
		if(u==b) break;
		for(long long i=0;i<edge[u].size();++i){
			if(w+edge[u][i].first<dist[edge[u][i].second]){
				dist[edge[u][i].second]=w+edge[u][i].first;
				pq.push({dist[edge[u][i].second],edge[u][i].second});
			}
		}
	}
	shortest=w;
	printf("%d\n",shortest);
	visited[a]=1;
	dfs(0,a);
	for(long long i=0;i<V;++i) printf("(%d,%d) ",i+1,parade[i]);
	printf("\n");
	pq2.push({0,c});
	if(parade[c]||parade[d]){
		printf("-1");
		return 0;
	}
	while(!pq2.empty()){
		w=pq2.top().first;    u=pq2.top().second;
		pq2.pop();
		if(u==d) break;
		for(long long i=0;i<edge[u].size();++i){
			if(w+edge[u][i].first<dist2[edge[u][i].second]&&!parade[edge[u][i].second]){
				dist2[edge[u][i].second]=w+edge[u][i].first;
				pq2.push({dist2[edge[u][i].second],edge[u][i].second});
			}
		}
	}
	if(dist2[d]==LONG_LONG_MAX) printf("-1");
	else printf("%lld",dist2[d]);
}
