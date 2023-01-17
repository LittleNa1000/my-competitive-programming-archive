//      20/2/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int d,u,k;
};
struct S{
    int w,v;
    bool uK;
};
int V,E,K,u,v,w,d,k,useK,dist[100005][8];
bool visited[100005][8];
vector<S> edge[100005];
priority_queue<N> pq;
bool operator<(const N &a,const N &b){
    return a.d>b.d;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d %d",&V,&E,&K);
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        if(-100<=w&&w<=-1){
            edge[u-1].push_back({0,v-1,0});
        }
        else if(w<-100){
            edge[u-1].push_back({0,v-1,1});
        }
        else{
            edge[u-1].push_back({w,v-1,0});
        }
    }
    for(int i=0;i<V;++i){
        for(int j=0;j<=K;++j) dist[i][j]=INT_MAX;
    }
    /*for(int i=0;i<V;++i){
        for(int j=0;j<edge[i].size();++j){
            printf("%d %d %d\n",edge[i][j].w,edge[i][j].v,edge[i][j].uK);
        }
        printf("\n");
    }*/
    dist[0][K]=0;
    pq.push({0,0,K});
    while(!pq.empty()){
        d=pq.top().d;
        u=pq.top().u;
        k=pq.top().k;
        pq.pop();
        if(visited[u][k]) continue;
        visited[u][k]=1;
        //printf("%d %d %d\n",d,u,k);
        if(u==V-1){
            printf("%d",d); return 0;
        }
        for(int i=0;i<edge[u].size();++i){
            w=edge[u][i].w;
            v=edge[u][i].v;
            useK=edge[u][i].uK;
            //printf("edge %d %d %d",w,v,useK);
            if(useK&&k&&!visited[v][k-1]&&d<dist[v][k-1]){
                dist[v][k-1]=d;
                pq.push({d,v,k-1});
                //printf("add1");
            }
            else if(!useK&&!visited[v][k]&&d+w<dist[v][k]){
                dist[v][k]=d+w;
                pq.push({d+w,v,k});
                //printf("add2");
            }
            //printf("\n");
        }
    }
}
