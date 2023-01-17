//          8/1/2564 or qsum f(b,2);
#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int f(int a,int b){
    if(b==1) return a;
    if(a==b) return 1; 
    if(mp[{a,b}]) return mp[{a,b}];
    int sum=0;
    for(int i=b-1;i<=a-1;++i){
        sum+=f(i,b-1)%1000003;
    }
    return mp[{a,b}]=sum%1000003;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",f(a,b)%1000003);
}