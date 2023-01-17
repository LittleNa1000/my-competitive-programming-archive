//                      15/10/2563 maybe string ans / vector<int> ans
#include<bits/stdc++.h>
using namespace std;
string str1,str2,ans;
int x,y,z,idx1,idx2,mxl;
int main(){
    cin>>str1>>str2;
    idx1=str1.length()-1;
    idx2=str2.length()-1;
    mxl=max(idx1,idx2)+1;
    ans.resize(mxl);
    for(int i=mxl-1;i>=0;--i,--idx1,--idx2){
        x=0; y=0;
        if(idx1>=0) x=str1[idx1]-'0';
        if(idx2>=0) y=str2[idx2]-'0';
        z+=x+y;
        if(z>=10){
            z%=10;
            ans[i]=z+'0';
            z=1;
        }
        else{
            ans[i]=z+'0';
            z=0;
        }
    }
    if(z) printf("1");
    cout<<ans;
}