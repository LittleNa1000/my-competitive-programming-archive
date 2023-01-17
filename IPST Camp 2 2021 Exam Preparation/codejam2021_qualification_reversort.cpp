//                      27/3/2564
#include<bits/stdc++.h>
using namespace std;
int T,n,num,arr[105],l,r,j,mn,idx,ans;
int main(){
    scanf("%d",&T);
    for(int t=0;t<T;++t){
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&num);
            arr[i]=num;
        }
        for(int i=0;i<n-1;++i){
            mn=INT_MAX,idx=i;
            for(int j=i;j<n;++j){
                if(arr[j]<mn){
                    idx=j;
                    mn=arr[j];
                }
            }
            //printf("= %d\n",idx);
            l=i,r=idx;
            while(l<r){
                swap(arr[l],arr[r]);
                l++;
                --r;
            }
            ans+=(idx-i+1);
        }
        printf("Case #%d: %d\n",t+1,ans);
    }
    
}