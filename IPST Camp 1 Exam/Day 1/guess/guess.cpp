#include "guess.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> ic;
//BRUTE FORCE
char res;
int find_answer(int N, int K) {
  vector<ic> base(N),send;
  for(int i=0;i<N;++i){
    base[i].first=i;
  }
  if(K==1){
    for(int i=0;i<base.size();++i){
      send.push_back({i,'R'});
      if(1){
        res=ask(send);
        if(res=='R') return i;
      }
    }
  }
  else{
    for(int i=0;i<base.size();++i){
      if(i%2) send.push_back({i,'B'});
      else send.push_back({i,'R'});
      if(i%2){
        res=ask(send);
        if(res=='B') return i;
        else if(res=='R') return i-1;
      }
    }
  }
}