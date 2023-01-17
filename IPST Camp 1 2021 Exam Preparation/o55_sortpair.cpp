//				9/1/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
bool com(const ii &a,const ii &b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int n,x,y;
ii a[100012];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        a[i]={x,y};
    }
    sort(a,a+n,com);
    for(int i=0;i<n;++i){
        printf("%d %d\n",a[i].first,a[i].second);
    }
}
