//      15/2/2564 or dp?
#include<bits/stdc++.h>
using namespace std;
int V,u,v,w[100005];
int dp[100005][2];
vector<int> edge[100005];
int dfs(int u,int par,bool pick){
    int sum0=0,sum1=0,v; //sum0 = don't pick    sum1 = pick
    //printf("visiting %d from %d ,%d\n",u,par,pick);
    if(edge[u].size()==1&&u!=0){
    	if(pick) return w[u];
    	return 0;
	}
	if(dp[u][pick]!=-1) return dp[u][pick];
	//printf("loop %d %d %d\n",u,par,pick);
    for(int i=0;i<edge[u].size();++i){
        v=edge[u][i];
        if(v!=par){
            if(pick){
            	//printf("dfs %d %d %d\n",v,u,0);
                sum1+=dfs(v,u,0);
            }
            //printf("dfs %d %d %d\n",v,u,1);
            sum0+=dfs(v,u,1);
        }
    }
    if(pick) sum1+=w[u];
    //printf("returning %d \n",max(sum1,sum0));
    return dp[u][pick]=max(sum1,sum0);
}
int main(){
    scanf("%d",&V);
    for(int i=0;i<V;++i){
        scanf("%d",&w[i]);
        dp[i][0]=-1;
        dp[i][1]=-1;
    }
    for(int i=0;i<V-1;++i){
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    //for(int i=0;i<V;++i){
    //	for(int j=0;j<edge[i].size();++j) printf("%d %d\n",i,edge[i][j]); printf("\n");}
    printf("%d",dfs(0,-1,1));
}
