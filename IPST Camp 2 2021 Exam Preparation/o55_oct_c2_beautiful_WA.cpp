//              6/5/2564
//      DFS
#include<bits/stdc++.h>
using namespace std;
int V,E,u,v,ans;
bool visited[10005];
vector<int> edge[10005];
void dfs(int u,int d){
    if(visited[u]) return ;
    visited[u]=1;
    for(int i=0;i<edge[u].size();++i){
        int v=edge[u][i];
        if(!visited[v]){
            dfs(v,d+1);
        }
        if(v==1){
            ans=max(ans,d+1);
        }
    }
}
int main(){
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;++i){
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    printf("%d",ans);
}