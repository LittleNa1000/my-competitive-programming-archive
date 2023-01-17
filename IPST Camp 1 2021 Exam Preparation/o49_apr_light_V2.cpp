//      24/2/2564
#include<bits/stdc++.h>
using namespace std;
int sz=2,lp[100005],rp[100005],val[100005],x,L,n,sum;
bool red;
void ins(int x,int idx){
    if(idx==0){
        return ;  
    }
    if(val[idx]>x){
        if(lp[idx]!=0) ins(x,lp[idx]);
        else{
            lp[idx]=sz;
            val[sz]=x;
            sz++;
        }
    }
    else{
        if(rp[idx]!=0) ins(x,rp[idx]);
        else{
            rp[idx]=sz;
            val[sz]=x;
            sz++;
        }
    }
}
void dfs(int l,int r,int idx){
    if(!idx){
        //printf("%d %d %d %d\n",l,r,idx,red);
        if(!red) sum+=(r-l+1);
        red=!red;
        return ;
    }
    dfs(l,val[idx],lp[idx]);
    dfs(val[idx]+1,r,rp[idx]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d",&L,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(!i) val[1]=x;
        else ins(x,1);
        sum=0;
        red=0;
        dfs(1,L,1);
        printf("%d\n",sum);
        // for(int i=0;i<=n;++i){
        //     printf("%d val%d left%d right%d\n",i,val[i],lp[i],rp[i]);
        // }
    }
}