#include<bits/stdc++.h>
using namespace std;
long long n,m,k,mx,l,r,idx,prv,cnt;
long long L,R,M,qsum[100005],ans=LONG_LONG_MAX;
vector<long long> v;
vector<long long> qsum_v;
long long arr[100005];
int main(){
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=0;i<n;++i){
        scanf("%lld",&arr[i]);
        qsum[i+1]=qsum[i]+arr[i];
    }
    //  Doesn't handle multiple highest interval sum!
    for(int i=m,j=0;i<=n;++i,++j){
        if(mx<qsum[i]-qsum[j]){
            mx=qsum[i]-qsum[j];
            l=j;
            r=i;
        }
    }
    --r;
    //printf("%lld %lld\n",l,r);
    for(int i=0;i<n;++i){
        if(l<=i&&i<=r){
            continue;
        }
        v.push_back(arr[i]);
        if(!i) qsum_v.push_back(arr[i]);
        else qsum_v.push_back(qsum_v[qsum_v.size()-1]+arr[i]);
        L=max(L,arr[i]);
    }
    R=qsum_v[qsum_v.size()-1];
    // for(int i=0;i<v.size();++i) printf("%lld ",v[i]); printf("\n");
    // for(int i=0;i<qsum_v.size();++i) printf("%lld ",qsum_v[i]); printf("\n");
    while(L<=R){
        M=(L+R)/2;
        prv=0;
        cnt=0;
        //  Might turn into inf loop
        for(long long x=M;cnt<v.size();x+=M,++cnt){
            idx=upper_bound(qsum_v.begin(),qsum_v.end(),x)-qsum_v.begin()-1;
            if(x>=qsum_v[qsum_v.size()-1]) idx=qsum_v.size()-1;
            idx=min(idx,prv+m-1);
            //printf("cnt%lld x%lld prv%lld idx%lld\n",cnt,x,prv,idx);
            if(idx>=qsum_v.size()-1){
                ++cnt;
                break;
            }
            prv=idx+1;
            x=qsum_v[idx];
        }
        //printf("\n%lld %lld %lld : %d\n",L,M,R,cnt);
        if(cnt>k){
            L=M+1;
        }
        else{
            R=M-1;
            ans=min(ans,M);
        }
    }
    printf("%lld",ans);
}