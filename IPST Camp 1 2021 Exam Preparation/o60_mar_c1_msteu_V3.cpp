//      12/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<long double,int> li;
int n,x[100005],y[100005],mst,u;
long double ans,d,reach[100005],w;
bool visited[100005];
priority_queue<li,vector<li>,greater<li> > pq;
long double dist(int u,int v){
    return (x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
        reach[i]=1e15;
    }
    reach[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        d=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u]=1;
        ++mst;
        ans+=d;
        if(mst==n){
            cout<<ans;
            return 0;
        }
        for(int v=0;v<n;++v){
            w=dist(u,v);
            if(v!=u&&!visited[v]&&w<reach[v]){
                //could we do even better?
                reach[v]=w;
                pq.push({w,v});
            }
        }
    }
}