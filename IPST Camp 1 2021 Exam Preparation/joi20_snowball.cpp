//      14/2/2564
#include<bits/stdc++.h>
using namespace std;
int n,q;
long long int x[200005],w[200005],d;
map<long long int,bool> snow;
int main(){
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;++i){
        scanf("%lld",&x[i]);
    }
    while(q--){
        scanf("%lld",&d);
        if(d>0){
            for(int i=n-1;i>=0;--i){
                for(int j=0;j<d;++j){
                	//printf("i=%d x[i]=%lld->%lld snow=%d\n",i,x[i],x[i]+1,snow[x[i]]);
                	++x[i];
                    if(!snow[x[i]]){
                        snow[x[i]]=1;
                        ++w[i];
                    }
                    
                }
            }
        }
        else{
            d=abs(d);
            for(int i=0;i<n;++i){
                for(int j=0;j<d;++j){
                	//printf("i=%d x[i]=%lld->%lld snow=%d\n",i,x[i],x[i]-1,snow[x[i]]);
                    if(!snow[x[i]]){
                        snow[x[i]]=1;
                        ++w[i];
                    }
					--x[i];
					
                    
                }
            }
        }
        //for(int i=0;i<n;++i) printf("%d %d\n",x[i],w[i]); printf("\n");
    }
    for(int i=0;i<n;++i) printf("%lld\n",w[i]);
}
