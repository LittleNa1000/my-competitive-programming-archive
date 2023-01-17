//              6/5/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n,x,ctn[30],ntc[30],m;
ii cost[205][205],dp[205][205],ans;
char ch;
string str;
ii f(int l,int r){
    if(l>=r) return {0,ctn[str[l]-'a']};
    if(dp[l][r]!=make_pair(-1,-1)) return dp[l][r];
    if(l+1==r){
        //printf("(%d,%d) %d,%c\n",l,r,cost[ctn[str[l]-'a']][ctn[str[r]-'a']].first,ntc[cost[ctn[str[l]-'a']][ctn[str[r]-'a']].second]+'a');
        return dp[l][r]= cost[ctn[str[l]-'a']][ctn[str[r]-'a']];
    }
    ii mn={INT_MAX,INT_MAX},a,b;
    for(int i=l;i<r;++i){
        a=f(l,i);
        b=f(i+1,r);
        if(mn.first>a.first+b.first+cost[a.second][b.second].first
        ||(mn.first==a.first+b.first+cost[a.second][b.second].first&&mn.second>cost[a.second][b.second].second)){
            mn.first=a.first+b.first+cost[a.second][b.second].first;
            mn.second=cost[a.second][b.second].second;
        }
    }
     //printf("(%d,%d) %d,%c\n",l,r,mn.first,ntc[mn.second]+'a');
    return dp[l][r]=mn;
}
void reset(bool all){
    for(int i=0;i<205;++i) for(int j=0;j<205;++j){
        dp[i][j]={-1,-1};
    }
    if(all){
        for(int i=0;i<30;++i){
            ctn[i]=0;
            ntc[i]=0;
        }
        for(int i=0;i<205;++i) for(int j=0;j<205;++j){
            cost[i][j]={0,0};
        }
    }
}
int main(){
    while(1){
        scanf("%d",&n);
        if(!n) return 0;
        for(int i=0;i<n;++i){
            cin>>ch;
            ctn[ch-'a']=i;
            ntc[i]=ch-'a';
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d-%c",&x,&ch);
                //printf("(%d,%d)\n",x,ch);
                cost[i][j]={x,ctn[ch-'a']};
            }
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            reset(0);
            cin>>str;
            ans=f(0,str.length()-1);
            printf("%d-%c\n",ans.first,ntc[ans.second]+'a');
        }
        reset(1);
        printf("\n");
    }
}