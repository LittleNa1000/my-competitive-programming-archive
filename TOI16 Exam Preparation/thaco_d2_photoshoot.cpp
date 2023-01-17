//                     8/11/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> chk;
int n,k,l,r,mn,mx,ans,val;
vector<int> v,a;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        v.push_back(i+1);
        a.push_back(i+1);
    }
    for(int i=0;i<k;++i){
        scanf("%d %d",&l,&r);
        chk.push_back({l,r});
    }
    do{
        val=0;
        //for(int i=0;i<n;++i) printf("%d ",v[i]);
        for(int i=0;i<k;++i){
            mn=INT_MAX; mx=INT_MIN;
            for(int j=chk[i].first;j<=chk[i].second;++j){
                mn=min(mn,v[j-1]);
                mx=max(mx,v[j-1]);
                //printf("(%d,%d) ",mn,mx);
            }
            val+=abs(mn-mx);
        }
        //printf("val=%d \n",val);
        if(val>ans){
            ans=val;
            for(int i=0;i<n;++i) a[i]=v[i];
        }
    }while(next_permutation(v.begin(),v.end()));
    for(int i=0;i<n;++i) printf("%d ",a[i]);
}