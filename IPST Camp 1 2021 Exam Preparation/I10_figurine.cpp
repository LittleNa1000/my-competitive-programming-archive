//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,tem,ans;
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        v.push_back(tem);
        ans+=tem;
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n/5;i++){
        //printf("+%d\n",v[n-((2*i))]);
        ans-=v[n-((2*i))];
    }
    printf("%d",ans);
}