#include "blindwalk.h"
#include<stdio.h>
#include<vector>
static const long long T1 = 2596418101;
static const long long T2 = 840634349;
static const long long T3 = 590846489;
using namespace std;
long long D;
vector<vector<int>> build_graph(int N){
  vector<vector<int>> out;
  for(int i=0;i<N;++i){
    for(int j=i+1;j<N;++j){
      D=ask(i,j);
      if(D==T1){
        out.push_back({i,j,1});
      }
      else if(D==T2){
        out.push_back({i,j,2});
      }
      else if(D==T3){
        out.push_back({i,j,3});
      }
    }
  }
  return out;
}
