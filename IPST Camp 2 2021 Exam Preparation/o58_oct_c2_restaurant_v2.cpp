//              23/4/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int d,u,v;
};
vector<N> edge;
bool com(const N &a,const N &b){
    return a.d<b.d;
}
int n,T,num,mx,ans,u,v,mst;
int par[305],deg[305],r[305];
int find_par(int x){
    if(x==par[x]) return x;
    return par[x]=find_par(par[x]);
}
int main(){
    scanf("%d %d",&n,&T);
    for(int i=0;i<n;++i){
        par[i]=i;
        for(int j=0;j<n;++j){
            scanf("%d",&num);
            if(i>j){
                edge.push_back({num,i,j});
            }
        }
    }
    sort(edge.begin(),edge.end(),com);
    for(int i=0;i<edge.size();++i){
        u=find_par(edge[i].u);
        v=find_par(edge[i].v);
        if(u!=v){
            ++mst;
            if(r[u]>r[v]) par[v]=par[u];
            else par[u]=par[v];
            if(r[u]==r[v]) ++r[u];
            ++deg[edge[i].u];
            ++deg[edge[i].v];
            if(mx<deg[edge[i].u]){
                mx=deg[edge[i].u];
                ans=edge[i].u;
            }
            if(mx<deg[edge[i].v]){
                mx=deg[edge[i].v];
                ans=edge[i].v;
            }
            if(mst==n-1) break;
        }
    }
    printf("%d",ans+1);
    if(T==2) printf("\n%d",deg[ans]);
}