#include "onlineshop.h"
#include<bits/stdc++.h>
using namespace std;
int l,r,m,a,b,pr,RESET_LIMIT=20;
bool searching;
void reset(){
  l=1000,r=1000000;
  searching=1;
  a=0,b=0;
  --RESET_LIMIT;
  RESET_LIMIT=max(5,RESET_LIMIT);//Latest SubM
  //printf("Reset\n");
}
int f(int x){
  //printf("pr %d\n",pr);
  return (max(1,x%10))*pow(10,x/10);
}
void sell_all(int N){
  reset();
  for(int i=0; i<N; i++){
    //if(i%N/2==0) reset();
    // l==r vs. l+1==r
    if(l+1==r){
      searching=0;
      pr=l;
      l=0; //Submission 4
    }
    if(searching){
      m=(l+r)/2;
      //printf("BS %d %d %d\n",l,m,r);
      if(sell_price(m)){
        l=m;
      }
      else{
        r=m+1;
      }
    }
    else{
      if(sell_price(pr)){
        b=0;
        a+=1;
        pr+=f(a);
        pr=min(pr,1000000);
      }
      else{
        a=0;
        b+=1;
        pr-=f(b);
        if(b>=RESET_LIMIT){
          reset();
        }
      }
    }
  }
}

