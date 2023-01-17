//                      7/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
priority_queue<ii,vector<ii>,greater<ii>> pq;
int n,m,w,v;
char ch;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+m;++i){
        cin>>ch;
        if(ch=='T'){
            cin>>w>>v;
            pq.push({w,v});
        }
        else{
            if(pq.empty()) printf("0\n");
            else{
                printf("%d\n",pq.top().second);
                pq.pop();
            }
        }
    }
}