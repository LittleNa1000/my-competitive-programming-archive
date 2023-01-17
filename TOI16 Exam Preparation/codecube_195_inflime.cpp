//                  20/9/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> chk;
vector<int> skip;
int n,m,idx=1,skipidx,chkidx,tem;
long long int i=1;
int main(){
    scanf("%d %d",&n,&m);
    int ans[m+1];
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        skip.push_back(tem);
    }
    sort(skip.begin(),skip.end());
    for(int i=0;i<m;++i){
        scanf("%d",&tem);
        chk.push_back({tem,i});
    }
    sort(chk.begin(),chk.end());
    for(;;++i){
        if(skip[skipidx]==i){
            ++skipidx;
            continue;
        }
        while(idx==chk[chkidx].first&&chkidx!=chk.size()){
            ans[chk[chkidx].second]=i;
            ++chkidx;
        }
        if(chkidx==chk.size()) break;
        ++idx;
    }
    for(int i=0;i<m;++i){
        printf("%d ",ans[i]);
    }
}