//                      4/1/2564
//                      FIRST CODE OF THE YEAR 2021
#include<bits/stdc++.h>
using namespace std;
int n,m,k,mn,idx;
int sp[1012],pr[1012];
//vector<int> pr;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&sp[i]);
        //pr.push_back(INT_MAX);
        pr[i]=INT_MAX;
    }
    for(int i=0;i<m;++i){
        scanf("%d",&idx);
        --idx;
        if(pr[idx]==INT_MAX){
            while(k<sp[idx]){
                mn=min_element(pr,pr+n)-pr;
                pr[mn]=INT_MAX;
                k+=sp[mn];
            }
            k-=sp[idx];
        }
        pr[idx]=i;
        //printf("%d\n",k);
    }
    printf("%d",k);
}