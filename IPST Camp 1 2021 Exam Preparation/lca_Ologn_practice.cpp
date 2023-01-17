#include<bits/stdc++.h>
using namespace std;
int V,E,Q,dp[100005][20],dep[100005];
float lgn;
vector<int> edge[100005];
void dfs(int u,int par){
    //
    if(par!=-1) dep[u]=dep[par]+1;
    if(par!=-1) dp[u][0]=par;
    for(int i=1;i<=lgn;++i){
        dp[u][i]=dp[dp[u][i-1]][i-1];
    }
    //
    for(int i=0;i<edge[u].size();++i){
        int v=edge[u][i];
        if(v!=par){
            dfs(v,u);
        }
    }
}
int lca(int u,int v){
    if(u==v) return u;
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=lgn;i>=0;--i){
        if(dep[dp[u][i]]>=dep[v]){
            u=dp[u][i];
        }
    }
    if(u==v) return u;
    for(int i=lgn;i>=0;--i){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return dp[u][0];
}
int main(){
    int u,v;
    scanf("%d %d %d",&V,&E,&Q);
    lgn=log2(V);
    for(int i=0;i<E;++i){
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        //edge[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=0;i<=V;++i){
        for(int j=0;j<=lgn;++j){
            printf("%d ",dp[i][j]);
        }
        printf("dep[%d] = %d \n",i,dep[i]);
    }
    while(Q--){
        scanf("%d %d",&u,&v);
        printf("lca(%d,%d) = %d\n",u,v,lca(u,v));
    }
}
/*
13 12 6
1 3
1 2
2 4
2 5
2 6
5 9
9 10
6 7
6 8
6 12
7 11
12 13
10 3
11 6
4 3
1 1
11 13
5 5
*/