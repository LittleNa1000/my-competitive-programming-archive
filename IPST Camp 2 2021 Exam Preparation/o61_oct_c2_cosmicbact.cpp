//              25/4/2564
#include<bits/stdc++.h>
using namespace std;
// num,x,t,st,en
struct N{
    long long num,x,t,st,en;
};
vector<N> bact;
bool del[100005],right_win;
long long n,L,i,j,x,y,d;
long long ans[100005];
bool com(const N &a,const N &b){
    return a.x<b.x;
}
void compare(long long a,long long b,bool left){
    if(a>b){
        if(left){
            //left eat right
            del[bact[j].num]=1;
            bact[i].en=bact[j].en;
        }
        else{
            //right eat left
            del[bact[i].num]=1;
            bact[j].st=bact[i].st;
            right_win=1;
        }
    }
    else{
        unsigned long long mid=(a+b)/2;
        right_win=1;
        if((b-a)%2){
            // no cont.
            bact[i].en=mid;
            bact[j].st=mid+1;
        }
        else{
            //cont.
            if(bact[i].num<bact[j].num){
                bact[i].en=mid;
                bact[j].st=mid+1;
            }
            else{
                bact[i].en=mid-1;
                bact[j].st=mid;
            }
        }
    }
}
int main(){
    scanf("%lld %lld",&n,&L);
    for(long long k=0;k<n;++k){
        scanf("%lld %lld",&x,&y);
        bact.push_back({k+1,x,y+k,x,x});
    }
    sort(bact.begin(),bact.end(),com);
    bact[0].st=0;
    bact[n-1].en=L;
    i=0,j=1;
    while(i<n&&j<n){
        right_win=0;
        d=abs(bact[i].t-bact[j].t);
        if(bact[i].t<bact[j].t){
            compare(bact[i].x+d,bact[j].x,1);
        }
        else{
            compare(bact[i].x,bact[j].x-d,0);
        }
        if(right_win){
            ++i;
            while(del[bact[i].num]&&i<n){
                ++i;
                if(i==n) break;
            }
            while((i>=j||del[bact[j].num])&&j<n){
                ++j;
                if(j==n) break;
            }
        }
        else ++j;
    }
    // for(long long k=0;k<n;++k){
    //     printf("%lld %lld %lld %lld %lld %d\n",bact[k].num,bact[k].x,bact[k].t,bact[k].st,bact[k].en,del[k+1]);
    // }
    for(long long k=0;k<n;++k){
        ans[bact[k].num]=bact[k].en-bact[k].st+1;
    }
    for(int k=0;k<n;++k){
        if(del[k+1]) printf("0\n");
        else printf("%lld\n",ans[k+1]);
    }
}