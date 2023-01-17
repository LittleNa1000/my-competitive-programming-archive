//                8/8/63 maybe segment tree
#include<bits/stdc++.h>
using namespace std;
set<int> s; // maybe vector
set<int>::iterator lb,lb1;
int n,m,sw,q,temp,temp1,k,l,r;
bool a,b;
int main(){
    scanf("%d %d %d %d",&n,&m,&sw,&q);
    for(int i=0;i<m;++i){
        scanf("%d",&temp);
        s.insert(temp);
    }
    for(int i=0;i<sw;++i){
        scanf("%d %d",&temp,&temp1);
        lb=s.lower_bound(temp);
        lb1=s.lower_bound(temp1);
        a=0;   b=0;
        if(lb!=s.end()&&*lb==temp) a=1; 
        if(lb1!=s.end()&&*lb1==temp1) b=1; 
        if(a>b){
            s.erase(lb);
            s.insert(temp1);
        }
        else if(b>a){
            s.erase(lb1);
            s.insert(temp);
        }
    }
    //for(lb=s.begin();lb!=s.end();lb++) printf("s%d\n",*lb);
    for(int i=0;i<q;++i){
        scanf("%d %d",&l,&r);
        lb=s.upper_bound(r);
        lb1=s.lower_bound(l);
        if(lb1==s.end()) printf("0 ");
        else printf("%d ",distance(lb1,lb));
    }
}
