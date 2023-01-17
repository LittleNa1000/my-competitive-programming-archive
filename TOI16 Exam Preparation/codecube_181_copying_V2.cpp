//                  11/11/2563 or not reset par data if k is increasing
#include<bits/stdc++.h>
using namespace std;
bool no_copy,b=1;
int x[50005],y[50005];
struct t{
    int u,v,w;
};
bool sbw(const t &a,const t &b){
    return a.w<b.w;
}
int V,E,P,par[40005][20],ans,l,m,r,idx,u,w,v,mw=INT_MAX;
vector<t> edge;
int find_par(int x){
    if(x==par[x][idx]) return x;
    return par[x][idx]=find_par(par[x][idx]);
}
int main(){
    scanf("%d %d %d",&V,&E,&P);
    for(int i=1;i<=V;++i){
        for(int j=0;j<20;++j) par[i][j]=i;
    }
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        edge.push_back({u,v,w}); //or u-1,v-1,w
        mw=min(mw,w);
    }
    ans=mw;
    for(int i=0;i<P;++i){
        scanf("%d %d",&x[i],&y[i]);
    }
    sort(edge.begin(),edge.end(),sbw);
    r=E-1;
    while(l<=r){
        m=(l+r)/2;
        if(!idx) m=E;
        for(int i=0;i<m;++i){
            u=find_par(edge[i].u);
            v=find_par(edge[i].v);
            par[max(u,v)][idx]=par[min(u,v)][idx];
        }
        no_copy=1;
        for(int i=0;i<P;++i){
            u=find_par(x[i]);
            v=find_par(y[i]);
            if(par[u][idx]==par[v][idx]){
                no_copy=0;
                break ;
            }
        }
        if(!idx&&no_copy){
            printf("-1");
            return 0;
        }
        ++idx;
        //printf("m%d k%d nocopy%d \n",m,edge[m].w,no_copy);
        
        if(no_copy){
            ans=max(ans,edge[m].w);
            l=m+1;
        }
        else{
            r=m-1;
            b=0;
        }
    }
    printf("%d",ans);
} 