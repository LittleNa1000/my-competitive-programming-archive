//				14/8/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int V,E,u,v,w,d,tc,x,y;
vector<pii> edge[105];
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;++i){
		scanf("%d %d %d",&u,&v,&w);
		edge[u-1].push_back({w,v-1});
		edge[v-1].push_back({w,u-1});
	}
	scanf("%d",&tc);
	while(tc--){
		int dist[105];
		scanf("%d %d",&x,&y);
		--x;   --y;
		for(int i=0;i<V;++i) dist[i]=INT_MAX;
		dist[x]=0;
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		pq.push({0,x});
		while(!pq.empty()){
			u=pq.top().second;   d=pq.top().first;
			//printf("visiting: %d\n",u);
			pq.pop();
			if(u==y) break;
			for(int i=0;i<edge[u].size();++i){
				if(d+edge[u][i].first<dist[edge[u][i].second]){
					dist[edge[u][i].second]=d+edge[u][i].first;
					pq.push({d+edge[u][i].first,edge[u][i].second});
				}
			}
		}
		if(dist[y]==INT_MAX) printf("-1\n");
		else printf("%d\n",d);
	}
	
}
