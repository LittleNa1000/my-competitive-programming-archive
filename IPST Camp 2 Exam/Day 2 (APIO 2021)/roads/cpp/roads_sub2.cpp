#include "roads.h"
#include<bits/stdc++.h>
using namespace std;
struct EDGE{
  int u,v,w;
};
vector<EDGE> edge;
bool com(const EDGE &a,const EDGE &b){
  return a.w>b.w;
}
vector<long long> minimum_closure_costs(int N, vector<int> U,
                                               vector<int> V,
                                               vector<int> W) {
  vector<long long> ans(N,0);
  long long dp[100005];
  for(int i=0;i<N-1;++i){
    ans[0]+=W[i];
  }
  for(int i=2;i<N;++i){
    dp[i]=min(dp[i-2]+W[i-2],dp[i-1]+W[i-1]);
    //printf("%lld ",dp[i]);
  }
  //printf("\n");
  ans[1]=dp[N-1];
  return ans;
}
