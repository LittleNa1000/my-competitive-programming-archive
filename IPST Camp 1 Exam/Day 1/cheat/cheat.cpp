#include "cheat.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> edge[200005];
int par[200005],cnt=1,tg;
bool ini;
void initial(){
  for(int i=1;i<=200000;++i){
    par[i]=i;
  }
  ini=1;
}
int find_par(int x){
  if(par[x]==x) return x;
  return par[x]=find_par(par[x]);
}
void cheat(int person1, int person2)
{
  if(!ini) initial();
  int u=find_par(person1);
  int v=find_par(person2);
  if(u!=v){
    int w=cnt;
    par[max(u,v)]=par[min(u,v)];
    edge[person1].push_back({person2,w});
    edge[person2].push_back({person1,w});
  }
  ++cnt;
  // if(1){
  //   for(int i=1;i<=100;++i){
  //     for(int j=0;j<edge[i].size();++j){
  //       printf("%d (%d,%d/0\n",i,edge[i][j].first,edge[i][j].second);
  //     }
  //     printf("\n");
  //     if(i==4) i=99;
  //   }
  // }
}
int dfs(int u,int pre,int mx){
  //printf("dfs(%d,%d,%d)\n",u,pre,mx);
  int g=0;
  if(u==tg) return mx;
  for(int i=0;i<edge[u].size();++i){
    int w=edge[u][i].second;
    int v=edge[u][i].first;
    //printf("goto ? %d %d\n",v,w);
    if(v!=pre){
      g=max(g, dfs(v,u,max(mx,w)));
    }
  }
  return g;
}
int investigate(int person1, int person2)
{
  if(!ini) initial();
  int u=find_par(person1);
  int v=find_par(person2);
  if(u!=v) return -1;
  tg=person2;
  return dfs(person1,-1,-1);
}
