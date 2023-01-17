//                      20/10/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > N;
int par[100001],c[100001];
int V,E,u,v,w,mst,ans;
priority_queue<N> pq;
int find_par(int x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}
int main(){
    scanf("%d %d",&V,&E);
    for(int i=0;i<V;++i){
        scanf("%d",&c[i]);
        par[i]=i;
    }
    for(int i=0;i<E;++i){
        scanf("%d %d",&u,&v);
        pq.push({c[u-1]+c[v-1],{u-1,v-1}});
    }
    while(mst<V-1&&!pq.empty()){
        u=pq.top().second.first; v=pq.top().second.second; w=pq.top().first;
        pq.pop();
        u=find_par(u);
        v=find_par(v);
        if(u!=v){
            par[max(u,v)]=par[min(u,v)];
            ++mst;
            ans+=w;
        }
    }
    printf("%d",ans);
}