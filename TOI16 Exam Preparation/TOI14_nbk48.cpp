//                      17/10/2563
#include<bits/stdc++.h>
using namespace std;
int n,q,idx,tem,ub;
vector<pair<int,int> > v;
pair<int,int> p;
int main(){
    scanf("%d %d",&n,&q);
    v.push_back({0,0});
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        v.push_back({v[v.size()-1].first+tem,i+1});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        if(idx>v[i].second) v[i].second=idx;
        idx=v[i].second;
        if(i>0&&v[i].first==v[i-1].first) v[i-1].second=idx;
    }
    //for(int i=0;i<v.size();++i) printf("(%d,%d) ",v[i].first,v[i].second);
    while(q--){
        scanf("%d",&tem);
        p={tem,0};
        ub=upper_bound(v.begin(),v.end(),p)-v.begin()-1;
        if(v[ub+1].first==tem) ++ub;
        printf("%d\n",v[ub].second);
    }
}