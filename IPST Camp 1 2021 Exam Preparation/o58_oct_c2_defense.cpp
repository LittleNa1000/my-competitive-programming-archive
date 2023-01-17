//                      14/1/2564
#include<bits/stdc++.h>
using namespace std;
int mn,idx,n,k,ans;
int cost[3005];
bool tower[3005];
void build(int l,int r){
    r=min(r,n-1);
    mn=INT_MAX,idx=0;
    for(int i=l;i<=r;++i){
        if(tower[i]) continue;
        if(mn>=cost[i]){
            mn=cost[i];
            idx=i;
        }
    }
    ans+=cost[idx];
    tower[idx]=1;
    //printf("at %d\n",idx);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&cost[i]);
    }
    build(0,k-1);
    build(0,k-1);
    for(int i=1;i<=n-k;++i){
        if(tower[i-1]) build(i,i+k-1);
    }
    printf("%d",ans);
}