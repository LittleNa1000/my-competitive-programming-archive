//              3/5/2564
// maybe merge mirror into 1d vector
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct P{
    int x1,y1,x2,y2;
};
vector<vector<ii>> v_mirror,h_mirror;
vector<P> h_beam[2],v_beam[2];
int r,c,n,m,x,y,idx,cnt,a,b,mn1,mx1,mn2,mx2,mn_i=INT_MAX,mn_j=INT_MAX;
bool is_hole,k;
/*
MIRROR
0 = /
1 = \
DIRECTION
0 = North
1 = East
2 = South
3 = West
*/
void getpath(int i,int j,int tid){
    //printf("[%d %d %d]\n",i,j,tid);
    if(tid==0){
        idx=lower_bound(v_mirror[j].begin(),v_mirror[j].end(),make_pair(i,0))-v_mirror[j].begin();
        if(v_mirror[j].empty()||idx==0){
            v_beam[is_hole].push_back({i,j,1,j});
            return ;
        }
        --idx;
        v_beam[is_hole].push_back({i,j,v_mirror[j][idx].first,j});
        if(v_mirror[j][idx].second){
            return getpath(v_mirror[j][idx].first,j,3);
        }
        return getpath(v_mirror[j][idx].first,j,1);
    }
    else if(tid==2){
        idx=lower_bound(v_mirror[j].begin(),v_mirror[j].end(),make_pair(i,0))-v_mirror[j].begin();
        //printf("(%d,%d)\n",v_mirror[j][idx].first,v_mirror[j][idx].second);
        if(v_mirror[j].empty()||idx==v_mirror[j].size()-1){
            v_beam[is_hole].push_back({i,j,r,j});
            return ;
        }
        if(v_mirror[j][idx].first==i) ++idx;
        v_beam[is_hole].push_back({i,j,v_mirror[j][idx].first,j});
        if(v_mirror[j][idx].second){
            return getpath(v_mirror[j][idx].first,j,1);
        }
        return getpath(v_mirror[j][idx].first,j,3);
    }
    else if(tid==1){
        idx=lower_bound(h_mirror[i].begin(),h_mirror[i].end(),make_pair(j,0))-h_mirror[i].begin();
        if(h_mirror[i].empty()||h_mirror[i][idx].first==j&&idx==h_mirror[i].size()-1){
            h_beam[is_hole].push_back({i,j,i,c});
            return ;
        }
        if(h_mirror[i][idx].first==j) ++idx;
        h_beam[is_hole].push_back({i,j,i,h_mirror[i][idx].first});
        if(h_mirror[i][idx].second){
            return getpath(i,h_mirror[i][idx].first,2);
        }
        return getpath(i,h_mirror[i][idx].first,0);
    }
    else if(tid==3){
        idx=lower_bound(h_mirror[i].begin(),h_mirror[i].end(),make_pair(j,0))-h_mirror[i].begin();
        if(h_mirror[i].empty()||idx==0){
            h_beam[is_hole].push_back({i,j,i,1});
            return ;
        }
        --idx;
        h_beam[is_hole].push_back({i,j,i,h_mirror[i][idx].first});
        if(h_mirror[i][idx].second){
            return getpath(i,h_mirror[i][idx].first,0);
        }
        return getpath(i,h_mirror[i][idx].first,2);
    }
}
int main(){
    scanf("%d %d %d %d",&r,&c,&n,&m);
    h_mirror.resize(r+1);
    v_mirror.resize(c+1);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        h_mirror[x].push_back({y,0});
        v_mirror[y].push_back({x,0});
    }
    for(int i=0;i<m;++i){
        scanf("%d %d",&x,&y);
        h_mirror[x].push_back({y,1});
        v_mirror[y].push_back({x,1});
    }
    for(int i=1;i<=r;++i){
        sort(h_mirror[i].begin(),h_mirror[i].end());
    }
    for(int i=1;i<=c;++i){
        sort(v_mirror[i].begin(),v_mirror[i].end());
    }
    getpath(1,1,1);
    // for(int i=1;i<=r;++i){
    //     if(h_mirror[i].size()!=0) {printf("\n%d:\n",i); for(int j=0;j<h_mirror[i].size();++j) printf("[%d,%d] ",h_mirror[i][j].first,h_mirror[i][j].second);}
    // }
    // for(int i=1;i<=c;++i){
    //     if(v_mirror[i].size()!=0) {printf("\n%d:\n",i); for(int j=0;j<v_mirror[i].size();++j) printf("[%d,%d] ",v_mirror[i][j].first,v_mirror[i][j].second);}
    // }
    // for(int i=0;i<h_beam[0].size();++i){
    //     printf("%d %d %d %d\n",h_beam[is_hole][i].x1,h_beam[is_hole][i].y1,h_beam[is_hole][i].x2,h_beam[is_hole][i].y2);
    // }
    // for(int i=0;i<v_beam[0].size();++i){
    //     printf("%d %d %d %d\n",v_beam[is_hole][i].x1,v_beam[is_hole][i].y1,v_beam[is_hole][i].x2,v_beam[is_hole][i].y2);
    // }
    if(!h_beam[0].empty()&&!v_beam[0].empty()){    
        if((h_beam[0][h_beam[0].size()-1].x2==r&&h_beam[0][h_beam[0].size()-1].y2==c)
         ||(v_beam[0][v_beam[0].size()-1].x2==r&&v_beam[0][v_beam[0].size()-1].y2==c)){
            printf("0");
            return 0;
        }
    }
    is_hole=1;
    getpath(r,c,3);
    // for(int i=0;i<h_beam[1].size();++i){
    //     printf("%d %d %d %d\n",h_beam[is_hole][i].x1,h_beam[is_hole][i].y1,h_beam[is_hole][i].x2,h_beam[is_hole][i].y2);
    // }
    // for(int i=0;i<v_beam[1].size();++i){
    //     printf("%d %d %d %d\n",v_beam[is_hole][i].x1,v_beam[is_hole][i].y1,v_beam[is_hole][i].x2,v_beam[is_hole][i].y2);
    // }
    for(int c=0;c<=1;++c){
        for(int i=0;i<h_beam[k].size();++i){
            for(int j=0;j<v_beam[!k].size();++j){
                mn1=min(h_beam[k][i].y1,h_beam[k][i].y2);
                mx1=max(h_beam[k][i].y1,h_beam[k][i].y2);
                mn2=min(v_beam[!k][j].x1,v_beam[!k][j].x2);
                mx2=max(v_beam[!k][j].x1,v_beam[!k][j].x2);
                if((mx1>=v_beam[!k][j].y1&&mn1<=v_beam[!k][j].y1)
                &&(mx2>=h_beam[k][i].x1&&mn2<=h_beam[k][i].x1)){
                    a=h_beam[k][i].x1;
                    b=v_beam[!k][j].y1;
                    ++cnt;
                    if(mn_i>a||(mn_i==a&&mn_j>b)){
                        mn_i=a;
                        mn_j=b;
                    }
                }
            }
        }
        k=!k;
    }
    if(cnt==0) printf("impossible");
    else printf("%d %d %d",cnt,mn_i,mn_j);
}