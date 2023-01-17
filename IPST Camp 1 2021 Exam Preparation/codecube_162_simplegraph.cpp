//                  24/1/2564
#include<bits/stdc++.h>
using namespace std;
int tc,n,tem,x;
bool b;
int temp[100005];
int main(){
    scanf("%d",&tc);
    for(int t=0;t<tc;++t){
        scanf("%d",&n);
        priority_queue<int> pq;
        for(int i=0;i<n;++i){
            scanf("%d",&tem);
            pq.push(tem);
        }
        b=1;
        while(!pq.empty()){
            x=pq.top();
            pq.pop();
            if(x>pq.size()){
                b=0;
                break;
            }
            else{
                for(int i=0;i<x;++i){
                    temp[i]=pq.top();
                    pq.pop();
                }
                for(int i=0;i<x;++i){
                    if(temp[i]-1>0) pq.push(temp[i]-1);
                }
            }
        }
        if(b) printf("Yes\n");
        else printf("No\n");
    }
}