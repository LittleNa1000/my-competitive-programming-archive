//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
string str;
int n,len,a,b,c,d;
int main(){
    scanf("%d",&n);
    for(int tc=0;tc<n;++tc){
        cin>>str;
        len=str.length();
        for(int i=0;i<len;++i){
            if((str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')){
                a=i;
                break;
            }
        }
        for(int i=a;i<len;++i){
            if(!(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')){
                b=i-1;
                break;
            }
        }
        for(int i=len-1;i>=0;--i){
            if((str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')){
                c=i;
                break;
            }
        }
        for(int i=c;i>=0;--i){
            if(!(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')){
                d=i+1;
                break;
            }
        }
        if(a==d&&b==c||(d==0&&c==len-1)) cout<<str<<'\n';
        else{
            //printf("%d %d %d %d\n",a,b,c,d);
            cout<<str.substr(0,a)<<str.substr(d,c-d+1)<<str.substr(b+1,d-b-1)<<str.substr(a,b-a+1)<<str.substr(c+1,len-1-c)<<'\n';
        }
    }
}