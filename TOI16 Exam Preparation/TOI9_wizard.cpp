//                      4/11/2563
#include<bits/stdc++.h>
using namespace std;
struct T{
    int st,nd,x,y;
};
vector<struct T> v;
int n,tx,ty,tem1,tem2,idx;
int x[1001],y[1001];
map<pair<int,int> ,int> mp;
pair<int,int> arr[1000005];
int main(){
    scanf("%d %d %d",&tx,&ty,&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&tem1,&tem2);
        for(int j=0;j<n;++j){
            v.push_back({tem1+x[j],tem2+y[j],x[j],y[j]});
        }
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&tem1,&tem2);
        for(int j=0;j<n;++j){
            mp[{tem1+x[j],tem2+y[j]}]=(i*n)+j+1;
            arr[(i*n)+j+1]={x[j],y[j]};
        }
    }
    for(int i=0;i<v.size();++i){
        idx=mp[{tx-v[i].st,ty-v[i].nd}];
        if(idx!=0){
            printf("%d %d\n%d %d\n",v[i].x,v[i].y,v[i].st-v[i].x,v[i].nd-v[i].y);
            printf("%d %d\n%d %d",arr[idx].first,arr[idx].second,tx-v[i].st-arr[idx].first,ty-v[i].nd-arr[idx].second);
        }
    }
}