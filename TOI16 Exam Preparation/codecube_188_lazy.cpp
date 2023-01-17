//                  21/11/2563
#include<bits/stdc++.h>
using namespace std;
int n,q,tem,l,r,x,lb,ub;
vector<int> v;
map<int,vector<int> > mp;
int main(){
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        mp[tem].push_back(i+1);
    }
    while(q--){
        scanf("%d %d %d",&l,&r,&x);
        v=mp[x];
        if(v.empty()||v[v.size()-1]<l) printf("0\n");
        else{
            lb=lower_bound(v.begin(),v.end(),l)-v.begin();
            ub=upper_bound(v.begin(),v.end(),r)-v.begin()-1;
            printf("%d\n",ub-lb+1);
        }
    }
}