//                      22/11/2563
#include<bits/stdc++.h>
using namespace std;
struct t{
    int i,j;
};
queue<t> q,tg;
int n,m,c,ans;
int dist[2005][2005];
string grid[2005];
int x[]={0,1,0,-1};
int y[]={-1,0,1,0};
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) dist[i][j]=INT_MAX;
    for(int i=0;i<n;++i){
        cin>>grid[i];
        for(int j=0;j<m;++j){
            if(grid[i][j]=='X'){
                q.push({i,j});
                dist[i][j]=0;
            }
            else if(grid[i][j]=='A'){
                tg.push({i,j});
            }
        }
    }
    int i,j;
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        q.pop();
        for(int k=0;k<4;++k){
            int vi=i+y[k],vj=j+x[k];
            if(vi>=0&&vi<n&&vj>=0&&vj<m&&grid[vi][vj]!='W'&&dist[vi][vj]>dist[i][j]+1){
                dist[vi][vj]=dist[i][j]+1;
                q.push({vi,vj});
            }
        }
    }
    while(!tg.empty()){
        i=tg.front().i;
        j=tg.front().j;
        tg.pop();
        if(dist[i][j]!=INT_MAX){
            ++c;
            ans+=dist[i][j]*2;
        }
    }
    printf("%d %d",c,ans);
}