//                      12/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,head[300012],x,y,t;
stack<int> st[300005];
//vector<int> v;
void f(int h){
    printf("%d ",h);
    while(!st[h].empty()){
        t=st[h].top();
        st[h].pop();
        f(t);
    }
    return ;
}
int find_head(int x){
    if(!head[x]) return x;
    return find_head(head[x]);
}
int main(){
    int h;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&x,&y);
        head[x]=y;
        st[y].push(x);
    }
    h=find_head(head[1]);//or find unvisited[]
    //printf("h%d\n",h);
    f(h);
    //for(int i=0;i<n;++i) printf("%d ",v[i]);
}