/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include<bits/stdc++.h>
using namespace std;
string str;
int arr[10012];
int f(int l,int r){
//int arr[10012]; //or global
    int cst=0,mn=100,mnidx=0;
    int in_b=0;
    if(l>r) return 0;
    //if(l==1&&r==2) return 0;
    //printf("(%d,%d) \n",l,r);
    /*if(r-l==1){
        if(str[l]=='[')l++;
        if(str[r]==']')r--;
    }*/
    /*if(str[l]=='['&&str[r]==']'){
        l++;
        r--;
    }*/
    int x=0;
    //or chk str [ ] 1st
    typedef pair<int,int> pii;
    stack<int> st;

    for(int i=l;i<=r;++i){
        if(str[i]=='[') st.push(i);
        if(str[i]==']'){
            if(st.top()==l&&i==r){
                l++;
                r--;
            }
            else st.pop();
        }
        //if(str[i]=='[') x++;
        //arr[i]=x;
        //if(str[i]==']') x++;
    }
    /*if(arr[l]==arr[r]&&str[l]=='['&&str[r]==']'){
        l++;
        r--;
        //printf("YES");
    }*/
    if(l==r) return 20;
    for(int i=l;i<=r;++i){
        if(str[i]=='[') in_b++;
        if(str[i]==']') in_b--;

        if(str[i]>='1'&&str[i]<='3'&&in_b<=0){
            //printf("Y");
            if(mn>=str[i]-'0'){ //or >
                mn=str[i]-'0';
                mnidx=i;
            }
        }

    }
    int m=mnidx;
    //printf("%d %d\n",mn,m); //return 0;
    cst+=f(l,m-1)+f(m+1,r);
    if(mn==1) cst+=cst*4/100;
    else if(mn==2) cst+=cst*8/100;
    else if(mn==3) cst+=cst*16/100;
    return cst;
}
int main(){
    cin>>str;
    /*for(int i=0;i<str.length();++i){
        if(str[i]>='1'&&str[i]<='3'){
            pq.push({str[i]-'0',i});
        }
    }*/
    printf("%d",f(0,str.length()-1));
}
