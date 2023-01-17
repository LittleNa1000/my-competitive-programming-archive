//				8/6/2563
#include<bits/stdc++.h>
using namespace std;
bool visited[500005],in_cycle[500005];
vector<int> edge[500005];
vector<int> v;
int ans[500005];
int E,source,temp,temp1,mx=INT_MIN,ans_n;
void dfs(int u){
	visited[u]=1;
	//printf("Visited: %d\n",u+1);
	for(int i=0;i<edge[u].size();i++){
		if(!visited[edge[u][i]]){
			v.push_back(edge[u][i]);
			dfs(edge[u][i]);
			//if(!in_cycle[edge[u][i]]) printf("Update ans[%d] from %d to %d\n",u+1,ans[u],ans[u]+ans[edge[u][i]]+1);
			if(!in_cycle[edge[u][i]]) ans[u]=ans[u]+ans[edge[u][i]]+1;
		}
		else if(edge[u][i]==source&&v.size()>2){
			for(int j=1;j<v.size();j++){
				in_cycle[v[j]]=1;
			}
		}
	}
	v.pop_back();
}
main(){
	scanf("%d %d",&E,&source);
	source--;	
	in_cycle[source]=1;
	for(int i=0;i<E;i++){
		scanf("%d %d",&temp,&temp1);
		edge[temp-1].push_back(temp1-1);
		edge[temp1-1].push_back(temp-1);
	}
	v.push_back(source);
	//printf("s%d\n",source);
	dfs(source);
	for(int i=0;i<E;i++){
		if(i!=source){
			if(mx<ans[i]){
				mx=ans[i];
				ans_n=i;
			}
		}
	}
	printf("%d\n%d",ans_n+1,ans[ans_n]);
}
