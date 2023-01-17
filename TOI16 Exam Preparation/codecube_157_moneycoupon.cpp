//                     25/10/2563
#include<bits/stdc++.h>
using namespace std;
int n,val;
char sym;
bool have_x0;
long long int sum,mul=1,subtract,ans;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>sym>>val;
        if(sym=='+'){
            sum+=val;
        }
        else if(sym=='-'){
            subtract+=val;
        }
        else{
            if(val==0) have_x0=1;
            else{
                mul*=val;
            }
        }
    }
    ans=sum*mul;
    if(!have_x0) ans-=subtract;
    printf("%lld",ans);
    //printf("\n(%lld,%lld,%lld)",sum,mul,subtract);
}