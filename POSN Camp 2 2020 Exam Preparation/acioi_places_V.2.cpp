//			24/3/2563 	Adapted from warptech
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > edge; //dist,(first node,destination node)
priority_queue<edge> pq;
vector<int> mst_edge_dist,minion[200005];
int master[200005],V,E,temp,temp1,temp2;
long long ans;
bool form_a_cycle(int start,int destination){ // and update master[i] if doesn't form a cycle
	if(master[start]==master[destination]) return 1;
	int a=max(master[start],master[destination]) , b=min(master[start],master[destination]);
	for(int i=0;i<minion[a].size();i++){//update all master
		master[minion[a][i]]=b;
		if(b!=0) minion[b].push_back(minion[a][i]);
		//printf("master[%d] = %d\n",i,master[i]);
	}
	return 0;
}
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		pq.push(make_pair(temp2,make_pair(temp-1,temp1-1)));
		//pq.push(make_pair(temp2,make_pair(temp1-1,temp-1)));
		if(i<V){
			minion[i].push_back(i);
			master[i]=i;
		}
	}
	while(mst_edge_dist.size()<V-1){
		edge maxedge=pq.top();
		pq.pop();
		if(!form_a_cycle(maxedge.second.first,maxedge.second.second)){ // cycle=1 	no cycle=0
			
			mst_edge_dist.push_back(maxedge.first);
			ans+=maxedge.first-1;
//printf("Add edge #%d which goes from %d to %d with dist: %d\n",mst_edge_dist.size(),maxedge.second.first,maxedge.second.second,maxedge.first);
		}
	}
	/*for(int i=0;i<mst_edge_dist.size();i++){
		printf("Dist: %d \n",mst_edge_dist[i]);
	}*/
	/*for(int i=0;i<q;i++){
		scanf("%d",&d);
		printf("%d\n",mst_edge_dist[mst_edge_dist.size()-d]);
	}*/
	printf("%lld",ans);
}
