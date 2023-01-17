//      19/2/2564 or chk nearby edge to find mincost
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct E{
    int i1,j1,i2,j2,w;
    bool mst;
};
vector<E> edge;
int ans,w,l=1,r=1000000000,n,m,mst_cnt,cnt;
ii u,v;
ii par[405][405][32];
ii find_par(ii x){
    //if(par[x]==x) return x;
    if(par[x.first][x.second][cnt]==x) return x;
    //return par[x]=find_par(par[x]);
    return par[x.first][x.second][cnt]=find_par(par[x.first][x.second][cnt]);
}
bool sbw(const E &a,const E &b){
    if(a.mst&&!b.mst){
        return a.w+m-0.5<b.w;
    }
    if(b.mst&&!a.mst){
        return a.w<b.w+m-0.5;
    }
    return a.w<b.w;
}
bool MST(){
    mst_cnt=0;
    //printf("\nMST #%d, (%d,%d,%d)\n",cnt,l,m,r);
    for(int i=0;i<edge.size();++i){
        if(mst_cnt+1>=n*m) break;
        //printf("chk %d (%d,%d) (%d,%d) %d %d",i,edge[i].i1,edge[i].j1,edge[i].i2,edge[i].j2,edge[i].w,edge[i].mst);
        u=find_par({edge[i].i1,edge[i].j1});
        v=find_par({edge[i].i2,edge[i].j2});
        if(u!=v){
            //printf(" added");
            if(!edge[i].mst){
                return 0;
            }
            ++mst_cnt;
            if((u.first*401)+u.second<(v.first*401)+v.second){
                par[v.first][v.second][cnt]=par[u.first][u.second][cnt];
            }
            else{
                par[u.first][u.second][cnt]=par[v.first][v.second][cnt];
            }
        }
        //printf("\n");
    }
    return 1;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m-1;++j){
            scanf("%d",&w);
            edge.push_back({i,j,i,j+1,w,0});
        }
        if(i+1!=n){
            for(int j=0;j<m;++j){
                scanf("%d",&w);
                edge.push_back({i,j,i+1,j,w,0});
                for(int k=0;k<32;++k) par[i][j][k]={i,j};
            }
        }
    }
    for(int j=0;j<m;++j) for(int k=0;k<32;++k) par[n-1][j][k]={n-1,j};
    sort(edge.begin(),edge.end(),sbw);
    //printf("\nMST #%d\n",cnt);
    for(int i=0;i<edge.size();++i){
        if(mst_cnt+1>=n*m) break;
        //printf("chk %d (%d,%d) (%d,%d) %d %d",i,edge[i].i1,edge[i].j1,edge[i].i2,edge[i].j2,edge[i].w,edge[i].mst);
        u=find_par({edge[i].i1,edge[i].j1});
        v=find_par({edge[i].i2,edge[i].j2});
        if(u!=v){
            ++mst_cnt;
            edge[i].mst=1;
            //printf(" added");
            if((u.first*401)+u.second<(v.first*401)+v.second){
                par[v.first][v.second][cnt]=par[u.first][u.second][cnt];
            }
            else{
                par[u.first][u.second][cnt]=par[v.first][v.second][cnt];
            }
        }
        //printf("\n");
    }
    while(l<=r){
        m=(l+r)/2;
        ++cnt;
        // for(int i=0;i<edge.size();++i){
        //     if(edge[i].mst){
        //         edge[i].w=ori_w+m;
        //     }
        // }
        sort(edge.begin(),edge.end(),sbw);
        //mst()=1 Still the same => add m
        //else decrease m
        if(MST()){
            l=m+1;
            ans=max(ans,m);
        }
        else{
            r=m-1;
        }
    }
    printf("%d",ans);
    // cnt++;
    // m=13;
    // sort(edge.begin(),edge.end(),sbw);
    // if(MST()) printf("YESS");
    // else printf("NOOO");
}