//                  12/11/2563
#include<bits/stdc++.h>
using namespace std;
struct t{
    long long int val;
    int idx;
};
deque<t> dq;
long long int ans,sum,x;
int y,arr[6000005],ansi,n,w;
int main(){
    scanf("%d %d",&n,&w);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
    dq.push_back({0,0});
    for(int i=1;i<=n;++i){
        sum+=arr[i];
        while(!dq.empty()&&i-dq.front().idx>w) dq.pop_front();
        while(!dq.empty()&&dq.back().val>=sum) dq.pop_back();
        dq.push_back({sum,i});
        x=sum-dq.front().val;
        y=i-dq.front().idx;
        if(ans<x||(ans==x&&ansi>y)){
            ans=x;
            ansi=y;
        }
    }
    if(x>0) printf("%lld\n%d",ans,ansi);
    else printf("0\n0");
}