#include "hoax.h"
#include<bits/stdc++.h>
using namespace std;
// Maybe using undirected graph instead of dsu
int par[200005],sz[200005],rnk[200005];
int u,v;
bool con;
int find_par(int x){
  if(x==par[x]) return x;
  return par[x]=find_par(par[x]);
}
void init(int N, int S, vector<int> T,
          vector<vector<int>> A, vector<vector<int>> B) {
  for(int i=0;i<N;++i){
    par[i]=i;
    sz[i]=1;
  }
  // if already connected then continue;
  for(int i=0;i<N-1;++i){
    for(int j=i+1;j<N;++j){
      u=find_par(i);
      v=find_par(j);
      if(u!=v){
        //  Compare i and j
        con=0;
        for(int a=0;a<T[i];++a){
          for(int b=0;b<T[j];++b){
            if((A[i][a]<=A[j][b]&&A[j][b]<=B[i][a])||(A[i][a]<=B[j][b]&&B[j][b]<=B[i][a])||
               (A[j][b]<=A[i][a]&&A[i][a]<=B[j][b])||(A[j][b]<=B[i][a]&&B[i][a]<=B[j][b])){
                 //printf("%d , %d connect\n",i,j);
                 con=1;
                 break;
              }
          }
          if(con) break;
        }
        if(con){
          if(rnk[u]>rnk[v]){
            par[v]=par[u];
            sz[u]+=sz[v];
          }
          else{
            par[u]=par[v];
            sz[v]+=sz[u];
          }
          if(rnk[u]==rnk[v]) ++rnk[u];
        }
      }
    }
  }
}

int count_users(int P) {
  u=find_par(P);
  return sz[u];
}
