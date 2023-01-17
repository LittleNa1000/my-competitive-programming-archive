//                      7/1/2564
#include<bits/stdc++.h>
using namespace std;
long long int n,tem;
vector<int> v={1,2,3,4,5,6,7,8,9};
int num[10];
void add(){
    v.push_back((num[0]*1e7)+(num[1]*1e6)+(num[2]*1e5)+(num[3]*1e4)+(num[4]*1e3)+(num[5]*1e2)+(num[6]*1e1)+(num[7]));
    //for(int i=0;i<=7;++i) printf("[%d] ",num[i]); printf("\n");
}
void f(int depth,int last){
    if(depth==8){
        add();
        return ;
    }
    for(int i=last+1;i<=9;++i){
        num[depth]=i;
        f(depth+1,i);
    }
}
int main(){
    //num[6]=1;
    for(int i=6;i>=0;--i){
        f(i,0);
    }
    v.push_back(123456789);
    //for(int i=0;i<v.size();++i) printf("%d\n",v[i]);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tem);
        if(tem>v.size()) printf("-1\n");
        else printf("%lld\n",v[tem-1]);
    }
}