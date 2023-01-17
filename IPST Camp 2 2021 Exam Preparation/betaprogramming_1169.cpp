#include<bits/stdc++.h>
using namespace std;
int x,ans;
string str;
int main(){
    cin>>str;
    for(int i=0;i<str.length();++i){
        if(str[i]=='(') ++x;
        else --x;
        if(x<0){
            ans+=-x;
            x=0;
        }
    }
    printf("%d",ans+x);
}