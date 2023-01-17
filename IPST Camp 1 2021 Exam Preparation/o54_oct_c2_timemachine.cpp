//                  24/1/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int d,x,y;
    bitset<10> v;
};
queue<N> q;
int n,m,k,x,y,dist,idx,ans,mn;
int tx[15],ty[15],p[15];
bitset<10> emp,visited;
bool miss;
int f(int x1,int y1,int x2,int y2){
    //printf("(%d,%d)->(%d,%d) = %f\n",x1,y1,x2,y2,(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))));
    return ceil(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;++i){
        scanf("%d %d %d",&tx[i],&ty[i],&p[i]);
        emp[i]=1;
        q.push({f(0,0,tx[i],ty[i])-p[i],tx[i],ty[i],emp});//Bug Here
        emp[i]=0;
    }
    ans=f(0,0,n-1,m-1);
    while(!q.empty()){
        dist=q.front().d;
        x=q.front().x;
        y=q.front().y;
        visited=q.front().v;
        q.pop();
        if(x==n-1&&y==m-1){
            ans=min(ans,dist);
            continue;
        }
        // push k+1 each time or push 2 each time
        mn=INT_MAX;
        idx=0;
        miss=0;
        for(int i=0;i<k;++i){
            if(!visited[i]&mn>f(x,y,tx[i],ty[i])){
                miss=1;
                idx=i;
                mn=f(x,y,tx[i],ty[i]);
            }
        }
        //printf("(%d,%d) d%d mn%d i%d m%d\n",x,y,dist,mn,idx,miss);
        if(!miss) ans=min(ans,dist+f(x,y,n-1,m-1));
        else{
            visited[idx]=1;
            q.push({dist-p[idx]+f(x,y,tx[idx],ty[idx]),tx[idx],ty[idx],visited});
            q.push({dist,x,y,visited});
        }
    }
    printf("%d",ans);
}