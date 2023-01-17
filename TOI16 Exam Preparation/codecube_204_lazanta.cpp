//                      25/10/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool visited[50001][6],found[30];
vector<pii> edge[50001];
int source,ans,u,v,w,V,E,d;
string str,card;
int dist[50001][6];
void sp(int k){
    //printf("Entering #%d (k)\n",k);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    dist[source][k]=0;
    pq.push({0,source});
    while(!pq.empty()){
        d=pq.top().first; u=pq.top().second;
        pq.pop();
        if(visited[u][k]) continue ;
        visited[u][k]=1;
        //printf("Visit(%d,%d)\n",d,u+1);
        if(k==0&&u==0){
            ans+=d;
            //printf("Ans found, Returning\n");
            return ;
        }
        else if(u!=0&&(card[u-1]=='X'||card[u-1]=='M'||card[u-1]=='A'||card[u-1]=='S')){
            if(found[card[u-1]-'A']==0){
                found[card[u-1]-'A']=1;
                source=u;
                ans+=d;
                //printf("%c Found, Returning\n",card[u-1]);
                return ;
            }
        }
        //printf("Finding path...\n");
        for(int i=0;i<edge[u].size();++i){
            w=edge[u][i].first;
            v=edge[u][i].second;
            if(d+w<dist[v][k]&&!visited[v][k]){
                dist[v][k]=d+w;
                pq.push({d+w,v});
            }
        }
    }
}
int main(){
    scanf("%d %d",&V,&E);
    cin>>str>>card;
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        edge[u-1].push_back({w,v-1});
        edge[v-1].push_back({w,u-1});
    }
    for(int i=0;i<str.length();++i){
        if(str[i]!='_'){
            found[str[i]-'A']=1;
        }
    }
    found[card[V-2]-'A']=1;
    //for(int i=0;i<30;++i) printf("%c=%d ",i+'A',found[i]); printf("\n");
    for(int i=0;i<V;++i){
        for(int j=0;j<6;++j) dist[i][j]=INT_MAX;
    }
    source=V-1;
    for(int i=1;!(found['X'-'A']&&found['M'-'A']&&found['A'-'A']&&found['S'-'A']);++i){
        sp(i); //dist[]?
    }
    sp(0);
    printf("%d",ans); //lld?
}