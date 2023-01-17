//                      9/1/2564
#include<bits/stdc++.h>
using namespace std;
int n;
int num[1012];
bool b,visited[1012];
int findvalid(int val){
    if(val==n+1) return -1;
    if(!visited[val]) return val;
    return findvalid(val+1);
}
void f(int depth){
    visited[num[depth]]=0;
    if(depth==1000){
        b=1;
        return;
    }
    int x=findvalid(num[depth]+1);
    if(x!=-1){
        num[depth]=x;
        visited[x]=1;
        f(depth+1);
        if(b) return ;
    }
    num[depth]=0;
    return f(depth-1);
}
void input(int i){
    if(i==1000) return;
    scanf("%d",&num[i]);
    visited[num[i]]=1;
    input(i+1);
}
void output(int i){
    if(i==1000) return;
    printf("%d\n",num[i]);
    output(i+1);
}
int main(){
    scanf("%d",&n);
    input(1000-n);
    f(999);
    output(1000-n);
}