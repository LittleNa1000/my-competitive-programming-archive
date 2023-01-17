//				4/6/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
int V,start,dest,E,h,temp,temp1,temp2,dist,u,t,pass,ans;
vector<p> edge[2005];
set<int> s;
struct Node{
	int cur,d,ps;
	set<int> visited;
};
queue<struct Node> q;
vector<p> path;
main(){
	scanf("%d %d %d %d",&V,&start,&dest,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp].push_back({temp2,temp1});
	}
	q.push({0,0,0,s});
	while(!q.empty()){
		u=q.front().cur;	dist=q.front().d;    pass=q.front().ps;    s=q.front().visited;
		q.pop();
		if(u==dest){
			path.push_back({dist,pass});
		}
		else{
			s.insert(u);
			for(int i=0;i<edge[u].size();i++){
				if(s.find(edge[u][i].second)==s.end()){
					q.push({edge[u][i].second,dist+edge[u][i].first,pass+1,s});
				}
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&h);
		ans=INT_MAX;
		for(int i=0;i<path.size();i++){
			ans=min(ans,path[i].first+((path[i].second-1)*h));
		}
		printf("%d ",ans);
	}
}
