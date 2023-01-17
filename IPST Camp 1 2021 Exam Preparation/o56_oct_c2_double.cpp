//                      10/1/2564
#include<bits/stdc++.h>
using namespace std;
int num,tg,n,j,a[100012],sum;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    tg=sum/2;
    for(int i=0;i<n;++i){
        num+=a[i];
        while(num>tg){
            num-=a[j];
            ++j;
        }
        if(num==tg){
            if(j>0) printf("%d %d",j,i+1);
            else printf("%d",i+1);
            return 0;
        }
    }
    printf("NO");
}