//                      19/10/2563
#include<bits/stdc++.h>
using namespace std;
int ans,n,k,sum;
string str[100001];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        cin>>str[i];
    }
    for(int i=0;i<k;++i){
        if(str[i]=="UR") ++sum;
    }
    ans=max(ans,sum);
    for(int i=k;i<n;++i){
        if(str[i]=="UR") ++sum;
        if(str[i-k]=="UR") --sum;
        ans=max(ans,sum);
    }
    printf("%d",ans);
}