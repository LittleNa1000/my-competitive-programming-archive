//          16/2/2564
#include<bits/stdc++.h>
using namespace std;
int x,y,n,idx;
int main(){
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        vector<pair<int,int>> v;
        vector<int> lis;
        for(int i=0;i<n;++i){
            scanf("%d %d",&x,&y);
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;++i){
            x=v[i].second;
            if(!i) lis.push_back(x);
            else{
                idx=upper_bound(lis.begin(),lis.end(),x)-lis.begin();
                if(idx==lis.size()) lis.push_back(x);
                else lis[idx]=x;
            }
        }
        printf("%d\n",lis.size());
    }
}