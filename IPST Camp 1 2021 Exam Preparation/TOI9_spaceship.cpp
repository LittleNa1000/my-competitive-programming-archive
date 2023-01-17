//                      5/1/2564 //or long long ans
#include<bits/stdc++.h>
using namespace std;
int n,k,xx,yy,zz,ans=2e9,dis,xi,yi,zi,A,B,C,i;
int x[15],y[15],z[15],a[15],b[15],c[15];
vector<int> v;
int main(){
    scanf("%d%d%d%d%d",&k,&xx,&yy,&zz,&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d%d%d",&x[i],&y[i],&z[i],&a[i],&b[i],&c[i]);
        v.push_back(i);
    }
    do{
        dis=0;
        A=0; B=0; C=0;
        xi=xx; yi=yy; zi=zz;
        for(int m=0;m<n;++m){
            i=v[m];
            dis+=(xi-x[i])*(xi-x[i])+(yi-y[i])*(yi-y[i])+(zi-z[i])*(zi-z[i]);
            xi=x[i];
            yi=y[i];
            zi=z[i];
            A+=a[i];
            B+=b[i];
            C+=c[i];
            if(A>=k&&B>=k&&C>=k){
                ans=min(ans,dis);
                break;
            }
        }
        //for(int i=0;i<v.size();++i) printf("%d ",v[i]); printf("\n");
    }while(next_permutation(v.begin(),v.end()));
    printf("%d",ans);
}