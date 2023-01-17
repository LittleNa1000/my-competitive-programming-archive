//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
double a[20],b[20],a_sum,a_cnt,b_sum,b_cnt,ans=1e9,sum;
int n;
void f(int h){
    if(h==n){
        //printf("%.0lf %.0lf %.0lf %.0lf\n",a_sum,a_cnt,b_sum,b_cnt);
        sum=(a_sum*(100-a_cnt)/100)+(b_sum*(100-b_cnt)/100);
        if(ans>sum){
            ans=sum;
            //printf("%.0f %.0f %.0f %.0f\n",a_sum,a_cnt,b_sum,b_cnt);
        }
        return ;
    }
    a_sum+=a[h];
    a_cnt++;
    f(h+1);
    a_sum-=a[h];
    a_cnt--;
    b_sum+=b[h];
    b_cnt++;
    f(h+1);
    b_sum-=b[h];
    b_cnt--;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lf",&a[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%lf",&b[i]);
    }
    f(0);
    printf("%.2lf",ans);
}