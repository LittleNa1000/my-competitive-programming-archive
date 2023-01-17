//                     8/11/2563
#include<bits/stdc++.h>
using namespace std;
typedef vector< pair<int,int> > vpii;
typedef pair<int,int> pii;
struct t{
    int u,v,w,idx;
};
bool sbw(const t& a,const t& b){
    return a.w<b.w;
}
bool revsort(const pii &a, const pii &b){
    return a.first>b.first;
}
bool no_bridge;
int V,E,K,u,v,w,mst,me,idx;
long long int ans;
int par[100001];
vpii minedge,v2;
vector<t> edge;
vector<int> v1;
int find_par(int x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}
int main(){
    scanf("%d %d %d",&V,&E,&K);
    for(int i=0;i<V;++i){
        par[i]=i;
        minedge.push_back({INT_MAX,i});
    }
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        edge.push_back({u-1,v-1,w,i+1});
        minedge[u-1].first=min(minedge[u-1].first,w);
        minedge[v-1].first=min(minedge[v-1].first,w);
    }
    for(int i=0;i<K;++i){
        scanf("%d %d",&u,&w);
        edge.push_back({u-1,-1,w,i+1});
    }
    sort(minedge.begin(),minedge.end(),revsort);
    sort(edge.begin(),edge.end(),sbw);
    int k=0;
    for(int i=0;mst<V-1;++i){
        u=edge[i].u;
        v=edge[i].v;
        w=edge[i].w;
        idx=edge[i].idx;
        if(v==-1&&no_bridge) continue ;
        u=find_par(u);
        if(v==-1){
            for(;k<minedge.size();++k){
                me=minedge[k].first;
                v=minedge[k].second;
                /*if(me<w){
                    no_bridge=1;
                    break ;
                }*/
                v=find_par(v);
                if(u!=v){
                    par[max(u,v)]=par[min(u,v)];
                    ans+=w;
                    v2.push_back({idx,v+1});
                    ++mst;
                    break ;
                }
            }
        }
        else{
            v=find_par(v);
            if(u!=v){
                par[max(u,v)]=par[min(u,v)];
                ans+=w;
                v1.push_back(idx);
                ++mst;
            }
        }
    }
    printf("%lld\n%d\n",ans,v1.size());
    for(int i=0;i<v1.size();++i){
        printf("%d\n",v1[i]);
    }
    printf("%d\n",v2.size());
    for(int i=0;i<v2.size();++i){
        printf("%d %d\n",v2[i].first,v2[i].second);
    }
}