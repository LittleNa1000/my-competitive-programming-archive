#include <bits/stdc++.h>
#include "dual.h"

using namespace std;
struct N{
  int d,u,x,y;
};
priority_queue<N> pq;
bool operator<(const N &a,const N &b){
  return a.d>b.d;
}
bool visited[105][105][105];
int dist[105][105][105],d,u,x,y;
long long dual_fuel(int n,int v,vector<int> &a, vector<int> &b) {
  if(n>100) return 0;
  for(int i=0;i<=n;++i){
    for(int j=0;j<=v;++j){
      for(int k=0;k<=v;++k){
        dist[i][j][k]=INT_MAX;
      }
    }
  }
  dist[0][0][0]=0;
  pq.push({0,0,0,0});
  while(!pq.empty()){
    d=pq.top().d; u=pq.top().u; x=pq.top().x; y=pq.top().y;
    pq.pop();
    if(visited[u][x][y]) continue;
    visited[u][x][y]=1;
    if(u>=n) return d;
    if(x+1<=v) pq.push({d+a[u],u,x+1,y});
    if(y+1<=v) pq.push({d+b[u],u,x,y+1});
    for(int i=1;i<=min(x,y);++i){
      if(u+i<=n&&!visited[u+i][x-i][y-i]&&d<dist[u+i][x-i][y-i]){
        pq.push({d,u+i,x-i,y-i});
        dist[u+i][x-i][y-i]=d;
      }
    }
  }
  return 0;
}
/*
4 2 
3 1 1 4 
1 5 1 6
*/
