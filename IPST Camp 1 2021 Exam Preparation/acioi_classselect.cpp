//                      21/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
bool com(const ii &a,const ii &b){
    return a.second<b.second;
}
int n,S,F,ans,cur;
vector<ii> v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&S);
        v.push_back({S,0});
    }
    for(int i=0;i<n;++i){
        scanf("%d",&F);
        v[i].second=F;
    }
    sort(v.begin(),v.end(),com);
    for(int i=0;i<n;++i){
        if(cur<=v[i].first){
            ++ans;
            cur=v[i].second;
        }
    }
    printf("%d",ans);
}