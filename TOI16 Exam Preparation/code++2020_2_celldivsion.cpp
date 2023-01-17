//                      18/10/2563
#include<bits/stdc++.h>
using namespace std;
int n,x;
string dp[1002]={"0","1"};
string add(string str1,string str2){
    string ans;
    int idx1,idx2,mxl,x=0,y=0,z=0;
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
    if(z) ans.insert(0,"1");
    return ans;
}
bool isSmaller(string str1, string str2){
    int n1=str1.length(),n2=str2.length();
    if (n1<n2) return 1;
    if (n2<n1) return 0;
    for (int i=0;i<n1;++i){
        if (str1[i]<str2[i]) return 1;
        else if (str1[i]>str2[i]) return 0;
    }
    return 0;
}
string subtract(string str1, string str2){
    if(isSmaller(str1,str2)) swap(str1,str2);
    string ans;
    int n1=str1.length(),n2=str2.length();
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int carry=0;
    for (int i=0;i<n2;++i){
        int sub=((str1[i]-'0')-(str2[i]-'0')-carry);
        if(sub<0){
            sub+=10;
            carry=1;
        }
        else carry=0;
        ans.push_back(sub+'0');
    }
    for (int i=n2;i<n1;++i) {
        int sub=((str1[i]-'0')-carry);
        if(sub<0){
            sub=sub+10;
            carry=1;
        }
        else carry=0;
        ans.push_back(sub+'0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    //cout<<findDiff("555","444");
    for(int i=2;i<=1000;++i){
        dp[i]=subtract(dp[i-1],dp[i-2]);
        dp[i]=add(dp[i],dp[i-1]);
        dp[i]=add(dp[i],dp[i-1]);
        //if(i<=500) cout<<dp[i]<<'\n';
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        cout<<dp[x]<<'\n';
    }
}
