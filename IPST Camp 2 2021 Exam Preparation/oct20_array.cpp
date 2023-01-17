//                  6/5/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int l,r,k;
};
int n,q,T,a,b,k,L,R;
double sum;
vector<N> v;
int main(){
    scanf("%d %d",&n,&q);
    while(q--){
        scanf("%d",&T);
        if(!T){
            scanf("%d %d %d",&a,&b,&k);
            --b;
            v.push_back({a,b,k});
        }
        else{
            scanf("%d %d",&L,&R);
            --R;
            sum=0;
            for(int i=0;i<v.size();++i){
                if(R<v[i].l||v[i].r<L){

                }
                else{
                    sum+=((double)(min(v[i].r,R)-max(v[i].l,L))*(double)v[i].k);
                    sum+=v[i].k;
                }
            }
            printf("%.0lf\n",sum);
        }
    }
    // sum=2000000000000000;
    // printf("%lf\n",sum);
}