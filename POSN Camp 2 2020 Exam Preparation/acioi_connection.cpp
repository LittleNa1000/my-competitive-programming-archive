//				6/4/2563
#include<bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> edge[1005];
int level[1005];
bool visited[1005];
int x,ans,temp,temp1,V,E,k,result;
void bfs(int source){
	//printf("Round %d\n",source);
	q.push(source);
	while(!q.empty()){
		x=q.front();
		q.pop();
		//printf("Front is %d size is %d Level = %d Visited = %d\n",x,edge[x].size(),level[x],visited[x]);
		visited[x]=1;
		if(level[x]==k) break;
		for(int i=0;i<edge[x].size();i++){
			if(!visited[edge[x][i]]){
				q.push(edge[x][i]);
				if(level[edge[x][i]]==0) level[edge[x][i]]=level[x]+1;
				result++;
				visited[edge[x][i]]=1;
				//printf("-Add %d to q with level=%d\n",edge[x][i],level[edge[x][i]]);
			}
		}
		
	}
	//printf("Result=%d\n",result);
	if(ans<result) ans=result;
}
main(){
	scanf("%d %d %d",&V,&E,&k);
	for(int i=0;i<E;i++){
		scanf("%d %d",&temp,&temp1);
		edge[temp].push_back(temp1);
		edge[temp1].push_back(temp);
	}
	for(int i=0;i<V;i++){
		result=1;
		bfs(i);
		while(!q.empty()) q.pop();
		for(int j=0;j<1005;j++){
			visited[j]=0;
			level[j]=0;
		}
	}
	printf("%d",ans);
}
