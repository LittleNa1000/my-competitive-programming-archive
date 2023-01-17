//      20/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct N{
    int d,u,l;
};
vector<ii> edge[10005],fl[10005];
bool visited[10005][55];
int V,E,s,L,u,v,w,d,l,dist[10005][55];
priority_queue<N> pq;
bool operator<(const N &a,const N &b){
    return a.d>b.d;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d %d %d",&V,&E,&s,&L);
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        edge[u-1].push_back({w,v-1});
    }
    for(int i=0;i<s;++i){
        scanf("%d %d %d",&u,&v,&w);
        fl[u-1].push_back({w,v-1});
    }
    for(int i=0;i<V;++i){
        for(int j=0;j<=L;++j) dist[i][j]=INT_MAX;
    }
    dist[0][L]=0;
    pq.push({0,0,L});
    while(!pq.empty()){
        d=pq.top().d;
        u=pq.top().u;
        l=pq.top().l;
        pq.pop();
        if(visited[u][l]) continue;
        visited[u][l]=1;
        //printf("%d %d %d\n",d,u,l);
        if(u==V-1){
            printf("%d",d); return 0;
        }
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i].second;
            w=edge[u][i].first;
            if(!visited[v][l]&&d+w<dist[v][l]){
                dist[v][l]=d+w;
                pq.push({d+w,v,l});
            }
        }
        if(l){
            for(int i=0;i<fl[u].size();++i){
                v=fl[u][i].second;
                w=fl[u][i].first;
                if(!visited[v][l-1]&&d+w<dist[v][l-1]){
                    dist[v][l-1]=d+w;
                    pq.push({d+w,v,l-1});
                }
            }
        }
    }
}