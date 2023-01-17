#include<bits/stdc++.h>
using namespace std;
int n,a,mn=INT_MAX;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","a",stdout);
    //scanf("%d",&n);
    cin>>n;
    for(int i=0;i<n;++i){
        //scanf("%d",&a);
        cin>>a;
        mn=min(mn,a);
    }
    //printf("%d",mn);
    cout<<mn;
}