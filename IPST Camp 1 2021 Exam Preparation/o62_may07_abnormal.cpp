//                      16/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,g,k,l,r;
string str;
int main(){
    scanf("%d%d%d%d%d",&n,&g,&k,&l,&r);
    for(int j=0;j<k;++j){
        cin>>str;
        if(r==1) cout<<str<<str<<'\n';
        else{
            for(int i=0;i<n;++i){
                if(str[i]<str[i+n]){
                    cout<<str[i];
                }
                else{
                    cout<<str[i+n];
                }
            }
            cout<<'\n';
        }
    }
}