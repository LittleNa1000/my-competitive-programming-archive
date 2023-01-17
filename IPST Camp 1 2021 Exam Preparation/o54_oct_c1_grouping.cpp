//                      12/1/2564
#include<bits/stdc++.h>
using namespace std;
long long mx,l,r,n,k,ans,g,sum,m;
long long a[10012];
bool b;
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
        mx=max(mx,a[i]);
    }
    l=mx,r=2e9;
    while(l<=r){
        m=(l+r)/2;
        sum=0;
        g=1;
        for(int i=0;i<n;++i){
            if(sum+a[i]<=m){
                sum+=a[i];
            }
            else{
                sum=a[i];
                g++;
            }
        }
        if(g<k){
            r=m-1;
        }
        else{
            l=m+1;
            if(g==k){
                b=1;
                ans=max(ans,m);
            }
        }
    }
    if(b) printf("%lld",ans);
    else printf("IMPOSSIBLE");
}