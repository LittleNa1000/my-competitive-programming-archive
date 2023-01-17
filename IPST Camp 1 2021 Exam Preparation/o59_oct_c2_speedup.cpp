//                  18/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct N{
    long long d;
    int u,po,lst;
};
bool operator<(const N &a,const N &b){
    return a.d>b.d;
}
priority_queue<N> pq;
vector<ii> edge[80005];
int expo[]={1,2,4,8,16,32,64,128,256};
int V,E,L,Q,u,v,w,po,lst;
long long dist[80005][10],d;
bool hp[80005],visited[80005][10]; //or bitset
int main(){
    scanf("%d%d%d%d",&V,&E,&L,&Q);
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        edge[u-1].push_back({w,v-1});
        edge[v-1].push_back({w,u-1});
    }
    for(int i=0;i<L;++i){
        scanf("%d",&u);
        hp[u-1]=1;
    }
    for(int i=0;i<V;++i){
        for(int j=0;j<=Q;++j){
            dist[i][j]=LONG_LONG_MAX;
        }
    }
    dist[0][0]=0;
    pq.push({0,0,0,-1});
    while(!pq.empty()){
        d=pq.top().d;
        u=pq.top().u;
        po=pq.top().po;
        lst=pq.top().lst;
        pq.pop();
        if(visited[u][po]) continue;
        visited[u][po]=1;
        //printf("%lld %d %d %d\n",d,u+1,po,lst+1);
        if(u==V-1){
            printf("%lld",d); return 0;
        }
        if(hp[u]&&po<Q&&lst!=u){
            ++po;
            lst=u;
        }
        //printf("%lld %d %d %d\n",d,u+1,po,lst+1);
        for(int i=0;i<edge[u].size();++i){
            w=(edge[u][i].first/expo[po]);
            v=edge[u][i].second;
            if(d+w<dist[v][po]&&!visited[v][po]){
                dist[v][po]=d+w;
                pq.push({d+w,v,po,lst});
            }
        }
    }
}