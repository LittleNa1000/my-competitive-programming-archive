//      20/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct N{
    int d,i,j,k;
};
bool operator<(const N &a,const N &b){
    return a.d>b.d;
}
priority_queue<N> q;
int n,p,k,cost[25][25],r1,c1,r2,c2,d,jump,dist[25][25][25];
ii portal[25][25];
bool visited[25][25][25];
int x[]={0,1,0,-1};
int y[]={-1,0,1,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d %d",&n,&p,&k);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&cost[i][j]);
            portal[i][j]={-1,-1};
            for(int a=0;a<=k;++a){
                dist[i][j][a]=INT_MAX;
            }
        }
    }
    for(int i=0;i<p;++i){
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        portal[r1][c1]={r2,c2};
    }
    dist[0][0][k]=0;
    q.push({0,0,0,k});
    while(!q.empty()){
        d=q.top().d;
        int i=q.top().i;
        int j=q.top().j;
        jump=q.top().k;
        q.pop();
        if(visited[i][j][jump]) continue;
        visited[i][j][jump]=1;
        //printf("%d (%d,%d) %d\n",d,i,j,jump);
        if(i==n-1&&j==n-1){
            printf("%d",d);
            return 0;
        }
        if(portal[i][j].first!=-1&&jump&&!visited[portal[i][j].first][portal[i][j].second][jump-1]&&d<dist[portal[i][j].first][portal[i][j].second][jump-1]){
            q.push({d,portal[i][j].first,portal[i][j].second,jump-1});
            dist[portal[i][j].first][portal[i][j].second][jump-1]=d;
        }
        for(int a=0;a<4;++a){
            int i2=i+y[a];
            int j2=j+x[a];
            //printf("Walk (%d,%d) %d %d %d %d",i2,j2,visited[i2][j2][jump],d,cost[i2][j2],dist[i2][j2][jump]);
            if(i2>=0&&i2<n&&j2>=0&&j2<n&&!visited[i2][j2][jump]&&d+cost[i2][j2]<dist[i2][j2][jump]){
                dist[i2][j2][jump]=d+cost[i2][j2];
                //printf(" add to q");
                q.push({d+cost[i2][j2],i2,j2,jump});
            }
            //printf("\n");
        }
    }
}