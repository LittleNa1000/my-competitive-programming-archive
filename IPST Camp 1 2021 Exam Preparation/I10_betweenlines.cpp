//                      4/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,cur,x,y,z,pre;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&cur);
        if(pre==13&&cur==10) ++x;
        if(cur==13) ++z;
        if(cur==10) ++y;
        pre=cur;
    }
    printf("%d %d %d",x+1,y+1,z+1);
}