//				15/6/2563 LAST EDITED: 4/7/2563 //SET EVERYTHING TO INT_MAX
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
typedef pair<int,p> pp;
int V,source,dest,E,temp,temp1,weight,t,ans,u,d,pass,h;
vector<p> edge[2005];
//bool visited[2005];
int mindist[2005],minpass[2005]; //mindist FIRST
int dist[2005][2005]; //maybe 2d vector constructor
priority_queue<pp,vector<pp>,greater<pp> > pq;
main(){
	scanf("%d %d %d %d",&V,&source,&dest,&E);
	for(int i=0;i<V;++i){
		if(i!=source) for(int j=0;j<V;++j) dist[i][j]=INT_MAX;
		mindist[i]=INT_MAX;
	}
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&weight);
		edge[temp].push_back({weight,temp1});
	}
	pq.push({0,{source,0}});
	while(!pq.empty()){
		u=pq.top().second.first;   d=pq.top().first;   pass=pq.top().second.second;
		pq.pop();
		if(u==dest){
			if(d<mindist[dest]||pass<minpass[dest]){
				if(d<dist[dest][pass]) dist[dest][pass]=d;
				if(d<mindist[dest]){
					mindist[dest]=d;
					minpass[dest]=pass;
				}
			}
		}
		else{
			for(int i=0;i<edge[u].size();i++){
				if(d+edge[u][i].first<mindist[edge[u][i].second]||pass+1<minpass[edge[u][i].second]){
					if(d+edge[u][i].first<dist[edge[u][i].second][pass+1]){
						dist[edge[u][i].second][pass+1]=d+edge[u][i].first;
						pq.push({d+edge[u][i].first,{edge[u][i].second,pass+1}});	
					}
					if(d+edge[u][i].first<mindist[edge[u][i].second]){
						mindist[edge[u][i].second]=d+edge[u][i].first;
						minpass[edge[u][i].second]=pass+1;
					}
				}
			}
		}
	}
	scanf("%d",&t);
	/*for(int i=0;i<V;i++){
		printf("\nFrom %d to %d: ",source,i);
		for(int j=0;j<V;++j) printf("(P%d,D%d) ",j,dist[i][j]);
	}*/
	while(t--){
		scanf("%d",&h);
		ans=INT_MAX;
		for(int i=1;i<V;i++){
			if(dist[dest][i]!=INT_MAX) ans=min(ans,dist[dest][i]+((i-1)*h));
		}
		printf("%d ",ans);
	}
}
