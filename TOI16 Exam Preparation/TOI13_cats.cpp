//                      17/10/2563 planB vector
#include<bits/stdc++.h>
using namespace std;
int n,mid,l,r,ans=INT_MAX,m,pre;
int meow[2000002];
set<int> s;
set<int>::iterator it;
bool b;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&meow[i]);
        s.insert(meow[i]);
    }
    pre=-1; b=1;
        for(int i=0;i<n;++i){
                if(pre==-1) pre=meow[i];
                else if(meow[i]!=pre){
                    b=0;
                    break;
                }
                else{
                    pre=-1;
                }
        }
    if(b){
        printf("0");
        return 0;
    }
    r=n/2;
    while(l<=r){
        m=(l+r)/2;
        it=s.begin();
        advance(it,m);
        mid=*it;
        //printf("*%d* ",mid);
        pre=-1; b=1;
        for(int i=0;i<n;++i){
            if(meow[i]>mid){
                if(pre==-1) pre=meow[i];
                else if(meow[i]!=pre){
                    b=0;
                    break;
                }
                else{
                    pre=-1;
                }
            }
        }
        if(b){
            ans=min(ans,mid);
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    printf("%d",ans);
}