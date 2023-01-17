//      25/2/2564
#include<bits/stdc++.h>
using namespace std;
int V,E,u,v;
vector<int> edge[100005],ans;
int visited[100005];
bool dfs(int u){
    if(visited[u]) return 0;
    visited[u]=1;
    //printf("%d*\n",u);
    for(int j=0;j<edge[u].size();++j){
        v=edge[u][j];
        if(visited[v]==1){
            printf("no");
            return 1;
        }
        else if(visited[v]==0){
            if(dfs(v)) return 1;
        }
    }
    visited[u]=2;
    ans.push_back(u);
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;++i){
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
    }
    for(int i=1;i<=V;++i){
        if(visited[i]) continue;
        if(dfs(i)){
            return 0;
        }
    }
    for(int i=V-1;i>=0;--i){
        printf("%d\n",ans[i]);
    }
}