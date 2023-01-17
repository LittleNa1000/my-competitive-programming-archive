//      20/2/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int d,i,j;
};
bool operator<(const N &a,const N &b){
    return a.d>b.d;
}
bool visited[20][20][205],grid[20][20][205];
int T,n,m,d,i2,j2,dist[20][20][205],di,dj,t=1;
int x[]={0,1,0,-1};
int y[]={-1,0,1,0};
string str;
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        priority_queue<N> pq;
        for(int i=1;i<=n;++i){
            cin>>str;
            for(int j=1;j<=m;++j){
                dist[i][j][T]=INT_MAX;
                if(str[j-1]=='O'){
                    dist[i][j][T]=0;
                    pq.push({0,i,j});
                    grid[i][j][T]=1;
                }
                else if(str[j-1]=='X'){
                    di=i;
                    dj=j;
                    grid[i][j][T]=1;
                }
                else if(str[j-1]=='.'){
                    grid[i][j][T]=1;
                }
            }
        }
        while(!pq.empty()){
            d=pq.top().d;
            int i=pq.top().i;
            int j=pq.top().j;
            pq.pop();
            if(visited[i][j][T]) continue;
            visited[i][j][T]=1;
            //printf("%d (%d,%d)\n",d,i,j);
            if(i==di&&j==dj){
                break;
            }
            if(!grid[i-1][j][T]||!grid[i+1][j][T]||!grid[i][j-1][T]||!grid[i][j+1][T]){
                for(int k=0;k<4;++k){
                    i2=i;
                    j2=j;
                    while(grid[i2+y[k]][j2+x[k]][T]){
                        i2+=y[k];
                        j2+=x[k];
                    }
                    //printf("Going to Warp %d (%d,%d)\n",d+1,i2,j2);
                    if(grid[i2][j2][T]&&!visited[i2][j2][T]&&d+1<dist[i2][j2][T]){
                        pq.push({d+1,i2,j2});
                        //printf("Warp %d (%d,%d)\n",d+1,i2,j2);
                        dist[i2][j2][T]=d+1;
                    }
                }
            }
            for(int k=0;k<4;++k){
                i2=i+y[k];
                j2=j+x[k];
                if(grid[i2][j2][T]&&!visited[i2][j2][T]&&d+1<dist[i2][j2][T]){
                    pq.push({d+1,i2,j2});
                    //printf("Walk %d (%d,%d)\n",d+1,i2,j2);
                    dist[i2][j2][T]=d+1;
                }
            }
        }
        printf("Case #%d: ",t++);
        if(dist[di][dj][T]==INT_MAX) printf("THE CAKE IS A LIE\n");
        else printf("%d\n",d);
    }
}