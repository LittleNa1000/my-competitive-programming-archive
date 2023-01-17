/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include<bits/stdc++.h>
using namespace std;
int E,V,u,v,w,bf;
int G[2012][2012];
//deque<int> dq;
//bool vst[2012];
int par[2012];
struct N{
    int u,v,w;
};
vector<N> vv;
void dfs(int src){
    stack<int> st;
    st.push(src);
    while(!st.empty()){
        u=st.top();
        st.pop();
    }
}
int find_par(int x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}
int main(){
    scanf("%d %d",&E,&V);
    for(int i=0;i<V;++i){
        par[i]=i;
    }
    //for(int i=0;i<V;++i){
    //    for(int j=0;j<V;++j) G[i][j]=INT_MAX;
    //}
    for(int i=0;i<E;++i){
        scanf("%d%d%d",&u,&v,&w);
        //printf("%d ",ans);
        vv.push_back({u,v,w});
        //G[u][v]=w;
        //G[v][u]=w;
        bf+=w;
    }
    bf*=2;
    //printf("T");
    if(E-V==-1) {printf("%d",bf); return 0;}
    for(int i=0;i<E;++i){
        u=vv[i].u;
        v=vv[i].v;
        w=vv[i].w;
        //printf("%d %d\n",u,v);
        u=find_par(u);
        v=find_par(v);
        if(par[u]==par[v]){
            if(i+1==E){
                printf("%d",bf/2);
                return 0;
            }

        }
        else{
            par[max(u,v)]=par[min(u,v)];
        }
    }
}
