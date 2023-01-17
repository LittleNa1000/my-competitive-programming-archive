//                      15/1/2564
#include<bits/stdc++.h>
using namespace std;
//int ex[]={1,3,7,17,41,99,239,577,1393,3363,8119,19601,47321,114243,275807,665857,1607521,3880899,9369319,22619537,54608393,33070892,21984746,77040384,77300083,34109688,46754028,28852313,5693223,40238759,86170741,15049379,17504068,50057515,18853667,87764849,95617934,81469855,61026782,5992557,73011896,53250918,80748301,17216658,16416186,50049030,17748815,85546660,90076704,68169206};
unsigned long long int m[70][2][2];
unsigned long long int n,tem,ans,idx2,tc,x,c,d,ans1=7,ans0=3;
void mul(int idx1,bool is_m,int a,int b){
    if(is_m){
        idx2=a;
        m[idx1+1][0][0]=((m[idx1][0][0]*m[idx2][0][0]) + (m[idx1][0][1]*m[idx2][1][0])) % 98765431;
        m[idx1+1][0][1]=((m[idx1][0][0]*m[idx2][0][1]) + (m[idx1][0][1]*m[idx2][1][1])) % 98765431;
        m[idx1+1][1][0]=((m[idx1][1][0]*m[idx2][0][0]) + (m[idx1][1][1]*m[idx2][1][0])) % 98765431;
        m[idx1+1][1][1]=((m[idx1][1][0]*m[idx2][0][1]) + (m[idx1][1][1]*m[idx2][1][1])) % 98765431;
    }
    else{
        c=((m[idx1][0][0]*a)+(m[idx1][0][1]*b))%98765431;
        d=((m[idx1][1][0]*a)+(m[idx1][1][1]*b))%98765431;
        ans1=c;
        ans0=d;
        //printf("(#%d %llu %llu %llu %llu)\n",idx1,m[idx1][0][0],m[idx1][0][1],m[idx1][1][0],m[idx1][1][1]); //printf("%llu %llu\n",c,d);
    }
}
int main(){
    m[0][0][0]=2; m[0][0][1]=1;
    m[0][1][0]=1; m[0][1][1]=0;
    for(int i=0;i<=64;++i){
        mul(i,1,i,-1);
    }
    /*for(int i=0;i<20;++i) printf("%d, ",ex[i]); printf("\n");
    for(int i=0;i<=20;++i){
        mul(i,1,i,-1);
        printf("--\n%llu %llu\n%llu %llu\n--\n",m[i+1][0][0],m[i+1][0][1],m[i+1][1][0],m[i+1][1][1]);
    }
    for(int i=0;i<=20;++i){
        mul(i,0,7,3);
    }*/
    scanf("%llu",&tc);
    for(int t=0;t<tc;++t){
        scanf("%llu",&x);
        if(x==1) printf("3\n");
        else if(x==2) printf("7\n");
        else{
            ans1=7; 
            ans0=3;
            x-=2;
            for(int i=0;x>0;++i){
                if(x%2){
                    mul(i,0,ans1,ans0);
                }
                x/=2;
            }
            printf("%llu\n",ans1);
        }
    }
    
}