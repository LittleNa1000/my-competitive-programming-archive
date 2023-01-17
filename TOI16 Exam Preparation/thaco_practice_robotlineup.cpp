//                  15/10/2563
#include<bits/stdc++.h>
using namespace std;
long long int ans;
vector<int> l;
void count_inversion(int left,int mid,int right){
    vector<int> temp;
    int i=left,j=mid+1;
    while((i<=mid)&&(j<=right)){
        if(l[i]<l[j]){
            temp.push_back(l[j++]);
            ans+=(mid+1-i);
        }
        else{
            temp.push_back(l[i++]);
        }
    }
    while(i<=mid) temp.push_back(l[i++]);
    while(j<=right) temp.push_back(l[j++]);
    for(i=0;i<temp.size();i++) l[i+left]=temp[i];
}
void divide(int left,int right){
    int mid=(left+right)/2;
    if(left>=right) return ;
    divide(left,mid);
    divide(mid+1,right);
    count_inversion(left,mid,right);
}
int main(){
    vector<int> v,r;
    int n,m,tem,mid;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        v.push_back(tem);
    }
    mid=v[n/2];
    for(int i=0;i<m;++i){
        scanf("%d",&tem);
        if(tem<mid){
            l.push_back(tem);
        }
        else{
            r.push_back(tem);
        }
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    for(int i=0;i<n;++i){
        l.push_back(v[i]);
    }
    for(int i=0;i<r.size();++i){
        l.push_back(r[i]);
    }
    //for(int i=0;i<l.size();++i) printf("%d ",l[i]);
    divide(0,n+m-1);
    printf("%lld",ans);
}