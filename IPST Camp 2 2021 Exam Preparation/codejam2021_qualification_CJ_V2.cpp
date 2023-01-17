#include<bits/stdc++.h>
using namespace std;
int T,ans,x,y;
char p;
string str;
int calc(char a,char b){
    if(a=='C'&&b=='J') return x;
    if(a=='J'&&b=='C') return y;
    return 0;
}
int main(){
    scanf("%d",&T);
    for(int t=0;t<T;++t){
        cin>>x>>y>>str;
        ans=0;
        for(int i=0;i<str.length();++i){
            if(str[i]=='?') {
                str.erase(str.begin()+i);
                --i;
            }
        }
        for(int i=1;i<str.length();++i){
            ans+=calc(str[i-1],str[i]);
        }
        printf("Case #%d: %d\n",t+1,ans);
    }
}