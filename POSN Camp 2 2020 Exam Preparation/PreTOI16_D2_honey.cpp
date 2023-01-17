//				9/5/2563
#include<bits/stdc++.h>
using namespace std;
int V,E,k,t,temp,temp1,temp2,source,s_mx;
long long int ans=LONG_MAX,tcost;
vector< pair<int,int> > v[505];
struct path{
	int u;
	long long int cost;
	int mx;
	bool visited[505];
};
struct path x;
queue<struct path> q;
void bfs(){
	while(!q.empty()){
		x=q.front();
		q.pop();
		source=x.u;
		//printf("s=%d\n",source);
		s_mx=x.mx;
		if(source==V-1){
			tcost=x.cost-x.mx+min(k,x.mx);
			//printf("tc%d\n",tcost);
			ans=min(ans,tcost);
		}
		else{
		x.visited[source]=1;
		for(int i=0;i<v[source].size();i++){
			if(!x.visited[v[source][i].first]){
				x.u=v[source][i].first;
				x.cost+=v[source][i].second;
				x.mx=max(s_mx,v[source][i].second);
				q.push(x);
				x.cost-=v[source][i].second;
			}
		}
		}
	}
}
main(){
	scanf("%d %d %d %d",&V,&E,&k,&t);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		v[temp-1].push_back({temp1-1,temp2});
		v[temp1-1].push_back({temp-1,temp2});
	}
	q.push({0,0,INT_MIN,{}});
	bfs();
	if(ans<=t) printf("Happy Winnie the Pooh :3\n%lld",ans);
	else printf("No Honey TT");
}
