#include "rumors.h"
#include<bits/stdc++.h>
using namespace std;
int arr[2005],diff,val,a,b,mx,sum;
vector<int> ans;
vector<int> analyze_rumors(int N, int K, int Q,vector<int> d,vector<int> x,vector<int> j) {
    for(int i=1;i<N;++i){
      diff=d[i]-d[i-1];
      val=(ceil((float)(diff-K)/(float)K));
      //printf("x%d \n",val);
      arr[i-1]=val;
    }
    for(int q=0;q<Q;++q){
      mx=0;
      sum=0;
      a=x[q];
      b=x[q];
      while(a-1>=0&&sum+arr[a-1]<=j[q]){
        sum+=arr[a-1];
        --a;
      }
      mx=max(mx,b-a+1);
      while(b<N-1&&a<=x[q]){
        sum+=arr[b];
        ++b;
        while(sum>j[q]){
          sum-=arr[a];
          ++a;

        }
        mx=max(mx,b-a+1);
      }
      ans.push_back(mx);
    }
  return ans;
}
