//      14/2/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int c,i,a,b;
};
int dp[11][1002][26][26];
int t;
bool bb;
string str;
int d(int x,int y){
    return min(abs(x-y),abs(x+26-y));
}
bool operator<(const N &a,const N &b){
    return a.c>b.c;
}
priority_queue<N> pq[11];
void f(int cost,int idx,int a,int b){
    pq[t].pop();
    int ch=str[idx]-'A';
    int da=d(a,ch),db=d(b,ch);
    //printf("%d %d %d %c %c\n",t,cost,idx,a+'A',b+'A');
    if(idx==str.length()){
        printf("%d\n",cost);
        bb=1;
        return ;
    }
    if(dp[t][idx+1][min(ch,b)][max(ch,b)]>cost+da){
        dp[t][idx+1][min(ch,b)][max(ch,b)]=cost+da;
        pq[t].push({cost+da,idx+1,ch,b});
    }
    if(dp[t][idx+1][min(ch,a)][max(ch,a)]>cost+db){
        dp[t][idx+1][min(ch,a)][max(ch,a)]=cost+db;
        pq[t].push({cost+db,idx+1,ch,a});
    }
}
int main(){
    scanf("%d",&t);
    
    for(int i=0;i<11;++i){
        for(int j=0;j<1002;++j){
            for(int k=0;k<26;++k){
                for(int l=0;l<26;++l){
                    dp[i][j][k][l]=INT_MAX;//could be faster
                }
            }
        }
    }
    while(t--){
        cin>>str;
        bb=0;
        dp[t][0][0][0]=0;
        pq[t].push({0,0,0,0});
        while(!pq[t].empty()){
            f(pq[t].top().c,pq[t].top().i,pq[t].top().a,pq[t].top().b);
            //printf("b%d\n",b);
            if(bb) break ;
        }
    }
}
