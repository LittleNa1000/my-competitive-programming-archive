//                  26/11/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,x,y;
vector<pii> v;
priority_queue<pii> pq;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
        pq.push({y,x});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        while(pq.top().second<=v[i].first&&!pq.empty()) pq.pop();
        if(pq.empty()||v[i].second>=pq.top().first) printf("%d %d\n",v[i].first,v[i].second);
    }
}