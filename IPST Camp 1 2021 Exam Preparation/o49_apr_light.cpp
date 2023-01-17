//                      16/1/2564
#include<bits/stdc++.h>
using namespace std;
//int bt[30000000];
int d[100005],lhs[100005],rhs[100005];
int z,n,val,sum,cnt;
void ins(int idx){
    if(val<bt[idx]){
        if(bt[(idx*2)+1]==0){
            bt[(idx*2)+1]=val;
        }
        else return ins((idx*2)+1);
    }
    else{
        if(bt[(idx*2)+2]==0){
            bt[(idx*2)+2]=val;
        }
        else return ins((idx*2)+2);
    }
}
void fs(int l,int r,int idx){
    if(bt[(idx*2)+1]==0){
        if(cnt%2){
            //printf("(%d,%d)\n",l,bt[idx]);
            sum+=(bt[idx]-l+1);
        }
        ++cnt;
    }
    else{
        fs(l,bt[idx],(idx*2)+1);
    }
    if(bt[(idx*2)+2]==0){
        if(cnt%2){
            //printf("(%d,%d)\n",bt[idx]+1,r);
            sum+=(r-bt[idx]);
        }
        ++cnt;
    }
    else{
        fs(bt[idx]+1,r,(idx*2)+2);
    }
}
int main(){
    scanf("%d%d",&z,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&val);
        if(i==0){
            d[0]=val;
            printf("%d\n",val);
        }
        else{
            sum=0;
            cnt=1;
            ins(0); //insert and find sum
            fs(1,z,0);
            printf("%d\n",sum);
        }
    }
}