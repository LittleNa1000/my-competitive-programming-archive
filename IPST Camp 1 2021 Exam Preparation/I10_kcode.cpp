//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
string str,cc="UUDDLRLRBA";
bool b;
int main(){
    cin>>str;
    for(int i=9;i>=0;--i){
        b=1;
        for(int j=0;j<=i;++j){
            //cout<<i<<' '<<j<<' '<<cc[j]<<'='<<str[str.length()-i-1+j]<<'\n';
            if(cc[j]!=str[str.length()-i-1+j]){
                b=0;
                break;
            }
        }
        if(b){
            for(int j=i+1;j<=9;++j){
                cout<<cc[j];
            }
            cout<<'S';
            return 0;
        }
    }
    cout<<cc<<'S';
}