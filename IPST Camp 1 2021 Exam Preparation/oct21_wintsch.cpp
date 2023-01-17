//                      13/1/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int s,t,w,dx;
};
vector<N> v;
vector<int> vs,ans;
bool com(const N &a,const N &b){
    return a.s<b.s;
}
int pre[1005];
int n,s,t,w,mx,mxw,cur_mxw,cur_mx=-1,idx;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d %d",&s,&t,&w);
        v.push_back({s,t,w,i});//or iiii
        //a[i]=w;
        pre[i]=-1;
    }
    sort(v.begin(),v.end(),com);
    for(int i=0;i<n;++i){
        vs.push_back(v[i].s);
    }
    for(int i=n-1;i>=0;--i){
        idx=lower_bound(vs.begin(),vs.end(),v[i].t)-vs.begin();
        mx=-1;
        mxw=0;
        if(idx<n){
            for(int j=idx;j<n;++j){
                if(mxw<v[j].w){
                    mxw=v[j].w;
                    mx=v[j].dx;
                }
            }
            v[i].w+=mxw;
            pre[i]=mx;
        }
        if(cur_mxw<v[i].w){
            cur_mxw=v[i].w;
            cur_mx=v[i].dx; //or i
        }
    }
    for(int i=cur_mx;i!=-1;i=pre[i]){
        ans.push_back(i+1);
    }
    printf("%d\n%d\n",cur_mxw,ans.size()); for(int i=0;i<ans.size();++i) printf("%d ",ans[i]);
}