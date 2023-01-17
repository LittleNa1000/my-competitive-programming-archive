//				25/3/2563
#include<bits/stdc++.h>
using namespace std;
vector<long long> prime;
bool is_prime(int in){
	for(int i=0;prime[i]*prime[i]<=in;i++){
		if(in%prime[i]==0) return 0;
	}
	return 1;
}
main(){
	prime.push_back(2);
	prime.push_back(3);
	int n;
	scanf("%d",&n);
	for(int i=2;i<n;i++){
		for(int j=prime[prime.size()-1]+2;;j+=2){
			if(is_prime(j)){
				prime.push_back(j);
				break;
			}
		}
	}
	if(n==1) printf("2");
	else printf("%lld",prime[prime.size()-1]);
}
