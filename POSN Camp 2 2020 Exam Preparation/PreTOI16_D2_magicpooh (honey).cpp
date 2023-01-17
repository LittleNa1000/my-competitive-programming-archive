//				12/8/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,bool> > t;
int V,E,k,tl,u,v,w,dt;
bool have_copter;
int dist[100005][3];
priority_queue<t,vector<t>,greater<t> > pq;
vector< pair<int,int> > edge[100005];
int main(){
	scanf("%d %d %d %d",&V,&E,&k,&tl);
	for(int i=0;i<E;++i){
		scanf("%d %d %d",&u,&v,&w);
		edge[u-1].push_back({w,v-1});
		edge[v-1].push_back({w,u-1});
	}
	/*for(int i=0;i<V;++i){
		for(int j=0;j<edge[i].size();++j) printf("(%d,%d) ",edge[i][j].first,edge[i][j].second);
		printf("\n");	
	}*/
	for(int i=0;i<V;++i){
		dist[i][0]=INT_MAX;
		dist[i][1]=INT_MAX;
	}
	dist[0][0]=0;   dist[0][1]=0;
	pq.push({0,{0,1}});
	while(!pq.empty()){
		dt=pq.top().first;   u=pq.top().second.first;    have_copter=pq.top().second.second;
		pq.pop();
		//printf("%d u=%d %d\n",dt,u+1,have_copter);
		if(u==V-1) break;
		for(int i=0;i<edge[u].size();++i){
			if(dt+edge[u][i].first<dist[edge[u][i].second][have_copter]){
				dist[edge[u][i].second][have_copter]=dt+edge[u][i].first;
				pq.push({dt+edge[u][i].first,{edge[u][i].second,have_copter}});
			}
			if(have_copter&&edge[u][i].first>k&&dt+k<dist[edge[u][i].second][0]){ // maybe &&d+k<dist[][1]
				dist[edge[u][i].second][0]=dt+k;
				pq.push({dt+k,{edge[u][i].second,0}});
			}
		}
	}
	if(dt<=tl&&u==V-1) printf("Happy Winnie the Pooh :3\n%d",dt);
	else printf("No Honey TT");
}
