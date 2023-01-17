//                      12/10/2563
#include<bits/stdc++.h>
using namespace std;
string str,str2;
int n,idx,l,r;
char tem;
int main(){
    cin>>str>>n;
    for(int i=0;i<n;++i){
        cin>>tem;
        if(tem=='I'){
            cin>>idx>>str2;
            str.insert(idx,str2);
        }
        else{
            cin>>l>>r;
            reverse(str.begin()+l-1,str.begin()+r);
        }
        
    }
    cout<<str;
}