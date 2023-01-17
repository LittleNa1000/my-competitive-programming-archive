//                  24/10/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> pr={4};
int a,b,l,r;
bool not_pr[1001];
int main(){
    for(int i=3;i<=997;i+=2){
        if(!not_pr[i]){
            pr.push_back(i*i);
            for(int j=2*i;j<=997;j+=i){
                not_pr[j]=1;
            }
        }
    }
    //for(int i=0;i<pr.size();++i) printf("%d ",pr[i]); printf("\n");
    scanf("%d %d",&a,&b);
    l=lower_bound(pr.begin(),pr.end(),a)-pr.begin();
    r=upper_bound(pr.begin(),pr.end(),b)-1-pr.begin();
    if(l>r) printf("-1");
    else for(int i=l;i<=r;++i) printf("%d ",pr[i]);
}