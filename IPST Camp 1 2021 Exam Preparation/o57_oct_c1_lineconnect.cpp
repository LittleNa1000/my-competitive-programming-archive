//      19/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> vec;
int ans=INT_MAX,V,x,u,v,par[100005];
int find_par(int x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d",&V);
    for(int i=1;i<=V;++i){
        scanf("%d",&x);
        vec.push_back({x,i});
        par[i]=i;
    }
    for(int i=0;i<V-2;++i){
        scanf("%d %d",&u,&v);
        u=find_par(u);
        v=find_par(v);
        if(u!=v){
            par[max(u,v)]=par[min(u,v)];
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<V;++i){
        u=find_par(vec[i].second);
        v=find_par(vec[i-1].second);
        if(u!=v){
            ans=min(ans,vec[i].first-vec[i-1].first);
        }
    }
    printf("%d",ans);
}