//				30/8/2563
#include<bits/stdc++.h>
using namespace std;
/*struct Node{
	long long x,y;
	stack<long long> z;
};*/
typedef pair<long long,long long> pii;
typedef pair<long long,pair<long long,stack<int> > > Node;
/*bool operator<(const Node &n,const Node &m){
	return n.x<m.x;
}*/
vector<pii> edge[100005];
bool parade[100005];
long long dist[100005]/*distC[100005]*/;
priority_queue<Node,vector<Node>,greater<Node> > pq;
priority_queue<pii,vector<pii>,greater<pii> > pqC;
long long V,E,u,v,w,a,b,c,d,di;
main(){
	scanf("%lld %lld",&V,&E);
	for(long long i=0;i<E;++i){
		scanf("%lld %lld %lld",&u,&v,&w);
		edge[u-1].push_back({w,v-1});
		edge[v-1].push_back({w,u-1});
	}
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	--a;  --b;  --c;  --d;
	parade[a]=1;   parade[b]=1;
	for(long long i=0;i<V;++i){
		dist[i]=LONG_LONG_MAX;
	}
	dist[a]=0;
	stack<int> path;
	pq.push({0,{a,path}});
	while(!pq.empty()){
		//u=pq.top().y;   di=pq.top().x;   path=pq.top().z;
		di=pq.top().first;   u=pq.top().second.first;   path=pq.top().second.second;
		pq.pop();
		if(u==b){
			path.pop();
			while(!path.empty()){
				parade[path.top()]=1;
				path.pop();
			}
		}
		else if(di<dist[b]){ //maybe <=
			for(long long i=0;i<edge[u].size();++i){
				if(di+edge[u][i].first<=dist[edge[u][i].second]){
					path.push(edge[u][i].second);
					dist[edge[u][i].second]=di+edge[u][i].first;
					pq.push({di+edge[u][i].first,{edge[u][i].second,path}});
					path.pop();
				}
			}
		}
	}
	//for(long long i=0;i<V;++i) printf("Node: %d=%d\n",i+1,parade[i]);
	while(!pq.empty()) pq.pop();
	for(int i=0;i<V;++i) dist[i]=LONG_LONG_MAX;
	dist[c]=0;
	pqC.push({0,c});
	while(!pqC.empty()){
		di=pqC.top().first;   u=pqC.top().second;
		pqC.pop();
		if(u==d) break;
		for(long long i=0;i<edge[u].size();++i){
			if(di+edge[u][i].first<dist[edge[u][i].second]&&!parade[edge[u][i].second]){
				dist[edge[u][i].second]=di+edge[u][i].first;
				pqC.push({dist[edge[u][i].second],edge[u][i].second});
			}
		}
	}
	if(dist[d]==LONG_LONG_MAX) printf("-1");
	else printf("%lld",di);
	
}
