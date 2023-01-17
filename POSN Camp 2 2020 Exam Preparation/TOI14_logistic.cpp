//				18/7/2563 WIP Soving Method by lnwTum :: Print mincost[] instead
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> p;
vector<pii> edge[105];
priority_queue<p,vector<p>,greater<p> > pq;
int V,E,start,dest,fuelcap,temp,temp1,temp2,u,ticket,fuel,v,w;
long long int tcost;
int cost[105];
int mincost[105][105][3]; // [NODE][FUEL][ 0=NO TICKET  1=HAVE TICKET ] must be INT_MAX except start node
main(){
	scanf("%d",&V);
	for(int i=0;i<V;++i){
		scanf("%d",&cost[i]);
	}
	scanf("%d %d %d %d",&start,&dest,&fuelcap,&E);
	--start;   --dest;
	for(int i=0;i<E;++i){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp-1].push_back({temp2,temp1-1});
		edge[temp1-1].push_back({temp2,temp-1});
	}
	for(int i=0;i<V;++i){
		for(int j=0;j<fuelcap;++j){
			mincost[i][j][0]=INT_MAX;
			mincost[i][j][1]=INT_MAX;
		}	
	}
	mincost[start][0][1]=0;
	pq.push({{0,start},{0,1}}); //COST, CURRENT NODE, FUEL, HAVE_TICKET
	while(!pq.empty()){
		tcost=pq.top().first.first; u=pq.top().first.second; fuel=pq.top().second.first;  ticket=pq.top().second.second;
		pq.pop();
		if(u==dest&&fuel==fuelcap){
			break;
		}
		if(fuel!=fuelcap){
			pq.push({{tcost+cost[u],u},{fuel+1,ticket}});// update mincost
			//printf("Add Fuel: Cost=%d Node=%d Fuel=%d Ticket=%d\n",tcost+cost[u],u,fuel+1,ticket);
		}
		for(int i=0;i<edge[u].size();++i){
			v=edge[u][i].second;
			w=edge[u][i].first;
			if(fuel>=w&&mincost[v][fuel-w][ticket]>tcost){
				mincost[v][fuel-w][ticket]=tcost;
				pq.push({{tcost,v},{fuel-w,ticket}});
				//printf("Travel: Cost=%d Node=(%d->%d) Fuel=%d Ticket=%d\n",tcost,u,v,fuel-w,ticket);
			}
		}
		if(ticket){
			pq.push({{tcost,u},{fuelcap,0}});// update mincost
			//printf("Use ticket: Cost=%d Node=%d Fuel=%d Ticket=%d\n",tcost,u,fuelcap,0);
		}
	}
	printf("%lld",tcost);
}
