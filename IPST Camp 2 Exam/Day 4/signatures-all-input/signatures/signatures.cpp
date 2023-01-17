/*
CURRENT MAX
1   9
2   4475
3   30
4   1228
5   4476
6   104
7   858
8   4475
9   139
10  4476
*/
#include<bits/stdc++.h>
using namespace std;
#define TC_NO 6
#define slen 105
#define tries 499500
string str,tmp;
int k,n;
set<int> s2;
int strtoint(bool b){
    int res=0;
    if(!b){
        for(int i=k-1,j=0;i>=0;--i,++j){
            res+=((1<<j)*(tmp[i]-'0'));
        }
        //printf("res 0 = %d\n",res);
    }
    else{
        for(int i=k-1,j=0;i>=0;--i,++j){
            res+=((1<<j)*(str[i]-'0'));
        }
    }
    //printf("res = %d\n",res);
    return res;
}
void getrandstr(){
    for(int i=0;i<slen;++i){
        str[i]=(rand()%2)+'0';
    }
    
}
bool chk(){
    int x=strtoint(1);
    set<int> s=s2;
    for(int i=k;i<slen;++i){
        //printf("[%d]",x);
        if(s.find(x)!=s.end()) return 0;
        s.insert(x);
        if(x>=(1<<(k-1))) x-=1<<(k-1);
        x=x<<1;
        if(str[i]-'0') x+=1;
    }
    if(s.find(x)!=s.end()) return 0;
    return 1;
}
int main(){
    if(TC_NO==1) freopen("1.in","r",stdin);
    else if(TC_NO==2) freopen("2.in","r",stdin);
    else if(TC_NO==3) freopen("3.in","r",stdin);
    else if(TC_NO==4) freopen("4.in","r",stdin);
    else if(TC_NO==5) freopen("5.in","r",stdin);
    else if(TC_NO==6) freopen("6.in","r",stdin);
    else if(TC_NO==7) freopen("7.in","r",stdin);
    else if(TC_NO==8) freopen("8.in","r",stdin);
    else if(TC_NO==9) freopen("9.in","r",stdin);
    else if(TC_NO==10) freopen("10.in","r",stdin);

    scanf("%d %d",&k,&n);
    for(int i=0;i<n;++i){
        cin>>tmp;
        s2.insert(strtoint(0));
    }
    str.resize(slen);
    srand(time(NULL));
    for(int i=1;i<=tries;++i){
        getrandstr();
        if(i%100==0)printf("#%dth String\n",i);
        if(chk()){
            cout<<"\nSol found at #"<<i<<'\n';
            if(TC_NO==1) freopen("1.out","w",stdout);
            else if(TC_NO==2) freopen("2.out","w",stdout);
            else if(TC_NO==3) freopen("3.out","w",stdout);
            else if(TC_NO==4) freopen("4.out","w",stdout);
            else if(TC_NO==5) freopen("5.out","w",stdout);
            else if(TC_NO==6) freopen("6.out","w",stdout);
            else if(TC_NO==7) freopen("7.out","w",stdout);
            else if(TC_NO==8) freopen("8.out","w",stdout);
            else if(TC_NO==9) freopen("9.out","w",stdout);
            else if(TC_NO==10) freopen("10.out","w",stdout);
            printf("%d\n",TC_NO);
            cout<<str<<'\n';
            return 0;
        }
        //printf("\n");
    }
    
    // freopen("1.out","w",stdout);
    // printf("%d\n",TC_NO);
    // cout<<"100010111";
}