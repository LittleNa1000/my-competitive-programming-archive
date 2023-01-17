//                  9/1/2564// or find relation n! / k!*(n-k)!
#include<bits/stdc++.h> 
using namespace std;
int num[12],n,k,l,r=1;
bool b;
void f(int depth,int last){
    if(depth==11){
        if(r==l){
            for(int i=11-k;i<=10;++i) printf("%d ",num[i]);
            b=1;
        }
        else ++r;
        return ;
    }
    for(int i=last+1;i<=n;++i){
        num[depth]=i;
        f(depth+1,i);
        if(b) return ;
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&l);
    f(11-k,0);
}