#include "traffic.h"
//#include "trafficlib.cpp"
#include <bits/stdc++.h>

using namespace std;
int N,K,idx,xa[5],ya[5],xb[5],yb[5],con,ansxa[5],ansxb[5],ansya[5],ansyb[5],ac;
bool db,skip,is_ver;
void bs(int L,int R){
  if(L>R) return ;
  int M=(L+R)/2;
  if(L+1==R){
    if(is_ver){
      ansxa[ac]=con;
      ansya[ac]=L;
      ansxb[ac]=con;
      ansyb[ac]=R;
      ++ac;
    }
    else{
      ansxa[ac]=L;
      ansya[ac]=con;
      ansxb[ac]=R;
      ansyb[ac]=con;
      ++ac;
    }
    return ;
  }
  if(db){
    int res,res2;
    if(is_ver){
      res=traffic_query(con,L,con,M),res2=traffic_query(con,M,con,R);
    }
    else{
      res=traffic_query(L,con,M,con),res2=traffic_query(M,con,R,con);
    }
    if(res>M-L+1) {
      return bs(L,M);
    }
    else if(res2>R-M+1) {
      return bs(M,R);
    }
    else{
      db=0;
      bs(L,M);
      return bs(M,R);
    }
  }
  else{
    int res;
    if(is_ver) res=traffic_query(con,L,con,M);
    else res=traffic_query(L,con,M,con);
    if(res>M-L){
      return bs(L,M);
    }
    else return bs(M,R);
  }
}
int main(){
  traffic_init(&N,&K);
  for(int i=1;i<=N;++i){
    int res=traffic_query(i,1,i,N);
    if(res>=N){
      xa[idx]=i;
      ya[idx]=1;
      xb[idx]=i;
      yb[idx]=N;
      ++idx;
    }
    if(res>N) skip=1;
  }
  for(int i=1;i<=N;++i){
    if(skip) continue;
    int res=traffic_query(1,i,N,i);
    if(res>=N){
      xa[idx]=1;
      ya[idx]=i;
      xb[idx]=N;
      yb[idx]=i;
      ++idx;
    }
  }
  
  if(K==2&&idx==1) db=1;
  //printf("idx%d db%d\n",idx,db);
  for(int i=0;i<idx;++i){
    is_ver=0;
    if(xa[i]==xb[i]) is_ver=1;
    if(is_ver){
      con=xa[i];
    }
    else con=ya[i];
    //printf("(%d,%d,%d,%d) con%d, is_ver%d\n",xa[i],ya[i],xb[i],yb[i],con,is_ver);
    bs(1,N);
  }
  //printf("report %d %d %d %d, %d %d %d %d\n",ansxa[0],ansya[0],ansxb[0],ansyb[0],ansxa[1],ansya[1],ansxb[1],ansyb[1]);
  traffic_report(ansxa[0],ansya[0],ansxb[0],ansyb[0],ansxa[1],ansya[1],ansxb[1],ansyb[1]);
}
