//                      13/10/2563
#include<bits/stdc++.h>
using namespace std;
struct s{
    int a,b,c;
};
bool operator>(const s &a, const s &b){
    return a.c>b.c;
}
priority_queue<s,vector<s>,greater<s> > pq;
int par[40002],s1[50002],s2[50002];
int find_par(int x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}
int V,E,P,u,v,w,mst;
int main(){
    scanf("%d %d %d",&V,&E,&P);
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        pq.push({u,v,w});
    }
    for(int i=0;i<V;++i){
        par[i]=i;
    }
    for(int i=0;i<P;++i){
        scanf("%d %d",&s1[i],&s2[i]);
    }
    while(mst<V-1&&!pq.empty()){
        u=pq.top().a;   v=pq.top().b;   w=pq.top().c;
        pq.pop();
        u=find_par(u);
        v=find_par(v);
        if(u!=v){
            par[max(u,v)]=par[min(u,v)];
            ++mst;
            for(int i=0;i<P;++i){
                if(par[s1[i]]==par[s2[i]]){
                    printf("%d",w);
                    return 0;
                }
            }
        }
    }
    printf("-1");
}