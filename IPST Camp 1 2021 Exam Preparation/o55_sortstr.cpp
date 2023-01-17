#include<bits/stdc++.h>
using namespace std;
int n;
string str[100012];
bool com(const string &a,const string &b){
    int idx=0;
    while(a[idx]==b[idx]) {
        ++idx;
        if(a.length()==b.length()&&idx==a.length()) return 0;
    }
    return a[idx]<b[idx];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
       cin>>str[i];
    }
    sort(str,str+n,com);
    for(int i=0;i<n;++i){
       cout<<str[i]<<'\n';
    }
}