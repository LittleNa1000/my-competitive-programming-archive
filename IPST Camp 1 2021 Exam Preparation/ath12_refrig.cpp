//                      6/1/2564
#include<bits/stdc++.h>
using namespace std;
int tc,n,tem,ans;
int main(){
    scanf("%d",&tc);
    while(tc--){
        priority_queue<int,vector<int>,greater<int>> pq;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&tem);
            pq.push(tem);
        }
        for(ans=1;;++ans){
            tem=pq.top();
            pq.pop();
            pq.push(tem+1);
            if(pq.top()-ans<=0) break;
        }
        printf("%d\n",ans);
    }
}