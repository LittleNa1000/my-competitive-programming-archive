//                      21/10/2563
#include<bits/stdc++.h>
using namespace std;
int E,t,u,v,w,d,ans,s;
int arr[100001];
queue<pair<int,int> > q;
vector<pair<int,int> > edge[100001];
bool visited[100001];
int main(){
    scanf("%d %d",&E,&t);
    for(int i=0;i<E-1;++i){
        scanf("%d %d %d",&u,&v,&w);

        edge[u-1].push_back({w,v-1});
        edge[v-1].push_back({w,u-1});
    }
    q.push({0,0}); //random source
    while(!q.empty()){
        d=q.front().first;   u=q.front().second;
        q.pop();
        if(visited[u]) continue;
        visited[u]=1;
        for(int i=0;i<edge[u].size();++i){
            w=edge[u][i].first;
                v=edge[u][i].second;
            if(!visited[v]){
                    
                arr[v]=d^w;
                q.push({d^w,v});
            }
            
        }
    }
    //for(int i=0;i<E-1;++i) printf("(%d,%d) ",i+1,arr[i]);
    while(t--){
        scanf("%d %d",&u,&v);
        ans=arr[v-1]^arr[u-1];
        printf("%d\n",ans);
    }
}