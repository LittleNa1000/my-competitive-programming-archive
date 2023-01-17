//      14/2/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int c,i,a,b;
};
int dp[1010][30][30];
int t;
bool bb;
string str;
int d(int x,int y){
    return min(abs(x-y),abs(x+26-y));
}
bool operator<(const N &a,const N &b){
    return a.c>b.c;
}
priority_queue<N> pq;
void f(int cost,int idx,int a,int b){
    pq.pop();
    int ch=str[idx]-'A';
    int da=d(a,ch),db=d(b,ch);
    //printf("%d %d %d %c %c\n",t,cost,idx,a+'A',b+'A');
    if(idx==str.length()){
        printf("%d\n",cost);
        bb=1;
        return ;
    }
    if(dp[idx+1][min(ch,b)][max(ch,b)]>cost+da){
        dp[idx+1][min(ch,b)][max(ch,b)]=cost+da;
        pq.push({cost+da,idx+1,min(ch,b),max(ch,b)});
    }
    if(dp[idx+1][min(ch,a)][max(ch,a)]>cost+db){
        dp[idx+1][min(ch,a)][max(ch,a)]=cost+db;
        pq.push({cost+db,idx+1,min(ch,a),max(ch,a)});
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>str;
        bb=0;
        for(int j=0;j<1010;++j){
            for(int k=0;k<30;++k){
                for(int l=0;l<30;++l){
                    dp[j][k][l]=INT_MAX;//could be faster
                }
            }
        }
        dp[0][0][0]=0;
        pq.push({0,0,0,0});
        while(!pq.empty()){
            f(pq.top().c,pq.top().i,min(pq.top().a,pq.top().b),max(pq.top().a,pq.top().b));
            //printf("b%d\n",b);
            if(bb) break ;
        }
        while(!pq.empty()) pq.pop();
    }
}
