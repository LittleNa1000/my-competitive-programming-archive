//                  26/9/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,bool> > p;
int V,E,S,T,sumw,u,v,w,d;
bool ticket;
vector<pii> edge[100001];
bool visited[100001][2];
int dist[100001][2];
priority_queue<p,vector<p>,greater<p> > pq;
int main(){
    scanf("%d %d %d %d",&V,&E,&S,&T);
    for(int i=0;i<V;++i){
        dist[i][0]=INT_MAX;
        dist[i][1]=INT_MAX;
    }
    dist[S][0]=0;
    dist[S][1]=0;
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
        sumw+=w;
    }
    pq.push({0,{S,1}});
    while(!pq.empty()){
        d=pq.top().first;    u=pq.top().second.first;    ticket=pq.top().second.second;
        pq.pop();
        //printf("%d %d %d\n",d,u,ticket);
        if(u==T){
            printf("%d",sumw-d);
            break;
        }
        if(visited[u][1]&&visited[u][0]) continue;
        visited[u][ticket]=1;
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i].second;    w=edge[u][i].first;
            if(visited[v][1]&&visited[v][0]) continue;
            if(d+w<dist[v][ticket]){
                pq.push({d+w,{v,ticket}});
                dist[v][ticket]=d+w;
            }
            if(ticket){
                pq.push({d,{v,0}});
                dist[v][0]=d;
            }
        }
    }
}