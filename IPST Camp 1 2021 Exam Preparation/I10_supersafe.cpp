//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
float t_pre,v_pre,t_cur,v_cur,k,V,T,n;
int main(){
    scanf("%f %f",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%f %f",&t_cur,&v_cur);
        if(v_cur<=v_pre||i==0){
            printf("0\n");
        }
        else{
            T=(k-((t_cur-t_pre)*v_pre))/v_pre;
            V=floor(k/T);
            //printf("%lf %lf\n",T,V);
            if(v_cur>V&&T>0) printf("%.0f\n",v_cur-V);
            else printf("0\n");
        }
        t_pre=t_cur;
        v_pre=v_cur;
    }
}