//                      23/10/2563
#include<bits/stdc++.h>
using namespace std;
unsigned long long int x=2,n;
int q;
vector<unsigned long long int> v={3,7,31,127,8191,131071,524287,2147483647,2305843009213693951};
bool is_prime(unsigned long long int k){
    unsigned long long int l=sqrt(k);
    for(int i=3;i<=l;i+=2){
        if(k%i==0) return 0;
    }
    return 1;
}
int main(){
    /*for(int i=2;i<=63;++i){
        x*=2;
        if(is_prime(x-1)){
            v.push_back(x-1);
        }
    }
    for(int i=0;i<v.size();++i) printf("%llu ",v[i]);
    printf("\n");*/
    scanf("%d",&q);
    while(q--){
        scanf("%llu",&n);
        if(binary_search(v.begin(),v.end(),n)) printf("YES\n");
        else printf("NO\n");
    }
}