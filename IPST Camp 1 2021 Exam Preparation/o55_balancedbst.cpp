#include<bits/stdc++.h>
using namespace std;
int n,q,tem;
int a[200012];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    while(q--){
        scanf("%d",&tem);
        if(binary_search(a,a+n,tem)) printf("y\n");
        else printf("n\n");
    }
}