//LAZANTA dist[V][2][2][2][2]
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> edge[50012];
int V,E,u,v,w,dst;
string str1,str2;
bool visited[50012][2][2][2][2];
int dist[50012][2][2][2][2];
int main(){
    scanf("%d %d",&V,&E);
    cin>>str1>>str2;
    for(int i=0;i<E;++i){
        scanf("%d%d%d",&u,&v,&w);
        edge[u-1].push_back({v-1,w});
        edge[v-1].push_back({u-1,w});
    }
    for(int i=0;i<V;++i){
        for(int a=0;a<2;++a){
            for(int b=0;b<2;++b){
                for(int c=0;c<2;++c){
                    for(int d=0;d<2;++d) dist[i][a][b][c][d]=INT_MAX;
                }
            }
        }
    }
    bool a=0,b=0,c=0,d=0;
    for(int i=0;i<str1.length();++i){
        if(str1[i]=='X') a=1;
        if(str1[i]=='M') b=1;
        if(str1[i]=='A') c=1;
        if(str1[i]=='S') d=1;
    }
    dist[V-1][a][b][c][d]=0;
    typedef pair<bool,bool> pbb;
    typedef pair<pbb,pbb> ppbb;
    typedef pair<pii,ppbb> node;
    priority_queue<node,vector<node>,greater<node>> pq;
    pq.push({{0,V-1},{{a,b},{c,d}}});
    while(!pq.empty()){
        dst=pq.top().first.first;
        u=pq.top().first.second;
        a=pq.top().second.first.first;
        b=pq.top().second.first.second;
        c=pq.top().second.second.first;
        d=pq.top().second.second.second;
        pq.pop();
        if(visited[u][a][b][c][d]) continue;
        visited[u][a][b][c][d]=1;
        bool pa=a,pb=b,pc=c,pd=d;
        if(u!=0){
            if(str2[u-1]=='X') pa=1;
            else if(str2[u-1]=='M') pb=1;
            else if(str2[u-1]=='A') pc=1;
            else if(str2[u-1]=='S') pd=1;
        }
        //printf("u%d dst%d [%d,%d,%d,%d]\n",u,dst,a,b,c,d);
        if(u==0&&pa&&pb&&pc&&pd){
            printf("%d",dst);
            return 0;
        }
        for(int i=0;i<edge[u].size();++i){
            v=edge[u][i].first;
            w=edge[u][i].second;
            if(!visited[v][pa][pb][pc][pd]&&dist[v][pa][pb][pc][pd]>dst+w){
                dist[v][pa][pb][pc][pd]=dst+w;
                pq.push({{dst+w,v},{{pa,pb},{pc,pd}}});
            }
        }
    }
}