//                      12/10/2563 //maybe qsum
#include<bits/stdc++.h>
using namespace std;
long long int n,x,y,mx,sum,ans;
long int A[100001],B[100001];
int main(){
    scanf("%lld %lld %lld",&n,&x,&y);
    for(int i=0;i<n;++i){
        scanf("%lld",&A[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&B[i]);
    }
    for(int i=0;i<x;++i){
        sum+=A[i];
    }
    mx=sum;
    for(int i=x;i<n;++i){
        sum=sum+A[i]-A[i-x];
        mx=max(sum,mx);
    }
    //printf("%d ",mx);
    ans+=(mx*y);
    mx=0;
    sum=0;
    for(int i=0;i<y;++i){
        sum+=B[i];
    }
    mx=sum;
    for(int i=y;i<n;++i){
        sum=sum+B[i]-B[i-y];
        mx=max(sum,mx);
    }
    //printf("%d ",mx);
    ans+=(mx*x);
    printf("%lld",ans);
}