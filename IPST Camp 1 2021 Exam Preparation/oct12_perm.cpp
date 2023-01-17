//                  9/1/2564// or find relation n! / (n-k)!
#include<bits/stdc++.h> 
using namespace std;
int num[12],n,k,l,r=1;
bool visited[12];
bool b;
void f(int depth){
    if(depth==11){
        if(r==l){
            for(int i=11-k;i<=10;++i) printf("%d ",num[i]);
            b=1;
        }
        else ++r;
        //for(int i=11-k;i<=10;++i) printf("%d ",num[i]); printf("\n");
        return ;
    }
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            num[depth]=i;
            visited[i]=1;
            f(depth+1);
            visited[i]=0;
            if(b) return ;
        }
        
        
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&l);
    f(11-k);
}