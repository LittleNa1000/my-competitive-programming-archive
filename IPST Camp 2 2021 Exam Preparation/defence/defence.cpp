//                  19/5/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int TESTCASE_NO = 6;
struct P{
    int x1,x2,y1,y2;
};
int n,m,k,tem,sum,sumodd,sumeven;
vector<int> v;
vector<ii> even,odd;
bool f(vector<ii> s,int target){
    int x;
    for(int i=1;i<=(1<<s.size())-1;++i){
        x=0;
        for(int j=0;j<s.size();++j){
            if(i&(1<<j)) x+=s[j].first;
        }
        if(x==target){
            printf("In f, i = %d\n",i);
            printf("s: ");
            for(int j=0;j<s.size();++j) printf("#%d ",s[j].second); printf("\n");
            return 1;
        }
    }
    return 0;
}
int main(){
    if(TESTCASE_NO==3){
        freopen("03.out","w",stdout);
        freopen("03.in","r",stdin);
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<k;++i){
            scanf("%d",&tem);
            printf("0 1 %d %d\n",sum,sum+tem);
            sum+=tem;
        }
    }
    else if(TESTCASE_NO==4){
        P arr[100000];
        freopen("04.out","w",stdout);
        for(int i=1;i<=49999;++i){
            int j=99999-i;
            arr[i-1]={0,i,i,i+1};
            arr[j-1]={i,99999,i,i+1};
        }
        arr[99998]={0,99999,0,1};
        for(int i=0;i<99999;++i){
            printf("%d %d %d %d\n",arr[i].x1,arr[i].x2,arr[i].y1,arr[i].y2);
        }
    }
    else if(TESTCASE_NO==5){
        freopen("05.out","w",stdout);
        int a=9973,b=293,c=99991,d=311;
        for(int i=0;i<d;++i){
            for(int j=0;j<b;++j){
                printf("%d %d %d %d\n",j*a,(j+1)*a,i*c,(i+1)*c);
            }
        }
    }
    else if(TESTCASE_NO==6){
        freopen("06.in","r",stdin);
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<k;++i){
            scanf("%d",&tem);
            //v.push_back({tem,i});
            if(tem%2){
                odd.push_back({tem,i});
            } 
            else even.push_back({tem,i});
        }
        // for(int i=1;i<=(1<<10)-1;++i){
        vector<ii> sss = odd;
        //     sumeven=0;
        //     for(int j=0;j<10;++j){
        //         if(i&(1<<j)){
        //             sumeven+=even[j].first;
        //         }
        //         else{
        //             sss.push_back(even[j]);
        //         }
        //     }
        //     //printf("Passing target = %d, i = %d, size = %d\n",1000000000-(sumeven/2),i,sss.size());

        // }
        static P arr[20];
        vector<ii> sss_2,slc_even;
        int cnt=0,cnt2=0;
        for(int i=0;i<10;++i){
            if(234&(1<<i)){
                slc_even.push_back(even[i]);
            }
            else sss.push_back(even[i]);
        }
        printf("\nSelected Even: \n");
        for(int i=0;i<slc_even.size();++i){
            printf("#%d ",slc_even[i].second);
            arr[slc_even[i].second]={0,2,cnt,cnt+(slc_even[i].first/2)};
            cnt+=(slc_even[i].first/2);
        }
        cnt2=cnt;
        printf("\nSSS 1: \n");
        for(int i=0;i<sss.size();++i){
            if(11178&(1<<i)){
                printf("#%d ",sss[i].second);
                arr[sss[i].second]={0,1,cnt,cnt+(sss[i].first)};
                cnt+=(sss[i].first);
            }
            else sss_2.push_back(sss[i]);
        }
        printf("\nSSS 2: \n");
        for(int i=0;i<sss_2.size();++i){
            printf("#%d ",sss_2[i].second);
            arr[sss_2[i].second]={1,2,cnt2,cnt2+(sss_2[i].first)};
            cnt2+=(sss_2[i].first);
        }
        freopen("06.out","w",stdout);
        for(int i=0;i<20;++i){
            printf("%d %d %d %d\n",arr[i].x1,arr[i].x2,arr[i].y1,arr[i].y2);
        }
    }
}