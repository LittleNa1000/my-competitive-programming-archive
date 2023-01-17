//                      14/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,x,idx;
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(i==0){
            v.push_back(x);
            continue;
        }
        idx=lower_bound(v.begin(),v.end(),x)-v.begin();
        if(idx==v.size()) v.push_back(x);
        else v[idx]=x;
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i) printf("%d ",v[i]);
}