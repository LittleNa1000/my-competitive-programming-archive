//				26/3/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

vector<int> dist; //Distance from start node to all nodes
vector<int>::iterator it;
int mn,V,E,k,u,v,temp,temp1,temp2;
vector<p> edge[105];


void initial(int source){
	int i=0;
	//printf("Initializing vector dist with source=%d i=%d\n",source,i);
	for(i=0;i<V;i++){
		//printf("Entering Loop\n");
		dist.push_back(INT_MAX);
		//printf("dist[%d] = %d\n",i,dist[i]);
	}
	dist[source]=0;
	//printf("dist source = %d\n",dist[source]);
}
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2); // start, destination, weight
		edge[temp-1].push_back(make_pair(temp1-1,temp2));
		edge[temp1-1].push_back(make_pair(temp-1,temp2));
	}
	scanf("%d",&k);
	while(k--){
		vector<bool> visited(105,0);
		scanf("%d %d",&u,&v);
		u--;
		v--;
		initial(u);
		//printf("Enter dijkstra algo\n");
		for(int i=0;i<V;i++){
			
			it=min_element(dist.begin(),dist.end());
			mn=it-dist.begin();
			//printf("min element is %d index is %d\n",*it,mn);
			if(dist[mn]==INT_MAX){
				break;
			}
			if(mn==v){
				printf("%d\n",dist[mn]);
				break;
			}
			visited[mn]=1;
			for(int j=0;j<edge[mn].size();j++){
				if(dist[mn]+edge[mn][j].second<dist[edge[mn][j].first]&&!visited[edge[mn][j].first]){
					//printf("Relax dist[%d] from %d to %d\n",edge[mn][j].first,dist[edge[mn][j].first],dist[mn]+edge[mn][j].second);
					dist[edge[mn][j].first]=dist[mn]+edge[mn][j].second;
				}
			}
			//dist.erase(it);
			dist[mn]=INT_MAX;
		}
		if(dist[v]==INT_MAX) printf("-1\n");
		dist.clear();
		//visited.clear();
		//else printf("Something's wrong, I can feel it\n");
	}
}
