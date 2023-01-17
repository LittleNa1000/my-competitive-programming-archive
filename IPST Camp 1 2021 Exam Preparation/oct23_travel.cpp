//                  18/1/2564 or BFS + lowest common ancestor
#include<bits/stdc++.h>//BFS only
using namespace std;
typedef pair<int,int> ii;
int x,source=1,V,u,v,t,ans,d;
vector<int> edge[30005];
int bfs(int s,int t){
    vector<bool> visited(V+1,0);
    queue<ii> q;
    q.push({0,s});
    while(!q.empty()){
        d=q.front().first;
        u=q.front().second;
        q.pop();
        if(visited[u]) continue;
        visited[u]=1;
        if(u==t){
            //printf("%d %d %d\n",s,t,d);
            return d;
        }
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i];
            if(!visited[v]){
                q.push({d+1,v});
            }
        }
    }
}
int main(){
    scanf("%d",&V);
    for(int i=0;i<V-1;++i){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&x);
        ans+=bfs(source,x);
        source=x;
    }
    printf("%d",ans);
}