//				13/5/2563 WIP
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
vector<int> dist(10005,INT_MAX),dist2(10005,INT_MAX);
bool visited[10005],visited2[10005];
int pickup,V,E,temp,temp1,temp2,V2,start,destination,budget,mn,idx,V3,pickupdist=INT_MAX;
vector<p> edge[10005];
main(){
	scanf("%d %d",&V,&E);
	scanf("%d %d %d",&start,&destination,&budget);
	dist[start]=0;			V2=V;
	dist2[destination]=0;	V3=V;
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		edge[temp].push_back({temp1,temp2});
		edge[temp1].push_back({temp,temp2});
	}
	while(V2--){
		mn=INT_MAX;
		for(int i=0;i<V;i++){
			if(mn>dist[i]&&!visited[i]){
				mn=dist[i];
				idx=i;
			}
		}
		visited[idx]=1;
		for(int i=0;i<edge[idx].size();i++){
			if(dist[idx]+edge[idx][i].second<dist[edge[idx][i].first]){
				dist[edge[idx][i].first]=dist[idx]+edge[idx][i].second;
			}
		}
	}
	while(V3--){
		mn=INT_MAX;
		for(int i=0;i<V;i++){
			if(mn>dist2[i]&&!visited2[i]){
				mn=dist2[i];
				idx=i;
			}
		}
		visited2[idx]=1;
		for(int i=0;i<edge[idx].size();i++){
			if(dist2[idx]+edge[idx][i].second<dist2[edge[idx][i].first]){
				dist2[edge[idx][i].first]=dist2[idx]+edge[idx][i].second;
			}
		}
	}
	if(dist[destination]<=budget) printf("%d %d 0",destination,dist[destination]);
	else{
		for(int i=0;i<V;i++){
			if(dist[i]<=budget){
				if(pickupdist>dist2[i]){
					pickup=i;
					pickupdist=dist2[i];
				}
			}
		}
		printf("%d %d %d",pickup,dist[pickup],pickupdist);
	}
}
