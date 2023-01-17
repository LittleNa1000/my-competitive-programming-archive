//                  23/11/2563 or dist[][][]
#include<bits/stdc++.h>
using namespace std;
struct t{
    int i,j,d;
    bool b;
};
queue<t> q;
int x[]={0,1,0,-1};
int y[]={-1,0,1,0};
bool bomb,grid[155][155];
int dist[155][155][3];
bool visited[155][155][3],zone[155][155][3];
int d,n,m,si,sj,fi,fj,cnt,pi,pj;
void f(int a,int b,int idx){
    queue<pair<int,int> > qq;
    qq.push({a,b});
    while(!qq.empty()){
        int i=qq.front().first;
        int j=qq.front().second;
        qq.pop();
        if(zone[i][j][idx]) continue;
        zone[i][j][idx]=1;
        for(int k=0;k<4;++k){
            pi=i+y[k]; pj=j+x[k];
            if(pi>=0&&pi<n&&pj>=0&&pj<m&&!zone[pi][pj][idx]&&grid[pi][pj]) qq.push({pi,pj});
        }
    }
}
int main(){
    scanf("%d %d %d %d %d %d",&n,&m,&si,&sj,&fi,&fj);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&grid[i][j]);
        }
    }
    f(si-1,sj-1,0);
    f(fi-1,fj-1,1);
    // for(int i=0;i<n;++i) {
    //     for(int j=0;j<m;++j) printf("(%d,%d) ",zone[i][j][0],zone[i][j][1]); printf("\n");
    // }
    bool a,b;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!grid[i][j]){
                a=0; b=0;
                for(int k=0;k<4;++k){
                    pi=i+y[k]; pj=j+x[k];
                    if(pi>=0&&pi<n&&pj>=0&&pj<m){
                        if(zone[pi][pj][0]) a=1;
                        if(zone[pi][pj][1]) b=1;
                    }
                }
                if(a&&b) cnt++;
            }
        }
    }
    q.push({si-1,sj-1,1,1});
    while(!q.empty()){
        int i=q.front().i;
        int j=q.front().j;
        bomb=q.front().b;
        d=q.front().d;
        q.pop();
        if(visited[i][j][bomb]){
            continue;
        }
        visited[i][j][bomb]=1;
        if(i==fi-1&&j==fj-1){
            printf("%d\n%d",cnt,d);
            return 0;
        }
        //printf("(%d,%d) %d %d\n",i+1,j+1,bomb,d);
        for(int k=0;k<4;++k){
            pi=i+y[k]; pj=j+x[k];
            if(pi>=0&&pi<n&&pj>=0&&pj<m&&!visited[pi][pj][bomb]){
                if(grid[pi][pj]){
                    q.push({pi,pj,d+1,bomb});
                }
                else if(!grid[pi][pj]&&bomb){
                    q.push({pi,pj,d+1,0});
                }
            }
        }
    }
    //printf("%d\n%d",cnt,dist[fi-1][fj-1]);
}
