//                      12/10/2563
#include<bits/stdc++.h> // maybe dfs, visited instead of in_queue
using namespace std;
queue<int> q;
int n,m,cnt,node,x2,y2;
int x[100001],y[100001];
vector<int> edge[100001];
void bfs(int source,vector<bool> visited){
    //for(int i=0;i<visited.size();++i) printf("%d ",visited[i]);
    //printf("\n");
    q.push(source);
    while(!q.empty()){
        node=q.front();
        q.pop();
        if(visited[node]) continue;
        ++cnt;
		visited[node]=1;
        //printf("%d ",node);
        for(int i=0;i<edge[node].size();++i){
            if(!visited[edge[node][i]]&&!(node==x2&&edge[node][i]==y2)&&!(node==y2&&edge[node][i]==x2)){
                q.push(edge[node][i]);
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d %d",&x[i],&y[i]);
        edge[x[i]].push_back(y[i]);
        edge[y[i]].push_back(x[i]);
    }
    vector<bool> vst(n+1,0);
    for(int i=0;i<m;++i){
        cnt=0;
        x2=x[i];
        y2=y[i];
        bfs(y[i],vst);
        //printf("(%d,%d,%d,%d) \n",x[i],y[i],cnt,abs(n-cnt));
        printf("%d ",cnt*(abs(n-cnt)));
    }
}
