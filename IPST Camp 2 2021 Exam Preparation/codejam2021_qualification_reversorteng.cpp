//                  27/3/2564
#include<bits/stdc++.h>
using namespace std;
int T,ans,l,r,mn,idx,n,c,arr[105],arr2[105];
bool b;
int f(){
    int an=0;
    for(int i=0;i<n-1;++i){
        mn=INT_MAX,idx=i;
        for(int j=i;j<n;++j){
            if(arr2[j]<mn){
                idx=j;
                mn=arr2[j];
            }
        }
        //printf("= %d\n",idx);
        l=i,r=idx;
        while(l<r){
            swap(arr2[l],arr2[r]);
            l++;
            --r;
        }
        an+=(idx-i+1);
    }
    return an;
}
int main(){
    scanf("%d",&T);
    for(int t=0;t<T;++t){
        scanf("%d %d",&n,&c);
        b=0;
        for(int i=0;i<n;++i) arr[i]=i+1;
        do{
           // for(int i=0;i<n;++i) printf("%d ",arr[i]); printf("\n");
            for(int i=0;i<n;++i) arr2[i]=arr[i];
            ans=f();
            if(ans==c){
                printf("Case #%d: ",t+1);
                for(int i=0;i<n;++i) printf("%d ",arr[i]); printf("\n");
                b=1;
                break ;
            }
        }while(next_permutation(arr,arr+n));
        if(!b) printf("Case #%d: IMPOSSIBLE\n",t+1);
    }
}