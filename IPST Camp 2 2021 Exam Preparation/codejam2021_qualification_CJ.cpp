//                      27/3/2564 Brute Force if TLE then Go Greedy
#include<bits/stdc++.h>
using namespace std;
// min priority_queue
// {totalcost,idx,previous}
// if(???????) -> Greedy
// vst or dist
int T,x,y,current;
string str;
struct N{
    int d,i;
    char p;
};
bool operator<(const N &a,const N &b){
    return a.d>b.d;
}
int calc(char a,char b){
    if(a==b) return 0;
    if(a=='C'&&b=='J') return x;
    return y;
}
int f(int idx){
    priority_queue<N> pq;
    if(str[idx]=='?'){
        pq.push({0,1,'C'});
        pq.push({0,1,'J'});
    }
    else pq.push({0,1,str[idx]});
    while(!pq.empty()){
        int d=pq.top().d;
        int ix=pq.top().i;
        char p=pq.top().p;
        pq.pop();
        //printf("%d %d %c\n",d,ix,p);
        if(ix==str.length()){
            return d;
        }
        if(str[ix]!='?'){
            pq.push({d+calc(p,str[ix]),ix+1,str[ix]});
            continue;
        }
        pq.push({d+calc(p,'C'),ix+1,'C'});
        pq.push({d+calc(p,'J'),ix+1,'J'});
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d",&T);
    for(int t=0;t<T;++t){
        cin>>x>>y>>str; // CJ, JC
        current=0;
        current=f(0);
        // for(int i=0;i<str.length();++i){
        //     if(str[i]=='?'){
        //         current+=f(i);
        //         ++i;
        //     //     while((i<str.length()&&str[i]=='?')){++i;}
        //      }
        //     // else if(i>0&&str[i-1]=='J'&&str[i]=='C') current+=y;
        //     // else if(i>0&&str[i-1]=='C'&&str[i]=='J') current+=x;
        //     // printf("i%d cur%d\n",i,current);
        // }
        printf("Case #%d: %d\n",t+1,current);
    }
}