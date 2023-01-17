//                      10/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> v[12];
bool b,visited[12][100012];
int ans,tc,n,k,w,c,l,r,m,cur_w,box;
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i){
            scanf("%d%d",&w,&c);
            v[tc].push_back({w,c});
        }
        b=0;
        l=1,r=1e8;
        ans=1e9;
        while(l<=r){
            queue<int> q;
            m=(l+r)/2;
            cur_w=0;
            box=1;
            for(int i=0;i<n;++i){
                w=v[tc][i].first; c=v[tc][i].second;
                if(cur_w+w<=m&&!visited[tc][c]){
                    cur_w+=w;
                    visited[tc][c]=1;
                    q.push(c);
                }
                else{
                    ++box;
                    --i;
                    cur_w=0;
                    while(!q.empty()){
                        visited[tc][q.front()]=0;
                        q.pop();
                    }
                }
            }
            while(!q.empty()){
                visited[tc][q.front()]=0;
                q.pop();
            }
            if(box<=k){
                r=m-1;
                ans=min(ans,m);
                b=1;
            }
            else{
                l=m+1;
            }
        }
        if(b) printf("%d\n",ans);
        else printf("-1\n");
    }
}