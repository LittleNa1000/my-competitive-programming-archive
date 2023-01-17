//                      13/1/2564 or 1 vec
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
bool broke[100005];
int n,m,ans,tem,x,mn,a,idx;
//priority_queue<ii> pq;
vector<int> vv;
bool com(const ii &a,const ii &b){
    return a.first<b.first;
}
vector<ii> v;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&tem);
        v.push_back({tem,i});
        vv.push_back(tem);
    }
    sort(vv.begin(),vv.end());
    sort(v.begin(),v.end(),com);
    broke[0]=1;
    broke[n+1]=1;
    mn=n;
    for(int i=0;i<m;++i){
        scanf("%d",&x);
        if(mn>x){
            ans=0;
            
            idx=upper_bound(vv.begin(),vv.end(),x)-vv.begin();
            for(int j=idx;j<mn;++j){
                a=v[j].second;
                if(!broke[a]){
                    ans++;
                    broke[a]=1;
                }
                if(!broke[a-1]){
                    ans++;
                    broke[a-1]=1;
                }
                if(!broke[a+1]){
                    ans++;
                    broke[a+1]=1;
                }
                //pq.pop();
            }
            mn=x;
            printf("%d\n",ans);
        }
        else printf("0\n");
    }
}
