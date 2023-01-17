#include<bits/stdc++.h>
using namespace std;
int n;
string str[100012];
bool com(const string &a,const string &b){
    if(a.length()!=b.length()) return a.length()<b.length();
    for(int idx=0;idx<a.length();++idx){
        if(a[idx]!=b[idx]) return a[idx]<b[idx];
    }
    return 0;
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