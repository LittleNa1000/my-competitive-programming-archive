/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
//typedef pair<pii,pii> ppi;
map<pii,int> mp;
//bool inf[5012][5012],spr[5012][5012];
//int h[5012][5012];
int n,t,f,s,Q,x,y,ninf,sq,px,py,h,inf;
int ii[]={-1,0,1,0};
int jj[]={0,1,0,-1};
bool spr;
struct ppi{
    int x,y,h;
    bool inf,spr;
};
queue<ppi> q;
int main(){
    scanf("%d%d%d%d%d",&n,&t,&f,&s,&Q);
    for(int i=0;i<n;++i){
        spr=0;
        scanf("%d%d",&x,&y);
        scanf("%d%d",&h,&inf);
        //printf("{%d,%d,%d%d}\n",x,y,h[x][y],inf[x][y]);
        if(inf) ninf++;
        if(inf&&h<=s){
            spr=1;
        }
        q.push({x,y,h,inf,spr});
    }
    for(int time=0;time<t;++time){
        //printf("t=%d ",time);
        for(int i=0;i<q.size();++i){
            x=q.front().x;
            y=q.front().y;
            h=q.front().h;
            inf=q.front().inf;
            spr=q.front().spr;
            q.pop();
            //printf("[%d,%d] ",x,y);
            if(inf) {h--;
                if(spr){
                    mp[{x,y}]=f-h;
                }
                //printf("(%d,%d)h,down ",x,y);
            }
            q.push({x,y,h,inf,spr});
        }
        for(int i=0;i<q.size();++i){
            x=q.front().x;
            y=q.front().y;
            h=q.front().h;
            inf=q.front().inf;
            spr=q.front().spr;
            q.pop();
            if(inf&&h<=Q){
                //printf("(%d,%d)h%d to Q ",x,y,h[x][y]);
                ++sq;
                --ninf;
                mp[{x,y}]=0;
                //h[x][y]=0;
                //spr[x][y]=0;
                //inf[x][y]=0;
            }
            else{
                q.push({x,y,h,inf,spr});
            }
        }
        for(int i=0;i<q.size();++i){
            x=q.front().x;
            y=q.front().y;
            h=q.front().h;
            inf=q.front().inf;
            spr=q.front().spr;
            q.pop();
            if(!inf){
                long sum=0;
                for(int k=0;k<4;++k){
                    px=x+jj[k];
                    py=y+ii[k];
                    sum+=mp[{px,py}];
                }
                if(sum>=h) {
                    inf=1;
                    ninf++;
                    //printf("(%d,%d) to inf ",x,y);
                }
            }
            q.push({x,y,h,inf,spr});
        }
        for(int i=0;i<q.size();++i){
            x=q.front().x;
            y=q.front().y;
            h=q.front().h;
            inf=q.front().inf;
            spr=q.front().spr;
            q.pop();
            if(inf&&h<=s&&!spr){
                spr=1;
                //printf("(%d,%d)spr ",x,y);
            }
            q.push({x,y,h,inf,spr});
        }
        //printf("\n");
    }
    printf("%d\n%d",ninf,sq);
}
