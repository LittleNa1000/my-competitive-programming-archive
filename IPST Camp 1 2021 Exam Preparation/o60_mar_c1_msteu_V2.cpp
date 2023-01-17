//      12/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<long double,int> li;
int n,x[100005],y[100005],mst,u;
long double ans,d,w,reach[100005];
bool visited[100005];
long double dist(int u,int v){
    return (x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]);
}
void getmin(){
    d=numeric_limits<long double>::max();
    for(int i=0;i<n;++i){
        if(!visited[i]&&reach[i]<d){
            d=reach[i];
            u=i;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i=1;i<n;++i) reach[i]=numeric_limits<long double>::max(); //or 1e15
    while(1){
        getmin();
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
            }
        }
    }
}