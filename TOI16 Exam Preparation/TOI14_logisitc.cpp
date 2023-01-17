//TOI14 Logistic
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct node{
    int d,u,f;
    bool ht;
};
bool operator<(const node &a,const node &b){
    return a.d<b.d;
}
int V,u,v,w,s,d,t,cap,f,E;
bool ht;
vector<pii> edge[112];
bool visited[112][112][2];
int dist[112][112][2];
int fc[112];
priority_queue<node,vector<node>,greater<node> > pq;
int main(){
    scanf("%d",&V);
    for(int i=0;i<V;++i){
        scanf("%d",&fc[i]);
    }
    scanf("%d%d%d%d",&s,&t,&cap,&E);
    --s;
    --t;
    if(s==t){
        printf("0");
        return 0;
    }
    for(int i=0;i<E;++i){
        scanf("%d%d%d",&u,&v,&w);
        edge[u-1].push_back({v-1,w});
        edge[v-1].push_back({u-1,w});
    }
    for(int i=0;i<V;++i){
        for(int j=0;j<cap;++j){
            dist[i][j][0]=INT_MAX;
            dist[i][j][1]=INT_MAX;
        }
    }
    dist[s][0][1]=0;
    pq.push({0,s,0,1});
    while(!pq.empty()){
        d=pq.top().d;
        u=pq.top().u;
        f=pq.top().f;
        ht=pq.top().ht;
        pq.pop();
        if(u==t&&f==cap){
            printf("%d",d);
            return 0;
        }
        if(visited[u][f][ht]) continue;
        visited[u][f][ht]=1;
        if(f<cap&&!visited[u][f+1][ht]&&dist[u][f+1][ht]>dist[u][f][ht]+fc[u]){
            dist[u][f+1][ht]=dist[u][f][ht]+fc[u];
            pq.push({d+fc[u],u,f+1,ht});
        }
        if(ht&&f<cap&&!visited[u][cap][0]&&dist[u][cap][0]>dist[u][f][1]) {
            pq.push({d,u,cap,0});
        }
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i].first;
            w=edge[u][i].second;
            if(f>=w&&!visited[v][f-w][ht]&&dist[v][f-w][ht]>dist[u][f][ht]){
                /*COST*/dist[v][f-w][ht]=dist[u][f][ht];
                pq.push({d,v,f-w,ht});
            }
        }
    }
}