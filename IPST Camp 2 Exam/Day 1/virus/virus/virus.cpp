#include "virus.h"
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, x, y,cnt,arr[15];
vector<int> v;
void initialize(int N, int X, int Y) {
  n = N, x = X, y = Y;
  if(n<=11){
    //Subtask 1,2
    //BF
    v.push_back(x);
    for(int i=1;i<=N;++i){
      if(i!=x&&i!=y){
        v.push_back(i);
      }
    }
    v.push_back(y);
    do{
      
      cnt=0;
      for(int i=1;i<=n-2;++i){
        if((v[i-1]<v[i]&&v[i+1]<v[i])||(v[i-1]>v[i]&&v[i+1]>v[i])){
          cnt++;
        }
      }
      //for(int i=0;i<n;++i) printf("%d ",v[i]);
      //printf("cnt = %d\n",cnt);
      arr[cnt]++;
      arr[cnt]%=MOD;
    }while(next_permutation(v.begin()+1,v.begin()+n-1));
  }
}

int ask(int L) {
  if(n<=11){
    //Subtask 1,2
    return arr[L];
  }

  else return 0;
}