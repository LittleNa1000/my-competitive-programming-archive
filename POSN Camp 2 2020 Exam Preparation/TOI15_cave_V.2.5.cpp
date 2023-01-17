//				4/6/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
int V,start,dest,E,h,temp,temp1,temp2,dist,u,t,pass,ans;
vector<p> edge[2005];
vector<bool> v;
struct Node{
	int cur,d,ps;
	vector<bool> visited;
};
queue<struct Node> q;
int path[2005];
main(){
	scanf("%d %d %d %d",&V,&start,&dest,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp].push_back({temp2,temp1});
	}
	vector<bool> b(V,0);
	q.push({0,0,0,b});
	while(!q.empty()){
		u=q.front().cur;	dist=q.front().d;    pass=q.front().ps;    v=q.front().visited;
		q.pop();
		if(u==dest){
			if(path[pass]==0) path[pass]=dist;
			else if(path[pass]>dist) path[pass]=dist;
		}
		else{
			v[u]=1;
			for(int i=0;i<edge[u].size();i++){
				if(!v[edge[u][i].second]){
					q.push({edge[u][i].second,dist+edge[u][i].first,pass+1,v});
				}
			}
		}
	}
	scanf("%d",&t);
	for(int i=0;i<V;i++){
		printf("dist=%d node visited=%d \n",path[i],i);
	}
	while(t--){
		scanf("%d",&h);
		ans=INT_MAX;
		for(int i=0;i<V;i++){
			if(path[i]!=0) ans=min(ans,path[i]+((i-1)*h));
		}
		printf("%d ",ans);
	}
}
