#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
vector<pii> edge[200012];
long long V,E,s,t,u,v,w,d;
long long dist[200012][3];
bool visited[200012][3];
bool dg[200012];
void shp(long long src,long long idx){
    dist[src][idx]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,src});
    while(!pq.empty()){
        d=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(visited[u][idx]) continue;
        visited[u][idx]=1;
        for(long long i=0;i<edge[u].size();++i){
            v=edge[u][i].first;
            w=edge[u][i].second;
            if(!visited[v][idx]&&dist[v][idx]>d+w){
                dist[v][idx]=d+w;
                pq.push({d+w,v});
            }
        }
    }
}
int main(){
    scanf("%lld%lld%lld%lld",&V,&E,&s,&t);
    --s;
    --t;
    for(long long i=0;i<E;++i){
        scanf("%lld%lld%lld",&u,&v,&w);
        edge[u-1].push_back({v-1,w});
        edge[v-1].push_back({u-1,w});
    }
    for(long long i=0;i<V;++i){
        dist[i][0]=LONG_LONG_MAX;
        dist[i][1]=LONG_LONG_MAX;
        dist[i][2]=LONG_LONG_MAX;
    }
    shp(s,0);
    shp(t,1);
    dg[s]=1;
    dg[t]=1;
    for(long long i=0;i<V;++i){
        if(dist[i][0]+dist[i][1]==dist[t][0]){
            dg[i]=1;
        }
    }
    dist[s][2]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,s});
    while(!pq.empty()){
        d=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(visited[u][2]) continue;
        visited[u][2]=1;
        for(long long i=0;i<edge[u].size();++i){
            v=edge[u][i].first;
            w=edge[u][i].second;
            if(dg[v]) w=0;
            if(!visited[v][2]&&dist[v][2]>d+w){
                dist[v][2]=d+w;
                pq.push({d+w,v});
            }
        }
    }
    long long q,x;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&x);
        printf("%lld\n",dist[x-1][2]);
    }
    //for(long long i=0;i<V;++i) printf("%d ",dist[i][2]); printf("\n");
    //for(long long i=0;i<V;++i) printf("%d ",dg[i]);
}