/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include<bits/stdc++.h>
using namespace std;
int mxstrlen;
int n,k,len;
int idx[12];
string str[12],tem;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){

        cin>>str[i];
        len=str[i].length();
        mxstrlen=max(mxstrlen,len);
    }
    /*for(int i=0;i<n;++i){
        tem=str[i];
        while(str[i].length()<mxstrlen) str[i]+=tem;
        cout<<str[i]<<'\n';
    }*/
    bool dty;
    for(int i=1;;++i){
        dty=1;
        for(int j=0;j<n;++j){
            len=str[j].length();
            //printf("str[%d][%d]=%c\n",j,i%len,str[j][i%len]);
            if(str[j][i%len]!=k+'0'){
                dty=0;
                break;
            }
        }
        if(dty){
            printf("%d",i);
            return 0;
        }

    }
    //printf("%d",mxstrlen);
}
