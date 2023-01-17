//                      24/10/2563 // pair[], qsum in main()
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,x,y;
vector<pii> v;
double ans;
bool sbx(const pii &a,const pii &b){
    return a.first>b.first;
}
void count_inver(int l,int m,int r){
    //printf("(%d,%d,%d)\n",l,m,r);
    vector<pii> tem;
    vector<int> qsum;
    for(int i=m;i>=l;--i){
        if(i==m) qsum.push_back(v[i].first);
        else qsum.push_back(qsum[qsum.size()-1]+v[i].first);
    }
    //for(int i=0;i<qsum.size();++i) printf("%d ",qsum[i]); printf("\n");
    int i=l,j=m+1;
    while(i<=m&&j<=r){
        if(v[i].second>v[j].second) tem.push_back(v[i++]);
        else{
            //printf("%.0lf->%.0lf\n",ans,ans+qsum[m-i]+(v[j].first*(m-i+1)));
            ans+=qsum[m-i]+(v[j].first*(m-i+1));
            tem.push_back(v[j++]);
        }
    }
    while(i<=m) tem.push_back(v[i++]);
    while(j<=r) tem.push_back(v[j++]);
    for(int a=l;a<=r;++a){
        v[a]=tem[a-l];
    }
}
void divide(int l,int r){
    if(l>=r) return ;
    //printf("(%d,%d)\n",l,r);
    int m=(l+r)/2;
    divide(l,m);
    divide(m+1,r);
    count_inver(l,m,r);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),sbx);
    //for(int i=0;i<n;++i) printf("(%d,%d) ",v[i].first,v[i].second); printf("\n");
    divide(0,n-1);
    printf("%.0lf",ans);
}