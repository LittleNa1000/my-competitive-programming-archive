//                  31/10/2563
#include<bits/stdc++.h>
using namespace std;
struct N{
    int pi,pj,ps;
};
short x[]={0,1,0,-1,-1,-1,1,1};
short y[]={-1,0,1,0,-1,1,-1,1};
int n,m,step,i,j;
bool visited[98][101][1250]; //or [][][2000] or bitset
short a[98][101];
queue<struct N> q;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    if(a[n/2][0]==1) q.push({n/2,0,1});
    if(a[(n/2)-1][0]==1) q.push({(n/2)-1,0,1});
    if(a[(n/2)+1][0]==1) q.push({(n/2)+1,0,1});
    while(!q.empty()){
        i=q.front().pi;   j=q.front().pj;   step=q.front().ps;
        q.pop();
        if(i==n/2&&j==m-1){
            printf("%d",step);
            return 0;
        }
        if(visited[i][j][step]) continue;
        visited[i][j][step]=1;
        //printf("(%d,%d) Step%d\n",i,j,step);
        for(int k=0;k<=3;++k){
            //printf("ni%d nj%d a%d\n",i+y[k],j+x[k],a[i+y[k]][j+x[k]]);
            if(i+y[k]>=0&&i+y[k]<=n-1&&j+x[k]>=0&&j+x[k]<=m-1&&a[i+y[k]][j+x[k]]!=0&&(step+1)%a[i+y[k]][j+x[k]]==0&&!visited[i+y[k]][j+x[k]][step+1]){
                q.push({i+y[k],j+x[k],step+1});
            }
        }
        if(i%2){
            for(int k=4;k<=5;++k){
                //printf("ni%d nj%d a%d\n",i+y[k],j+x[k],a[i+y[k]][j+x[k]]);
                if(i+y[k]>=0&&i+y[k]<=n-1&&j+x[k]>=0&&j+x[k]<=m-1&&a[i+y[k]][j+x[k]]!=0&&(step+1)%a[i+y[k]][j+x[k]]==0&&!visited[i+y[k]][j+x[k]][step+1]){
                    q.push({i+y[k],j+x[k],step+1});
                }
            }
        }
        else{
            for(int k=6;k<=7;++k){
                //printf("ni%d nj%d a%d\n",i+y[k],j+x[k],a[i+y[k]][j+x[k]]);
                if(i+y[k]>=0&&i+y[k]<=n-1&&j+x[k]>=0&&j+x[k]<=m-1&&a[i+y[k]][j+x[k]]!=0&&(step+1)%a[i+y[k]][j+x[k]]==0&&!visited[i+y[k]][j+x[k]][step+1]){
                    q.push({i+y[k],j+x[k],step+1});
                }
            }
        }
    }

}