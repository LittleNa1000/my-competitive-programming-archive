//              3/5/2564
#include<bits/stdc++.h>
using namespace std;
bool visited[505][505];
int tcost[505][505],cost[505][505];
int n,d,x,y,mx;
int solve(int x,int y){
    int mn=min(x,y);
    if(visited[x][y]) return tcost[x][y];
    visited[x][y]=1;
    //printf("%d %d %d\n",tcost[x][y],x,y);
    if(mn==2) return tcost[x][y]=cost[1][x]+cost[1][y];
    
    return tcost[x][y]=min(solve(mn-1,y)+cost[mn-1][x],solve(x,mn-1)+cost[mn-1][y]);;
}
int main(){
    scanf("%d",&n);
    {
        int i,j=0;
        for(i=1;i<n;++i){
            for(j=i+1;j<=n;++j){
                scanf("%d",&cost[i][j]);
            }
        }
    }
    //maybe 2d loop
    printf("%d",solve(n,n));
}