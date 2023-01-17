//				15/6/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
typedef pair<int,p> pp;
int V,source,dest,E,temp,temp1,weight,t,ans,u,dist,pass,h;
vector<p> edge[2005];
bool visited[2005];
int path[2005];
priority_queue<pp,vector<pp>,greater<pp> > pq;
main(){
	scanf("%d %d %d %d",&V,&source,&dest,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&weight);
		edge[temp].push_back({weight,temp1});
	}
	pq.push({0,{source,0}});
	while(!pq.empty()){
		if(1){
			u=pq.top().second.first;   dist=pq.top().first;   pass=pq.top().second.second;
			if(u==dest){
				if(path[pass]==0||path[pass]>dist) path[pass]=dist;
			}
			else if(1){
			visited[u]=1;
				for(int i=0;i<edge[u].size();i++){
					if(!visited[edge[u][i].second]){
						pq.push({dist+edge[u][i].first,{edge[u][i].second,pass+1}});
					}
				}
			}
		}
		pq.pop();
	}
	scanf("%d",&t);
	/*for(int i=0;i<V;i++){
		printf("dist=%d node visited=%d \n",path[i],i);
	}*/
	while(t--){
		scanf("%d",&h);
		ans=INT_MAX;
		for(int i=0;i<V;i++){
			if(path[i]!=0) ans=min(ans,path[i]+((i-1)*h));
		}
		printf("%d ",ans);
	}
}
