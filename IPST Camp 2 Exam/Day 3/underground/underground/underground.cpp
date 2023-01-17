#include "underground.h"
#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
struct N{
  int i,j,d;
};
priority_queue<N> pq;
bool operator<(const N &a,const N &b){
  return a.d>b.d;
}
int rnk[505][505],dist[505][505];
bool visited[505][505];
int i2,j2,ans;
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
pair<int,int> p1,p2,p3,p4,par[505][505];
pair<int,int> find_par(pair<int,int> x){
  if(par[x.ff][x.ss]==x) return x;
  return par[x.ff][x.ss]=find_par(par[x.ff][x.ss]);
}
void merge(int a,int b,int c,int d){
  p1=find_par({a,b});
  p2=find_par({c,d});
  if(p1!=p2){
    if(rnk[p1.ff][p1.ss]<rnk[p2.ff][p2.ss]){
      par[p1.ff][p1.ss]=p2;
    }
    else par[p2.ff][p2.ss]=p1;
    if(rnk[p1.ff][p1.ss]==rnk[p2.ff][p2.ss]) ++rnk[p1.ff][p1.ss];
  }
}
bool allconnect(int R,int C){
  p1=find_par({0,0});
  p2=find_par({0,C-1});
  p3=find_par({R-1,0});
  p4=find_par({R-1,C-1});
  if((p1==p2)&&(p3==p4)&&(p1==p3)) return 1;
  return 0;
}
int dig_paths(int R, int C,vector<vector<int>>& A){
  //return R+C-1+min(R,C)-1; //Subtask 1
  //Maybe dijkstra + W=0 + dijkstra
  for(int i=0;i<R;++i){
    for(int j=0;j<C;++j){
      par[i][j]={i,j};
      dist[i][j]=INT_MAX;
    }
  }
  pq.push({0,0,A[0][0]});
  pq.push({0,C-1,A[0][C-1]});
  pq.push({R-1,0,A[R-1][0]});
  pq.push({R-1,C-1,A[R-1][C-1]});
  dist[0][0]=A[0][0];
  dist[0][C-1]=A[0][C-1];
  dist[R-1][0]=A[R-1][0];
  dist[R-1][C-1]=A[R-1][C-1];
  while(!pq.empty()){
    int i=pq.top().i,j=pq.top().j,d=pq.top().d;
    pq.pop();
    if(visited[i][j]) continue;
    visited[i][j]=1;
    printf("%d %d %d %d\n",i,j,d,A[i][j]);
    for(int k=0;k<4;++k){
      i2=i+y[k];
      j2=j+x[k];
      if(i2>=0&&i2<R&&j2>=0&&j2<C&&visited[i2][j2]){
        merge(i,j,i2,j2);
      }
    }
    if(allconnect(R,C)) break;
    for(int k=0;k<4;++k){
      i2=i+y[k];
      j2=j+x[k];
      if(i2>=0&&i2<R&&j2>=0&&j2<C&&!visited[i2][j2]&&d+A[i2][j2]<dist[i2][j2]){
        dist[i2][j2]=d+A[i2][j2];
        pq.push({i2,j2,dist[i2][j2]});
      }
    }
  }
  for(int i=0;i<R;++i){
    for(int j=0;j<C;++j){
      if(visited[i][j]) ans+=A[i][j];
    }
  }
  return ans;
  
}
/*
5 6
1 20 20 25 50 1
2 1 45 4 1 1
65 1 67 2 50 1
3 1 2 1 52 3
1 95 85 25 57 1

5 6
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
*/
