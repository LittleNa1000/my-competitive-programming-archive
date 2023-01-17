//                      20/9/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,skip,tem;
vector<pii> v;
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
    scanf("%d %d",&n,&m);
    int ans[m+1];
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        pq.push(tem);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&tem);
        v.push_back({tem,i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;++i){
        v[i].first+=skip;
        while(!pq.empty()&&v[i].first>=pq.top()){
            pq.pop();
            ++skip;
            ++v[i].first;
        }
        ans[v[i].second]=v[i].first;
    }
    for(int i=0;i<m;++i) printf("%d ",ans[i]);
}