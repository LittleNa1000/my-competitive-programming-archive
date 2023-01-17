#include "jumps.h"
#include<bits/stdc++.h>
#define ff first 
#define ss second 
using namespace std;
vector<int> h;
vector<int> edge[200005];
int u,d,n;
void init(int N, vector<int> H) {
  h=H;
  n=N;
  //Build DAG in O(N^2)
  for(int i=0;i<N;++i){
    for(int j=i-1;j>=0;--j){
      if(h[j]>h[i]){
        edge[i].push_back(j);
        break;
      }
    }
    for(int j=i+1;j<N;++j){
      if(h[j]>h[i]){
        edge[i].push_back(j);
        break;
      }
    }
  }

}

int minimum_jumps(int A, int B, int C, int D) {
  //BFS in O(N)
  //can check -1 case in O(logN)
  queue<pair<int,int>> q;
  vector<bool> vst(n,0);
  for(int i=A;i<=B;++i){
    q.push({i,0});
  }
  while(!q.empty()){
    u=q.front().ff; d=q.front().ss; q.pop();
    if(vst[u]) continue;
    vst[u]=1;
    if(C<=u&&u<=D) return d;
    for(int i=0;i<edge[u].size();++i){
      if(!vst[edge[u][i]]){
        if(C<=edge[u][i]&&edge[u][i]<=D) return d+1;
        q.push({edge[u][i],d+1});
      }
    }
  }
  return -1;
}
