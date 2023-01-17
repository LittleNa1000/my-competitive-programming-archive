//                      20/10/2563 wrong answer
#include<bits/stdc++.h>
using namespace std;
int n,k,sm,sf;
int m[1001],f[1001];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d %d",&m[i],&f[i]);
    }
    for(int i=0;i<(2*k)+1;++i){
        sm+=m[i];
        sf+=f[i];
    }
    if(sm!=sf){
        printf("NO");
        return 0;
    }
    for(int i=(2*k)+1;i<n;++i){
        sm+=m[i]-m[i-(2*k)-1];
        sf+=f[i]-f[i-(2*k)-1];
        if(sm!=sf){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}