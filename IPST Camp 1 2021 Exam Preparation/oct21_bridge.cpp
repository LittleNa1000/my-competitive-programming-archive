//                      15/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,tem,a[3005],idx[3005],x,id;
vector<int> v;
int main(){
    scanf("%llu",&n);
    for(int i=1;i<=n;++i){
        scanf("%llu",&tem);
        idx[tem]=i;
    }
    for(int i=1;i<=n;++i){
        scanf("%llu",&tem);
        a[i]=idx[tem];
        //printf("%llu ",a[i]);
    }
    for(int i=1;i<=n;++i){
        x=a[i];
        if(i==0){
            v.push_back(x);
            continue;
        }
        id=lower_bound(v.begin(),v.end(),x)-v.begin();
        if(id==v.size()) v.push_back(x);
        else v[id]=x;
    }
    printf("%llu\n",v.size());
}