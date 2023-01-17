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
  for(int i=0;i<N-1;++i){
    edge.push_back({U[i],V[i],W[i]});
  }
  sort(edge.begin(),edge.end(),com);
  //for(int i=0;i<N-1;++i) printf("%d ",edge[i].w); printf("\n");
  for(int i=N-2;i>=0;--i){
    ans[i]=ans[i+1]+edge[i].w;
  }
  return ans;
}
