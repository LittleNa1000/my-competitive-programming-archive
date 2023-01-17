//				10/8/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> edge[1000005];
int tc,V,E,temp,temp1,u;
queue<int> q;
int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&V,&E);
		vector<bool> ban(V,0);
		set<int> ans;
		ban[1]=1;
		for(int i=0;i<E;++i){
			scanf("%d %d",&temp,&temp1);
			edge[temp-1].push_back(temp1-1);
			edge[temp1-1].push_back(temp-1);
			if(temp-1==1){
				ban[temp1-1]=1;
				q.push(temp1-1);
			}
			else if(temp1-1==1){
				ban[temp-1]=1;
				q.push(temp-1);
			}
		}
		while(!q.empty()){
			u=q.front();	q.pop();
			if(u!=0){
				for(int i=0;i<edge[u].size();++i){
					ban[edge[u][i]]=1;
				}
			}
		}
		for(int i=0;i<edge[0].size();++i){
			if(!ban[edge[0][i]]){
				ans.insert(edge[0][i]+1);
			}
		}
		if(ans.empty()) printf("-1");
		else{
			for(set<int>::iterator i=ans.begin();i!=ans.end();++i) printf("%d ",*i);
		}
		printf("\n");
		for(int i=0;i<V;++i) edge[i].clear();
	}
}
