//                      18/1/2564
#include<bits/stdc++.h>// 0-25 'A' - 'Z' , 26-51 'a' - 'z'
using namespace std;// or char itoc(int n){}
typedef pair<int,char> ic;
int E,d,w;
char u,v;
bool visited[52];
vector<ic> edge[52];
priority_queue<ic,vector<ic>,greater<ic>> pq;
int dist[52];
int ctoi(char ch){
    if(ch>='A'&&ch<='Z') return ch-'A';
    return ch-'a'+26;
}
int main(){
    scanf("%d",&E);
    for(int i=0;i<E;++i){
        cin>>u>>v>>w;
        edge[ctoi(u)].push_back({w,v});
        edge[ctoi(v)].push_back({w,u});
    }
    for(int i=0;i<=51;++i){
        dist[i]=INT_MAX;
    }
    dist[25]=0; //  'Z'
    pq.push({0,'Z'});
    while(!pq.empty()){
        d=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(visited[ctoi(u)]) continue;
        visited[ctoi(u)]=1;
        if(u>='A'&&u<'Z'){
            printf("%c %d",u,d);
            return 0;
        }
        for(int i=0;i<edge[ctoi(u)].size();++i){
            w=edge[ctoi(u)][i].first;
            v=edge[ctoi(u)][i].second;
            if(d+w<dist[ctoi(v)]&&!visited[ctoi(v)]){
                dist[ctoi(v)]=d+w;
                pq.push({d+w,v});
            }
        }
    }
}