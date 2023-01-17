//              7/1/2564
#include<bits/stdc++.h>
using namespace std;
long long n,k,pz,m,ans=2e9,l,r,mn=1e9;
long long x[100012];
int main(){
    scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%lld",&x[i]);
        mn=min(mn,x[i]);
    }
    l=n,r=2e9;//min(2e9,mn*k)
    while(l<=r){
        pz=n;
        m=(l+r)/2;
        for(int i=0;i<n;++i){
            pz+=m/x[i];
        }
        if(pz>=k){
            ans=min(ans,m);
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    printf("%lld",ans);
}