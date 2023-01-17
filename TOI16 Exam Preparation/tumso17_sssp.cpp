//                      20/10/2563 maybe llu instead of lld
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<unsigned long long,int> pli;
vector<int> ans;
vector<pii> edge[100001];
priority_queue<pli,vector<pli>,greater<pli> > pq;
int V,E,s,t,u,v,w;
unsigned long long d;
bool visited[100001];
int par[100001];
unsigned long long dist[100001];
void find_path(int x){
    ans.push_back(x);
    if(par[x]==-1) return ;
    return find_path(par[x]);
}
int main(){
    scanf("%d %d %d %d",&V,&E,&s,&t);
    for(int i=0;i<V;++i) {
        dist[i]=ULONG_LONG_MAX;
    }
    dist[s]=1;
    par[s]=-1;
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    pq.push({1,s});
    while(!pq.empty()){
        d=pq.top().first;   u=pq.top().second;
        pq.pop();
        if(u==t){
            find_path(t);
            break;
        }
        if(visited[u]) continue;
        visited[u]=1;
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i].second;
            w=edge[u][i].first;
            if(!visited[v]&&d*w<dist[v]){
                dist[v]=d*w;
                par[v]=u;
                pq.push({d*w,v});
            }
        }
    }
    for(int i=ans.size()-1;i>=0;--i){
        printf("%d ",ans[i]);
    }
}