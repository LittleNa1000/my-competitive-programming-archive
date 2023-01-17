//				20/6/2563
#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> v;
void f(int sum){
	if(sum==n){
		ans++;
		//for(int i=1;i<v.size();++i) printf("%d ",v[i]);
		//printf("\n"); 
		return ;
	}
	if(v[v.size()-1]*2>n) return ;
	for(int i=v[v.size()-1];i<=n;++i){
		if(sum+i<=n){
			v.push_back(i);
			f(sum+i);
			v.pop_back();
		}
	}
}
main(){
	scanf("%d",&n);
	v.push_back(1); //if(n==1)
	f(0);
	if(n==1) printf("1");
	else printf("%d",ans);
}
