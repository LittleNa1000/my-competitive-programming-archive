//                     12/10/2563
#include<bits/stdc++.h>
using namespace std;
int n,l,tem,ans;
int broke[1000002],fix[1000002];
vector<int> v;
int main(){
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        broke[tem]=1;
        v.push_back(tem);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        if(broke[v[i]]&&!fix[v[i]]){
            for(int j=0;j<l&&v[i]+j<=10e6;++j){
                fix[v[i]+j]=1;
            }
            ++ans;
        }
    }
    printf("%d",ans);
}