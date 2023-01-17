//      11/2/2564
#include<bits/stdc++.h>
#include"crectlib.h"
using namespace std;
typedef pair<int,int> ii;
int n,i,j,max_i,max_j,cnt_i[10005],cnt_j[10005],hj1=INT_MAX,hi,hj2,vi1=INT_MAX,vj,vi2;
vector<ii> rod;
void f(int i1,int i2,int j1,int j2){
    if(i1==i2&&j1==j2){
        //printf("(%d,%d)\n",i1,j1);
        rod.push_back({i1,j1});
        ++cnt_i[i1];
        ++cnt_j[j1];
        if(max_i<cnt_i[i1]){
            max_i=cnt_i[i1];
            hi=i1;
        }
        if(max_j<cnt_j[j1]){
            max_j=cnt_j[j1];
            vj=j1;
        }
        return ;
    }
    int i_m=(i1+i2)/2,j_m=(j1+j2)/2;
    if(rect(i1,i_m,j1,j_m)){
        f(i1,i_m,j1,j_m);
    }
    if(i1!=i2){
        if(rect(i_m+1,i2,j1,j_m)){
            f(i_m+1,i2,j1,j_m);
        }
    }
    if(j1!=j2){
        if(rect(i1,i_m,j_m+1,j2)){
            f(i1,i_m,j_m+1,j2);
        }
    }
    if(i1!=i2&&j1!=j2){
        if(rect(i_m+1,i2,j_m+1,j2)){
            f(i_m+1,i2,j_m+1,j2);
        }
    }
}
int main(){
    n=gridsize();
    f(1,n,1,n);
    for(int x=0;x<rod.size();++x){
        int i=rod[x].first;
        int j=rod[x].second;
        if(i==hi){
            hj1=min(hj1,j);
            hj2=max(hj2,j);
        }
        if(j==vj){
            vi1=min(vi1,i);
            vi2=max(vi2,i);
        }
    }
    report(hi,hj1,hi,hj2,vi1,vj,vi2,vj);
}