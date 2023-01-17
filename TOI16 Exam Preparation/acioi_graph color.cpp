//				22/8/2563
#include<bits/stdc++.h>
using namespace std;
int color[55];
bool b[55]; // maybe int b[]
int ans,V,E,u,v;
vector<int> edge[55];
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;++i){
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=0;i<V;++i){// maybe backtracking
		for(int j=0;j<edge[i].size();++j){
			b[color[edge[i][j]]]=1;
		}
		for(int j=1;j<=50;++j){
			if(!b[j]){
				ans=max(ans,j);
				color[i]=j;
				break;
			}
		}
		for(int j=1;j<=50;++j) b[j]=0;
	}
	printf("%d",ans);
}
