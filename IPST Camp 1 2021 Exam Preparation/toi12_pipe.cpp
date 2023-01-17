//      12/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<long double,int> li;
int n,x[100005],y[100005],mst,u,k;
long double d,sum,reach[100005],w;
vector<long double> ans;
bool visited[100005];
priority_queue<li,vector<li>,greater<li> > pq;
long double dist(int u,int v){
    return abs(x[u]-x[v])+abs(y[u]-y[v]);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
        reach[i]=numeric_limits<long double>::max();
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
        ans.push_back(d);
        if(mst==n){
            break;
        }
        for(int v=0;v<n;++v){
            w=dist(u,v);
            if(v!=u&&!visited[v]&&reach[v]>w){
                //could we do even better?
                reach[v]=w;
                pq.push({w,v});
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<=n-k;++i){
        sum+=ans[i];
    }
    cout<<sum;
}