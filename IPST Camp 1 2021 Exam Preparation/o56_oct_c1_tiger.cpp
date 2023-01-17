//      17/2/2564
#include<bits/stdc++.h>
using namespace std;
int n,m,f_x[1005],f_y[1005],x,y,mn,pre,mxcnt,cnt;
vector<int> v;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d %d",&f_x[i],&f_y[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d %d",&x,&y);
        mn=INT_MAX;
        for(int j=0;j<n;++j){
            mn=min(mn,abs(x-f_x[j])+abs(y-f_y[j]));
        }
        v.push_back(mn);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        if(v[i]==pre){
            if(!cnt) cnt=1;
            ++cnt;
            mxcnt=max(mxcnt,cnt);
        }
        else{
            cnt=0;
        }
        pre=v[i];
    }
    printf("%d",mxcnt);
}