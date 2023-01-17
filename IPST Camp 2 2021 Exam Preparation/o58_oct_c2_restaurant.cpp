#include<bits/stdc++.h>
using namespace std;
int n,T,l,r,d,cnt;
int hop[90005],table[305][305];
vector<pair<int,pair<int,int>>> v;
bool have_pair(int idx){
    while(l!=r&&r>=0&&l<=v.size()-1){
        int sum=v[l].first+v[r].first;
        if(sum==v[idx].first) return 1;
        else if(sum<v[idx].first) ++l;
        else --r;
    }
    return 0;
}
int main(){
    scanf("%d %d",&n,&T);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&d);
            if(i>j){
                v.push_back({d,{i,j}});
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        l=0,r=i-1;
        if(have_pair(i)){
            hop[i]=hop[l]+hop[r];
        }
        else hop[i]=1;
        table[v[i].second.first][v[i].second.second]=hop[i];
        table[v[i].second.second][v[i].second.first]=hop[i];
    }
    for(int i=0;i<n;++i){
        cnt=0;
        for(int j=0;j<n;++j){
            if(table[i][j]==1) ++cnt;
        }
        if(cnt>2){
            printf("%d",i+1);
            if(T==2) printf("\n%d",cnt);
        }
    }
}