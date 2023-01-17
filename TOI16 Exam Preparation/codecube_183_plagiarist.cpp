//                  26/11/2563
#include<bits/stdc++.h>
using namespace std;
int fen[200005],arr[200005];
int n,x,l,r,m,mid;
int sum(int idx){
    int res=0;
    while(idx>0){
        res+=fen[idx];
        idx=idx-(idx&-idx);
    }
    return res;
}
void upd(int idx,int val){
    while(idx<=n){
        fen[idx]+=val;
        idx=idx+(idx&-idx);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
        upd(i,1);
    }
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        l=1;
        r=n;
        while(l<r){
            mid=(l+r)/2;
            m=sum(mid);
            //printf("To find %d, [%d,%d,%d] sum=%d\n",x,l,mid,r,m);
            if(m>=x) r=mid;
            else l=mid+1;
        }
        printf("%d\n",arr[l]);
        upd(l,-1);
    }
}