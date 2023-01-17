//                      9/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int dist[50012][35];
bool visited[50012][35];
int order[50012];
int V,E,L,s,t,u,v,w,d,l;
vector<ii> edge[50012];
priority_queue<iii,vector<iii>,greater<iii> > pq;
int main(){
    scanf("%d %d %d %d %d",&V,&E,&L,&s,&t);
    --s;
    --t;
    for(int i=0;i<V;++i){
        scanf("%d",&order[i]);
        for(int j=0;j<L;++j){
            dist[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<E;++i){
        scanf("%d%d%d",&u,&v,&w);
        edge[u-1].push_back({w,v-1});
    }
    pq.push({0,{s,0}});
    while(!pq.empty()){
        u=pq.top().second.first;
        d=pq.top().first;
        l=pq.top().second.second;
        pq.pop();
        if(visited[u][l]) continue;
        visited[u][l]=1;
        //printf("%d %d %d\n",u,d,l);
        if(u==t&&l==L-1){
            printf("%d",d);
            return 0;
        }
        if(l==order[u]-1) ++l;
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i].second;
            w=edge[u][i].first;
            if(dist[v][l]>d+w&&!visited[v][l]){
                dist[v][l]=d+w;
                pq.push({d+w,{v,l}});
            }
        }
    }
}