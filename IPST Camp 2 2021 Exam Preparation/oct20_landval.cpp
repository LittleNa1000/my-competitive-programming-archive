//              5/5/2564
#include<bits/stdc++.h>
using namespace std;
int seg[10000005];
int n,m,a,b,k,x,sum,T;
void update(int idx,int l,int r){
    if(l>r) return ;
    if(r<a||b<l){

    }
    else if(a<=l&&r<=b){
        seg[idx]+=k;
    }
    else{
        int m=(l+r)/2;
        update((idx*2)+1,l,m);
        update((idx*2)+2,m+1,r);
    }
    return ;
}
void getval(int idx,int l,int r){
    if(l>r) return ;
    int m=(l+r)/2;
    sum+=seg[idx];
    if(l==r) return ;
    if(x>m){
        return getval((idx*2)+2,m+1,r);
    }
    else{
        return getval((idx*2)+1,l,m);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d",&T);
        if(T==1){
            scanf("%d %d %d",&a,&b,&k);
            update(0,1,n);
        }
        else{
            scanf("%d",&x);
            sum=0;
            getval(0,1,n);
            printf("%d\n",sum);
        }
    }
}