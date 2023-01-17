//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,tem,cur,pre=2e9;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&tem,&cur);
        printf("%d\n",max(0,cur-pre));
        pre=min(cur,pre);
    }
}