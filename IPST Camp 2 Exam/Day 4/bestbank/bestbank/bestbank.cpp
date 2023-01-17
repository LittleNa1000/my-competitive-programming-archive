#include "bestbank.h"
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> ii;
int n,k,u,par,d;
bool bank[100005],vst[100005];
vector<long long> percent[100005],fee[100005];
long long mn;
vector<ii> edge[100005];
struct TT{
  int u,p,d;
};
void initialize(int N, int K,vector<vector<int> > R,vector<vector<long long> > B){
  n=N;
  k=K;
  //printf("1\n");
  for(int i=0;i<N-1;++i){
    //printf("i = %d\n",i);
    edge[R[i][0]].push_back(make_pair(R[i][1],R[i][2]));
    edge[R[i][1]].push_back(make_pair(R[i][0],R[i][2]));
  }
  //printf("2\n");
  for(int i=0;i<k;++i){
    bank[B[i][0]]=1;
    percent[B[i][0]].push_back(B[i][1]);
    fee[B[i][0]].push_back(B[i][2]);
  }
  //printf("3\n");
  return;
}

void update_bank(int P, int F,long long L){
  bank[P]=1;
  percent[P].push_back(F);
  fee[P].push_back(L);
  return;
}

long long find_best_bank(int S, int Y){
  mn=LONG_LONG_MAX;
  for(int i=0;i<n;++i) vst[i]=0;
  queue<ii> q;
  q.push({S,0});
  while(!q.empty()){
    u=q.front().ff;
    //par=q.front().p;
    d=q.front().ss;
    q.pop();
    if(vst[u]) continue ;
    vst[u]=1;
    if(bank[u]){
      for(int i=0;i<fee[u].size();++i){
        mn=min(mn,d+fee[u][i]+(Y*percent[u][i]/100));
      }
    }
    for(int i=0;i<edge[u].size();++i){
      if(!vst[edge[u][i].ff]){
        q.push({edge[u][i].ff,d+edge[u][i].ss});
      }
    }
  }
  return mn;
}
/*
5 2 7
0 2 15 
1 2 6 
2 3 5 
3 4 7
1 5 3 
4 2 5
2 2 100
1 0 1 10
2 2 1000
2 3 500
2 1 1000
2 4 700
*/