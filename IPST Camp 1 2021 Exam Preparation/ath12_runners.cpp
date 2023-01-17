//                      6/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<float,float>> iff;
bool com(const iff &a,const iff &b){
    if(a.second.first==b.second.first){
        return a.second.second>b.second.second;
    }
    return a.second.first<b.second.first;
}
int tc,n,k,x,y;
int main(){
    scanf("%d",&tc);
    while(tc--){
        vector<iff> v;//or double
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            v.push_back({i,{((float)k*1000/(float)x)+(float)y,(float)y}});
        }
        sort(v.begin(),v.end(),com);
        //for(int i=0;i<n;++i) printf("%d %f %f\n",v[i].first,v[i].second.first,v[i].second.second);
        for(int i=0;i<n;++i) printf("%d\n",v[i].first+1);
    }
}