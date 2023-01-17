#include "jumps.h"
#include<bits/stdc++.h>
#define ff first 
#define ss second 
using namespace std;
vector<int> h;
vector<int> edge[200005];
int l[200005],r[200005];
int u,d,n,idx;
void init(int N, vector<int> H) {
  h=H;
  n=N;
  //Build DAG in O(N)
  deque<int> dq;
  for(int i=0;i<n;++i){
    l[i]=-1;
    r[i]=-1;
  }
  for(int i=0;i<n;++i){
    while(1){
      if(dq.empty()||h[i]<h[dq.back()]){
        dq.push_back(i);
        break;
      }
      else{
        idx=dq.back();
        dq.pop_back();
        if(!dq.empty()) l[idx]=dq.back();
        r[idx]=i;
      } 
    }
    
  }
  if(dq.size()==2){
    l[dq.back()]=dq.front();
  }
  for(int i=0;i<n;++i){
    //printf("%d %d %d\n",i,l[i],r[i]);
    if(l[i]!=-1) edge[i].push_back(l[i]);
    if(r[i]!=-1) edge[i].push_back(r[i]);
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
/*
7 3
3 2 1 6 4 5 7
4 4 6 6
1 3 5 6
0 1 2 2
*/
