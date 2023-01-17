//                  5/11/2563
#include<bits/stdc++.h>
using namespace std;
int inv[100005],arr[100005],pos[100005];
int n,q,a,b;
void count_inversion(int l,int m,int r){
    //printf("Merge %d %d %d\n",l,m,r);
    vector<int> t;
    int i=l,j=m+1;
    while((i<=m)&&(j<=r)){
        if(arr[i]>arr[j]){
            inv[arr[j]]+=(m-i+1);
            t.push_back(arr[j++]);
        }
        else{
            t.push_back(arr[i++]);
        }
    }
    while(i<=m) t.push_back(arr[i++]);
    while(j<=r) t.push_back(arr[j++]);
    for(int x=0;x<t.size();++x){
        arr[x+l]=t[x];
    }
}
void d(int l,int r){
    //printf("Div %d %d\n",l,r);
    if(l>=r) return ;
    int m=(l+r)/2;
    d(l,m);
    d(m+1,r);
    count_inversion(l,m,r);
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
        pos[arr[i]]=i;
    }
    d(1,n);
    //for(int i=1;i<=n;++i) printf("%d ",inv[i]); printf("\n");
    //for(int i=1;i<=n;++i) printf("%d ",arr[i]); printf("\n");
    while(q--){
        scanf("%d %d",&a,&b);
        if(a+b>=n+1) printf("%d\n",b);
        else printf("%d\n",pos[b]-min(inv[b],a));
    }
}