//                      16/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> v;
vector<int> rp[25005];
int n,tem,cnt,q,l,r,lb,ub,ans;
bool same;
bool com(const ii &a,const ii &b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        v.push_back({tem,i});
    }
    sort(v.begin(),v.end(),com);
    for(int i=1;i<n;++i){
        if(v[i].first==v[i-1].first){
            if(!same){
                rp[cnt].push_back(v[i-1].second);
                //printf("%d %d\n",cnt,v[i-1].second);
                rp[cnt].push_back(v[i].second);
                //printf("%d %d\n",cnt,v[i].second);
                same=1;
            }
            else{
                rp[cnt].push_back(v[i].second);
                //printf("%d %d\n",cnt,v[i].second);
            }
        }
        else{
            if(same){
                same=0;
                ++cnt;
            }
        }
    }
    if(same) ++cnt;
    //printf("=%d",cnt);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        ans=0;
        for(int i=0;i<cnt;++i){
            if(r>=rp[i][rp[i].size()-1]) ub=rp[i].size()-1;
            else ub=upper_bound(rp[i].begin(),rp[i].end(),r)-rp[i].begin()-1;
            if(l<=rp[i][0]) lb=0;
            else lb=lower_bound(rp[i].begin(),rp[i].end(),l)-rp[i].begin();
            ans+=max(0,(ub-lb));
        }
        printf("%d\n",ans);
    }
}