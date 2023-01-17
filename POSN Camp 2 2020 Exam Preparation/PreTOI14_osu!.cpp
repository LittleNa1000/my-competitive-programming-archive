//				31/5/2563 //DON'T PUSH PQ IN DEST NODE
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ip;
typedef pair<int,ip> p;
short int revisited[10005];//16 then -1
vector<ip> edge[10005];
bool succ;
priority_queue<p,vector<p>,greater<p> > pq;
int V,E,t,start,dest,temp,temp1,temp2,u,dist,click;
main(){
	scanf("%d %d %d %d %d",&V,&E,&t,&start,&dest);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp-1].push_back({temp1-1,temp2});
	}
	pq.push({0,{start-1,1}});	revisited[start-1]=1;
	for(;!pq.empty();){
		u=pq.top().second.first;	dist=pq.top().first;    click=pq.top().second.second;
		pq.pop();
		revisited[u]++;
		if(u==dest-1&&click%t==0){
			printf("%d",dist);
			succ=1;
			break;
		}
		if(revisited[u]==100) break;
		for(int i=0;i<edge[u].size();i++){
			pq.push({edge[u][i].second+dist,{edge[u][i].first,click+1}});
		}
	}
	if(!succ) printf("-1");
}
