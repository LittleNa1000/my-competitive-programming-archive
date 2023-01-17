//				31/5/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ip;
typedef pair<long long int,ip> p;
bool visited[10005][100];
long long int dist[10005][100];
vector<ip> edge[10005];
priority_queue<p,vector<p>,greater<p> > pq;
int V,E,t,start,dest,temp,temp1,temp2,u,click,w,v;
long long int d;
bool vst,ptq;
main(){
	scanf("%d %d %d %d %d",&V,&E,&t,&start,&dest);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp-1].push_back({temp1-1,temp2});
	}
	for(int i=0;i<V;++i){
		for(int j=1;j<=100;++j) dist[i][j]=LLONG_MAX;
	}
	pq.push({0,{start-1,1}});
	while(!pq.empty()){
		u=pq.top().second.first;	d=pq.top().first;    click=pq.top().second.second;
		pq.pop();
		vst=1;
		for(int i=1;i<=100;++i){
			if(click%i==0&&!visited[u][i]){
				vst=0;
				visited[u][i]=1;
			}
		}
		if(vst) continue;
		//printf("Visiting %d (d=%d, click=%d)\n",u+1,d,click);
		if(u==dest-1&&click%t==0){
			printf("%lld",d);
			return 0;
		}
		for(int i=0;i<edge[u].size();i++){
			v=edge[u][i].first;
			w=edge[u][i].second;
			ptq=0;
			for(int j=1;j<=100;++j){
				if(!visited[v][j]&&click%j==0&&dist[v][j]>d+w){
					ptq=1;
					dist[v][j]=d+w;
				}
			}
			if(ptq){
				pq.push({w+d,{v,click+1}});
			}
		}
	}
	printf("-1");
}

