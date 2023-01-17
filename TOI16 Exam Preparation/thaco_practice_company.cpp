//                  10/10/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> v[300002];
vector<pii> money;
set<int> s;
set<int>::iterator it;
int n,parent;
int arr[300002];
void dfs(int node){
    int l=0;
    int r=INT_MAX/2;
    if(!s.empty()){
        if(arr[node]!=0){
            it=s.begin();
            advance(it,arr[node]-1);
            l=*it;
        } 
        if(arr[node]!=s.size()){
            it=s.begin();
            advance(it,arr[node]);
            r=*it;
        }
    }
    money.push_back({(l+r)/2,node});
    if(v[node].empty()) return ;
    s.insert((l+r)/2);
    for(int i=0;i<v[node].size();++i){
        dfs(v[node][i]);
    }
    s.erase((l+r)/2);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
    for(int i=2;i<=n;++i){
        scanf("%d",&parent);
        v[parent].push_back(i);
    }
    dfs(1);
    sort(money.begin(),money.end());
    for(int i=n-1;i>=0;--i){
        printf("%d ",money[i].second);
    }
}