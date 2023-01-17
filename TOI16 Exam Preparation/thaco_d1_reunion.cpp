//                     7/11/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> wall[105]; // or no vec but check 1 by 1
int n,m,ans,broke[30005];
long long int x[105],y[105],h[30005],k[30005],r[30005];
bool same;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%lld %lld",&x[i],&y[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%lld %lld %lld",&h[i],&k[i],&r[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if((x[i]-h[j])*(x[i]-h[j])+(y[i]-k[j])*(y[i]-k[j])<r[j]*r[j]){
                wall[i].push_back(j);
                if(!broke[j]){
                    ++ans;
                }
                ++broke[j];
                if(broke[j]==n){
                    --ans;
                }
            }
        }
    }
    same=1;
    for(int i=1;i<n;++i){
        if(wall[i]!=wall[i-1]){
            same=0;
            break;
        }
    }
    if(same) printf("0");
    else printf("%d",ans);
}