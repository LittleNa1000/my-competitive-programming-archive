//				9/8/2563
#include<bits/stdc++.h>
using namespace std;
int mul=1,ans,n,m,temp;
vector<int> v;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;++i){
		ans+=(long long int)v[i]*mul%1000000007;
		ans%=1000000007;
		if((i+1)%m==0&&i+1+m<=n){
			++mul;
		}
	}
	printf("%d",ans);
}
