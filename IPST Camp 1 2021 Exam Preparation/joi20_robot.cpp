//      14/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<unsigned long long,int> li;
struct N{
    int v,c,w;
};
int V,E,u,v,c,w,pre;
unsigned long long d,dist[200005];
bool visited[200005];
priority_queue<li,vector<li>,greater<li>> pq;
vector<N> edge[200005];
bool sbc(const N &a,const N &b){
    return a.c<b.c;
}
int main(){
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;++i){
        scanf("%d %d %d %d",&u,&v,&c,&w);
        edge[u-1].push_back({v-1,c,w});
        edge[v-1].push_back({u-1,c,w});
    }
    for(int i=0;i<V;++i){
        dist[i]=LONG_LONG_MAX;
        sort(edge[i].begin(),edge[i].end(),sbc);
    }
    pq.push({0,0});
    while(!pq.empty()){
        d=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u]=1;
        //printf("%llu %d\n",d,u+1);
        if(u==V-1){
            printf("%llu",d);
            return 0;
        }
        pre=-1;
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i].v;
            c=edge[u][i].c;
            w=edge[u][i].w;
            if(!((i>0&&edge[u][i-1].c==edge[u][i].c)||(i+1<edge[u].size()&&edge[u][i+1].c==edge[u][i].c))) w=0;
            //printf("(%d %d %d)\n",v+1,c,w);
            if(!visited[v]&&d+w<dist[v]){
                dist[v]=d+w;
                pq.push({d+w,v});
            }
            pre=c;
        }
    }
    printf("-1");
}