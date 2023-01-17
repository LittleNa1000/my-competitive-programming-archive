//				10/5/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> dist(105,INT_MAX-10000);
vector< pair<int,pair<int,int> > > edge;
int V,E,s,temp,temp1,temp2;
bool update;
void print_v(){
	for(int i=0;i<V;i++){
		printf("%d ",dist[i]);
	}
}
main(){
	scanf("%d %d %d",&V,&E,&s);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge.push_back({temp2,{temp,temp1}});
	}
	dist[s]=0;
	for(int i=0;i<V;i++){
		update=0;
		for(int j=0;j<edge.size();j++){
			if(dist[edge[j].second.first]+edge[j].first<dist[edge[j].second.second]){
				dist[edge[j].second.second]=dist[edge[j].second.first]+edge[j].first;
				update=1;
			}
		}
		print_v();
		if(!update){
			print_v();
			break;
		}
		if(i+1==V){
			if(update) printf("-1");
			else print_v();
		}
	}
}
